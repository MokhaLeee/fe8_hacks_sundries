#!/bin/sh
cd `dirname $0`

BASE_DIR=$(dirname $(readlink -f $0))
TOOL_DIR=$BASE_DIR/tools
EA_DIR=$TOOL_DIR/ea
FE8_DIR=$TOOL_DIR/fe8

# Install dependence
sudo apt-get install binutils-arm-none-eabi gcc-arm-none-eabi build-essential \
    cmake re2c ghc cabal-install libghc-vector-dev libghc-juicypixels-dev python3-pip \
    aspnetcore-runtime-6.0 dotnet-sdk-6.0 dotnet-runtime-6.0 pkg-config libpng*

pip install pyelftools PyInstaller tmx six

# cabal update

# Install devkitPro
TEMP_DIR=$(mktemp -d) && cd $TEMP_DIR
wget https://apt.devkitpro.org/install-devkitpro-pacman
chmod +x ./install-devkitpro-pacman
./install-devkitpro-pacman
rm install-devkitpro-pacman
cd $BASE_DIR && rm -rf $TEMP_DIR

# Update tools' submodules
git submodule update --init --recursive

# Build event-assembler
cd $EA_DIR && sudo ./build.sh

# Build and install agbcc
TEMP_DIR=$(mktemp -d)
git clone git@github.com:pret/agbcc.git $TEMP_DIR
cd $TEMP_DIR
./build.sh
./install.sh $BASE_DIR
./install.sh $FE8_DIR
rm -rf $TEMP_DIR

# build decomp
cp $BASE_DIR/fe8.gba $FE8_DIR/baserom.gba
cd $FE8_DIR && ./build_tools.sh

cd $BASE_DIR
