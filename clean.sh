#!/bin/sh

set -e

. ./config.sh

if [ -d "${BUILD_DIR}" ]; then
	rm -rf ${BUILD_DIR}
fi
