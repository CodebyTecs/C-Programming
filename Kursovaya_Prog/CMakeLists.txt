cmake_minimum_required(VERSION 3.10)
project(FrequencyAnalysis)

set(CMAKE_C_STANDARD 11)

find_path(CMOCKA_INCLUDE_DIR NAMES cmocka.h PATHS /opt/homebrew/include /usr/local/include /usr/include)
find_library(CMOCKA_LIBRARY NAMES cmocka libcmocka libcmocka.0 PATHS /opt/homebrew/lib /usr/local/lib /usr/lib)

add_library(functions STATIC functions.c)
target_include_directories(functions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(frequency_analysis main.c)
target_link_libraries(frequency_analysis functions)

add_executable(test_functions test_functions.c)
target_include_directories(test_functions PRIVATE ${CMOCKA_INCLUDE_DIR})
target_link_libraries(test_functions functions ${CMOCKA_LIBRARY})

