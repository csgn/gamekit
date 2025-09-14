cmake_minimum_required(VERSION 3.30)
project(gamekit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.17.0
)
FetchContent_MakeAvailable(googletest)

include_directories(include)

add_subdirectory(src gamekit)
add_subdirectory(tests gamekit-tests)
