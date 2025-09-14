#!/bin/bash

set -e

BUILD_DIR=cmake-build-debug

if [ ! -d "${BUILD_DIR}" ]; then
    mkdir "${BUILD_DIR}"
fi

# configure
cmake -S . -G "Unix Makefiles" -B ${BUILD_DIR}

# build
cmake --build ${BUILD_DIR} -- -j$(nproc)
