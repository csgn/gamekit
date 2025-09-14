#!/bin/bash

set -e

BUILD_DIR=cmake-build-debug

if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

cd "$BUILD_DIR"

cmake ..

cmake --build . -- -j$(nproc)

cd ..
