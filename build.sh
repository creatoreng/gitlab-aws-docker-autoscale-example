#!/bin/bash

mkdir -p build-cache/amd64
if [ ! -f build-cache/amd64/nfactorial.o ]; then
   echo building nfactorial
   (cd lib-external && g++ -c -o ../build-cache/amd64/nfactorial.o nfactorial.cpp)
else
   echo nfactorial is in cache, skipping
fi

mkdir -p build/amd64
echo building hello
g++ -o build/amd64/hello main.cpp build-cache/amd64/nfactorial.o
