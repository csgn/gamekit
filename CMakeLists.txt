cmake_minimum_required(VERSION 3.30)
set(PROJECT_NAME gamekit)
set(PROJECT_NAME_FIRST_CAPITALIZED Gamekit)
set(PROJECT_NAME_ALL_CAPITALIZED GAMEKIT)

project(${PROJECT_NAME} LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(settings)
include(versioning)
include(commands)
include(dependencies)
include(clangd)
include(doxygen)
include(projects)
include(bindings)

target_compile_definitions(${PROJECT_NAME} PRIVATE ${PROJECT_API_EXPORT_VAR})