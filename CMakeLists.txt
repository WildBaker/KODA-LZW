project(KODA-LZW)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#aux_source_directory(. SRC_LIST)
#add_executable(${PROJECT_NAME} ${SRC_LIST})

include_directories(include)
add_library(lzw src/lib/lzw.cpp include/lib/lzw.h src/lib/types.cpp include/lib/types.h)

add_executable(test src/tests/test.cpp)
target_link_libraries(test lzw)

add_executable(compress src/lzw_compress)
target_link_libraries(compress lzw)

add_executable(decompress src/lzw_decompress)
target_link_libraries(decompress lzw)
