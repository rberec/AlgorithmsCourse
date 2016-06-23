cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(algorithmscourse)
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

add_compile_options(-std=c++11)

add_subdirectory(src)
include_directories ("${PROJECT_SOURCE_DIR}/src")

add_executable(algorithmscourse main.cpp)
target_link_libraries (algorithmscourse Src)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

install(TARGETS algorithmscourse RUNTIME DESTINATION bin)

# Testing
enable_testing()

add_test(NAME PercolationTest
	 COMMAND algorithmscourse "Percolation" 100 100)
	 
add_test(NAME PercolationTest2
	 COMMAND algorithmscourse "Percolation" 200 100)
	 
add_test(NAME PercolationTest3
	 COMMAND algorithmscourse "Percolation" 300 100)
	 
add_test(NAME PercolationTest4
	 COMMAND algorithmscourse "Percolation" 500 100)

