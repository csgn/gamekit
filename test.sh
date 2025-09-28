#!/bin/sh

set -e

. ./build.sh

cd "${TESTS_OUTPUT_DIR}"
ctest

export LD_LIBRARY_PATH="${CSHARP_OUTPUT_DIR}/bin":"${LD_LIBRARY_PATH}"
dotnet test "${CSHARP_TEST_CSPROJ_PATH}" -o "${CSHARP_TEST_OUTPUT_DIR}"
