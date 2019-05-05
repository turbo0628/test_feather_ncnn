# The utility project to test computing results for FeatherCNN and ncnn

This branch is for MacOS system.
## Usgae
First, clone this project and enter the root directory.
```
git clone https://github.com/turbo0628/test_feather_ncnn
cd test_feather_ncnn
```
And then download ncnn and FeatherCNN as submodules.
```
git submodule update --init --recursive
```
Build respective libraries
```
./build_ncnn.sh
./build_feather.sh
```
And finally build the tester
```
./build_tester.sh
```
If everything's going smooth, you should be able to see a `test_feather_ncnn` executable.
Prepare your ncnn model file. The run command is:
```
./test_feather_ncnn [ncnn_model.param] [ncnn_model.bin] [input_data.txt]
```
