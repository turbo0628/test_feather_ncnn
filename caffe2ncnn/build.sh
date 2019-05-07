protoc --cpp_out=. ./caffe.proto
g++ -g caffe2ncnn.cpp caffe.pb.cc -I/usr/include `pkg-config --cflags --libs protobuf` -o caffe2ncnn -std=c++11
#cmake -f CMakeList.txt
#make
