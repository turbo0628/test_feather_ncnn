#!/bin/bash

g++ -g tester.cpp test_utils.cpp -I./libncnn/include/ -I./libfeather/include -L./libncnn/lib -lncnn -L./libfeather/lib/ -lfeather -o test_feather_ncnn
