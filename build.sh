#!/bin/bash

set -e

. ./config.sh "$1"

if [ ! -d "${BUILD_DIR}" ]; then
    mkdir -p "${BUILD_DIR}"
fi

# configure
cmake -S . -G "Unix Makefiles" -B ${BUILD_DIR} -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

# build
cmake --build ${BUILD_DIR}
