set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#add_library(core ${core_SRCS})

set(SOURCE_FILES main.cpp vector.h unordered_set.h linked_list.h unordered_map.h)
add_executable(STD ${SOURCE_FILES})

