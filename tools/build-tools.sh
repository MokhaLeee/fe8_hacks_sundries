#!/bin/bash

sudo apt-get -y install binutils-arm-none-eabi ctags gcc-arm-none-eabi build-essential cmake re2c ghc cabal-install libghc-vector-dev libghc-juicypixels-dev python3-pip pkg-config libpng* bsdiff moreutils
pip install pyelftools PyInstaller tmx six

cd Tools
git clone https://github.com/MokhaLeee/FE-CLib-Mokha.git Tools/FE-CLib-Mokha
git clone https://github.com/StanHash/EventAssembler.git --recursive Tools/EventAssembler
git clone https://github.com/StanHash/FE-PyTools.git --recursive Tools/FE-PyTools

wget https://apt.devkitpro.org/install-devkitpro-pacman
chmod +x ./install-devkitpro-pacman
sudo ./install-devkitpro-pacman
sudo dkp-pacman -S gba-dev

echo "export DEVKITPRO=/opt/devkitpro" >> ~/.bashrc
echo "export DEVKITARM=\${DEVKITPRO}/devkitARM" >> ~/.bashrc
echo "export DEVKITPPC=\${DEVKITPRO}/devkitPPC" >> ~/.bashrc
echo "export PATH=\${DEVKITPRO}/tools/bin:\$PATH" >> ~/.bashrc
source ~/.bashrc

wget https://dot.net/v1/dotnet-install.sh -O dotnet-install.sh
chmod +x ./dotnet-install.sh
sudo ./dotnet-install.sh --channel 6.0

export DOTNET_ROOT=$HOME/.dotnet
export PATH=$PATH:$DOTNET_ROOT:$DOTNET_ROOT/tools

cd Tools/EventAssembler && ./build.sh && cd ../..
