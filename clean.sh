#!/bin/sh

set -e

. ./config.sh

if [ -d "${BUILD_DIR}" ]; then
	rm -rf ${BUILD_DIR}
fi

if [ -d "${DOCS_DIR}/html" ]; then
	rm -rf ${DOCS_DIR}/html
fi
