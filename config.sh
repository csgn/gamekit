PROJECT_NAME=gamekit

BUILD_DEBUG_DIR=build/linux/debug
BUILD_RELEASE_DIR=build/linux/release
BUILD_DIR=

DOCS_DIR=docs/

if [ -z $1 ]; then
	BUILD_DIR=${BUILD_DEBUG_DIR}
elif [ $1 == "release" ]; then
	BUILD_DIR=${BUILD_RELEASE_DIR}
else
	echo "Unrecognized parameter: $1"
fi
