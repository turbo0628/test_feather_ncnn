#!/bin/bash

if [ "$1" == "MACOS" ]
then
BUILD_SCRIPT=build_macos_avx.sh
BUILD_FOLDER=build-macos-avx
elif [ "$1" == "ARMLINUX" ]
then
BUILD_SCRIPT=build_armlinux.sh
BUILD_FOLDER=build-linux-aarch64
else
echo "Usage: ./build_feather.sh [ARMLINUX|MACOS]"
exit 0
fi
pushd feather
./build_scripts/$BUILD_SCRIPT
popd
mkdir -p libfeather
pushd libfeather
mkdir -p include/feather
mkdir -p include/booster
mkdir -p lib
cp ../feather/$BUILD_FOLDER/install/feather/include/* ./include/feather/
cp ../feather/$BUILD_FOLDER/install/booster/include/booster/* ./include/booster/
cp ../feather/$BUILD_FOLDER/install/feather/lib/libfeather.a ./lib/
cp ../feather/$BUILD_FOLDER/install/booster/lib/libbooster.a ./lib/
popd
