project(KODA-LZW)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#aux_source_directory(. SRC_LIST)
#add_executable(${PROJECT_NAME} ${SRC_LIST})

include_directories(include)
#add_library(lzwtypes src/types.cpp include/types.h)
add_executable(test src/main.cpp src/types.cpp include/types.h)
#target_link_libraries(test lzwtypes)
