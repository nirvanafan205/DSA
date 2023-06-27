cmake_minimum_required(VERSION 3.10)
project(BubbleSortTest)

set(CMAKE_CXX_STANDARD 11)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link against GTest and any additional libraries
add_executable(bubble_sort_test bubble_sort_test.cpp)
target_link_libraries(bubble_sort_test ${GTEST_LIBRARIES} pthread)

