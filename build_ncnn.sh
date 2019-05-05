#!/bin/bash

pushd ncnn
mkdir -p build
pushd build
cmake ..
make -j4
make install
popd
popd
mkdir -p libncnn
pushd libncnn 
mkdir -p include/ncnn
mkdir -p lib
# copy headers
cp ../ncnn/build/install/include/* ./include/ncnn/
# copy lib
cp ../ncnn/build/install/lib/* ./lib/
popd
