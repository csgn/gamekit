PROJECT_NAME=gamekit

BUILD_DEBUG_DIR=cmake-build-debug
BUILD_RELEASE_DIR=cmake-build-release
BUILD_DIR=

DOCS_DIR=docs/

if [ -z $1 ]; then
	BUILD_DIR=${BUILD_DEBUG_DIR}
elif [ $1 == "release" ]; then
	BUILD_DIR=${BUILD_RELEASE_DIR}
else
	echo "Unrecognized parameter: $1"
fi
