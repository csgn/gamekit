cmake_minimum_required(VERSION 3.30)
project(gamekit LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(Settings)
include(Dependencies)
include(Clangd)
include(Doxygen)
include(Testing)
include(Projects)