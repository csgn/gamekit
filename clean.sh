#!/bin/sh

set -e

. ./config.sh

TARGET="$1"

if [ ! -d "${BUILD_DIR}" ]; then
    echo "There is no build dir: ${BUILD_DIR}"
    exit 0
fi

clean_native() {
	rm -rf "${BUILD_DIR:?}/gamekit"
	rm -rf "${BUILD_DIR:?}/gamekit-tests"
}

clean_csharp() {
	rm -rf "${BUILD_DIR:?}/gamekit-csharp"
	rm -rf "${BUILD_DIR:?}/gamekit-csharp-tests"
	rm -rf "${CSHARP_DIR:?}/bin"
	rm -rf "${CSHARP_DIR:?}/obj"
}

clean_all() {
	clean_native
	clean_csharp
}

case "$TARGET" in
    csharp)
        echo "Cleaning CSharp..."
		clean_csharp
        ;;
    cpp|native)
        echo "Cleaning Native..."
		clean_native
        ;;
    "" )
        echo "Cleaning all..."
		clean_all
        ;;
    * )
        echo "Unknown parameter: $TARGET"
        exit 1
        ;;
esac

if [ -f ".clangd" ]; then
    rm .clangd
fi
