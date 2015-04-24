project(KODA-LZW)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#aux_source_directory(. SRC_LIST)
#add_executable(${PROJECT_NAME} ${SRC_LIST})

include_directories(include)
add_library(lzw src/lzw.cpp include/lzw.h src/types.cpp include/types.h)
add_executable(test src/test.cpp src/types.cpp include/types.h)

add_executable(compress src/lzw_compress)
target_link_libraries(compress lzw)

add_executable(decompress src/lzw_decompress)
target_link_libraries(decompress lzw)
