cmake_minimum_required(VERSION 3.3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(GoogleTest)

include(CTest)
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

#target_link_libraries(GoogleTest /usr/local/lib/libgtest.a /usr/local/lib/libgtest_main.a)

#add_executable(GoogleTest gtest.cpp ${test_SRCS})
#add_test(GoogleTest GoogleTest )