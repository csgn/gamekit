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

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.17.0
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src gamekit)
add_subdirectory(tests gamekit-tests)
