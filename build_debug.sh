#! /bin/bash

rm -R bin

mkdir bin

cd bin

conan install ../src

cmake -DCMAKE_BUILD_TYPE=Debug ../src

make