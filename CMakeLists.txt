cmake_minimum_required(VERSION 3.22)
project(RK2)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/third-party/gtest" "gtest")


add_library(tree STATIC symmetrictree.cpp)

add_executable(test ${CMAKE_CURRENT_SOURCE_DIR}/tests/MainTest.cpp)


target_link_libraries(test gtest gtest_main tree)

cmake_minimum_required(VERSION 3.4)

)