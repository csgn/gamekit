cmake_minimum_required(VERSION 3.30)
project(gamekit)

if(EXISTS "${CMAKE_SOURCE_DIR}/.clangd.in")
    configure_file(
            "${CMAKE_SOURCE_DIR}/.clangd.in"
			"${CMAKE_SOURCE_DIR}/.clangd"
            @ONLY
    )
endif()

set(CMAKE_CXX_STANDARD 17)

# Generate Doxyfile
include(FetchContent)
FetchContent_Declare(
    doxygen-awesome-css
    URL https://github.com/jothepro/doxygen-awesome-css/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(doxygen-awesome-css)

FetchContent_GetProperties(doxygen-awesome-css SOURCE_DIR AWESOME_CSS_DIR)

set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

# Add GTest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.17.0
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src gamekit)
add_subdirectory(tests gamekit-tests)
