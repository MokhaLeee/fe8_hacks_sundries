#!/bin/sh
cd `dirname $0`

BASE_DIR=$(pwd)
TOOL_DIR=$BASE_DIR/tools
EA_DIR=$TOOL_DIR/ea
FE8_DIR=$TOOL_DIR/fe8

# Install dependence
sudo apt-get install binutils-arm-none-eabi gcc-arm-none-eabi build-essential \
    cmake re2c ghc cabal-install libghc-vector-dev libghc-juicypixels-dev python3-pip

pip install pyelftools PyInstaller tmx six

# Update tools' submodules
git submodule update --init --recursive

# Build event-assembler
cd $EA_DIR && ./build.sh

# Build and install agbcc
TEMP_DIR=$(mktemp -d)
git clone git@github.com:StanHash/agbcc.git $TEMP_DIR
cd $TEMP_DIR
./build.sh
./install.sh $BASE_DIR
./install.sh $FE8_DIR
rm -fr $TEMP_DIR

# build decomp
cp $BASE_DIR/fe8.gba $FE8_DIR/baserom.gba
cd $FE8_DIR && ./build_tools.sh

cd $BASE_DIR
