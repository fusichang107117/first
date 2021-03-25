#!/bin/sh

rm -rf builds
mkdir builds
cd builds
# Debug, Release, RelWithDebInfo and MinSizeRel
cmake -D CMAKE_BUILD_TYPE=Debug ..
make
make install
make test
#make memcheck
