cmake_minimum_required(VERSION 2.8.4)
project(distributor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${distributor_SOURCE_DIR})
add_subdirectory(main)
add_subdirectory(managers)
add_subdirectory(functions)
add_subdirectory(uris)
add_subdirectory(data)

set(SOURCE_FILES main.cpp)
add_executable(distributor ${SOURCE_FILES})

target_link_libraries(distributor MAIN)
target_link_libraries(distributor MANAGERS)
target_link_libraries(distributor FUNCTIONS)
target_link_libraries(distributor URIS)
target_link_libraries(distributor DATA)
