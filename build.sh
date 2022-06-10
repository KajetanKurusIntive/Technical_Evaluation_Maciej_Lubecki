#!/bin/sh

PATH_TO_VCPKG=$1

mkdir -p build
cd build
cmake -DPATH_TO_VCPKG_DIRECTORY=${PATH_TO_VCPKG} ..
make -j4