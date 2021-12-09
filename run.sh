#!/bin/bash

# if ! gx main.gx.go main ; then
#     exit
# fi

if ! gx example/main.gx.go build/main ; then
    exit
fi

echo "#include <cstdlib>" | cat - build/gx.hh > build/temp && mv build/temp build/gx.hh

# if ! g++ main.gx.cc cppfpm.cpp -lfcgi++ -lfcgi -std=c++17 -o hello_world ; then
#     exit
# fi

export CPATH=/gx-web/build:/gx-web/gx-ext:/gx-web/cpp-fpm

if ! g++ build/main.gx.cc cpp-fpm/cppfpm.cpp -lfcgi++ -lfcgi -std=c++17 -o build/example.exe ; then
    exit
fi

pkill example
spawn-fcgi -s /run/fcgi.sock build/example.exe
