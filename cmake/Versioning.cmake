# -------------------------------
# Git versioning
# -------------------------------
find_package(Git REQUIRED)

# Get the latest Git tag
execute_process(
    COMMAND ${GIT_EXECUTABLE} describe --tags --abbrev=0
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_LAST_TAG
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
)

if(NOT GIT_LAST_TAG)
    set(GIT_LAST_TAG "v0.0.0")
endif()

# Get commit messages since last tag
execute_process(
    COMMAND ${GIT_EXECUTABLE} log ${GIT_LAST_TAG}..HEAD --pretty=format:%s
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_COMMIT_MESSAGES
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Parse major, minor, patch from the latest tag
string(REGEX REPLACE "v([0-9]+)\\.([0-9]+)\\.([0-9]+)([-A-Za-z0-9\\.]+)?" "\\1" PROJECT_VERSION_MAJOR "${GIT_LAST_TAG}")
string(REGEX REPLACE "v([0-9]+)\\.([0-9]+)\\.([0-9]+)([-A-Za-z0-9\\.]+)?" "\\2" PROJECT_VERSION_MINOR "${GIT_LAST_TAG}")
string(REGEX REPLACE "v([0-9]+)\\.([0-9]+)\\.([0-9]+)([-A-Za-z0-9\\.]+)?" "\\3" PROJECT_VERSION_PATCH "${GIT_LAST_TAG}")
string(REGEX REPLACE "v([0-9]+)\\.([0-9]+)\\.([0-9]+)([-A-Za-z0-9\\.]+)?" "\\4" PROJECT_VERSION_PRERELEASE "${GIT_LAST_TAG}")

# Increment version based on commit messages
if(GIT_COMMIT_MESSAGES MATCHES "BREAKING CHANGE")
    math(EXPR PROJECT_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}+1")
    set(PROJECT_VERSION_MINOR 0)
    set(PROJECT_VERSION_PATCH 0)
elseif(GIT_COMMIT_MESSAGES MATCHES "^feat")
    math(EXPR PROJECT_VERSION_MINOR "${PROJECT_VERSION_MINOR}+1")
    set(PROJECT_VERSION_PATCH 0)
elseif(GIT_COMMIT_MESSAGES MATCHES "^fix")
    math(EXPR PROJECT_VERSION_PATCH "${PROJECT_VERSION_PATCH}+1")
endif()

# Compose full version string
if(PROJECT_VERSION_PRERELEASE)
    set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}${PROJECT_VERSION_PRERELEASE}")
else()
    set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
endif()

# Get Git describe output
execute_process(
    COMMAND ${GIT_EXECUTABLE} describe --tags --dirty --always
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_DESCRIBE
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Build timestamp
string(TIMESTAMP BUILD_DATE "%Y-%m-%d %H:%M:%S")

# -------------------------------
# Generate version header
# -------------------------------
configure_file(
    "${CMAKE_SOURCE_DIR}/include/gamekit/version.h.in"
    "${CMAKE_BINARY_DIR}/version.h"
    @ONLY
)