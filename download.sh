#!/bin/bash
git clone https://github.com/tencent/feathercnn
git clone https://github.com/tencent/ncnn
mv feathercnn feather
cd feather/
git checkout master
cd ../ncnn
git reset --hard d46c5989e1768caf59ad4b1ef2ba620573aa2685
