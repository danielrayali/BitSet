cmake_minimum_required (VERSION 3.5.1)
project (BitSet CXX)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable (bitset src/main.cc)

target_include_directories (bitset PUBLIC src)

target_link_libraries (bitset)

set_target_properties (bitset PROPERTIES LINKER_LANGUAGE CXX)
