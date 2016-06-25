cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(algorithmscourse)
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

add_compile_options(-std=c++11)

add_subdirectory(src)
add_subdirectory(tests)

include_directories ("${PROJECT_SOURCE_DIR}/src")

add_executable(algorithmscourse main.cpp)
target_link_libraries (algorithmscourse Src)

add_executable(UnionFind_test tests/UnionFind_test.cpp)
target_link_libraries (UnionFind_test Src)

add_executable(PercolationStats_test tests/PercolationStats_test.cpp)
target_link_libraries (PercolationStats_test Src)

add_executable(Stack_test tests/Stack_test.cpp)
target_link_libraries (Stack_test Src)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

install(TARGETS algorithmscourse RUNTIME DESTINATION bin)

# Testing
enable_testing()

add_test(NAME UnionFind_test_1
	 COMMAND UnionFind_test)

add_test(NAME PercolationStats_test_1
	 COMMAND PercolationStats_test 100 100)
	 
add_test(NAME PercolationStats_test_2
	 COMMAND PercolationStats_test 200 100)
	 
add_test(NAME PercolationStats_test_3
	 COMMAND PercolationStats_test 300 100)
	 
#add_test(NAME PercolationStats_test_4
#	 COMMAND PercolationStats_test 500 100)

add_test(NAME Stack_test_1
	 COMMAND Stack_test)


