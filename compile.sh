#!/bin/sh

g++ main.cpp libraries/src/common.cpp -Ilibraries/inc -std=c++14 -O3 -o benchmark_io
