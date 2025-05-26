cmake_minimum_required(VERSION 3.10)
project(Project C)

option(STATIC "Build with static library" OFF)

add_library(mylib_static STATIC main.c functions.c)
set_target_properties(mylib_static PROPERTIES OUTPUT_NAME "MYLIB")
add_library(mylib_shared SHARED main.c functions.c)
set_target_properties(mylib_shared PROPERTIES OUTPUT_NAME "MYLIB")

add_executable(prog prog.c)

if(STATIC)
    target_link_libraries(prog mylib_static)
else()
    target_link_libraries(prog mylib_shared)
endif()