# Задание: Создать библиотеку из background.c и слинковать ее с библиотекой pipes

cmake_minimum_required(VERSION 3.10)

set(SOURCE_LIB background.c)
add_library(BACKGROUND_LIB STATIC ${SOURCE_LIB})
