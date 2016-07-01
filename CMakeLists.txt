cmake_minimum_required(VERSION 3.3)
project(STD)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(gtest-1.7.0)
#add_executable(STD ${SOURCE_FILES})

include_directories(${gtest_SOURCE_DIR}/include)
set(test_sources
        test/vector_test.cpp
        test/unordered_set_test.cpp test/test_main.cpp test/linked_list_test.cpp)
add_executable(GoogleTest ${test_sources})
target_link_libraries(GoogleTest gtest_main)
