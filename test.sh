#!/bin/sh

set -e

. ./config.sh

test_native() {
	cd "${TESTS_OUTPUT_DIR:?}"
	ctest
}

#test_csharp() {
#	export LD_LIBRARY_PATH="${CSHARP_OUTPUT_DIR:?}/bin":"${LD_LIBRARY_PATH}"
#	dotnet test "${CSHARP_TEST_CSPROJ_PATH:?}" -o "${CSHARP_TEST_OUTPUT_DIR:?}"
#}

test_all() {
	test_native
#	test_csharp
}

case "$1" in
#    csharp)
#        test_csharp
#        ;;
    all)
        test_all
        ;;
    cpp|native|*)
        test_native
        ;;
esac
