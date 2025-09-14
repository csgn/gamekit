#!/bin/sh

set -e

. ./build.sh

TEST_EXE="./${BUILD_DIR}/gamekit-tests/gamekit-tests"

if [ ! -f "$TEST_EXE" ]; then
    echo "Error: Test executable not found: $TEST_EXE"
    exit 1
fi

${TEST_EXE}
