cmake_minimum_required(VERSION 2.6)
project(algorithmscourse)
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

add_compile_options(-std=c++11)

add_subdirectory(src)
include_directories ("${PROJECT_SOURCE_DIR}/src")

add_executable(algorithmscourse main.cpp)
target_link_libraries (algorithmscourse UnionFind)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

install(TARGETS algorithmscourse RUNTIME DESTINATION bin)

