#!/bin/bash

BUILD_SCRIPT=build_macos_avx.sh
BUILD_FOLDER=build-macos-avx

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
