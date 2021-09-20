cmake_minimum_required(VERSION 3.16)
project(SqEqSo C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_EXE main.c)
set(SOURCE_LIB library.c Unittest.c)
add_library(library STATIC ${SOURCE_LIB})
add_executable(main ${SOURCE_EXE})
target_link_libraries(main library Unittest)