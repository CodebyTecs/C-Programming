# Задание: Создать библиотеку pipes из read_pipe.c write_pipe.c

cmake_minimum_required(VERSION 3.10)

set(SOURCE_EXE read_pipe.c write_pipe.c)
add_library(PIPES_LIB STATIC ${SOURCE_EXE})

