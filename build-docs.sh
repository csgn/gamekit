#!/bin/bash

set -e

. ./config.sh "$1"

doxygen "${BUILD_DIR?:}"/Doxyfile
