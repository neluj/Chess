#! /bin/bash

#rm -R bin

#mkdir bin

cd bin

#conan install ..

cmake -DCMAKE_BUILD_TYPE=Debug ..

make

#gdb bin/Chess