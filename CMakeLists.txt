cmake_minimum_required(VERSION 2.8.4)
project(distributor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${distributor_SOURCE_DIR})
add_subdirectory(main)

set(SOURCE_FILES main.cpp)
add_executable(distributor ${SOURCE_FILES})

target_link_libraries(distributor MAIN)
