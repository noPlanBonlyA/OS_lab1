cmake_minimum_required(VERSION 3.28)

project(dmitrievmyshell VERSION 0.1.0)

option(DMITRIEVMYSHELL_DEVELOPER "Enable ${PROJECT_NAME} developer mode" OFF)
option(DMITRIEVMYSHELL_BENCHMARK "Enable ${PROJECT_NAME} benchmark module" OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(cmake/CompileOptions.cmake)

add_subdirectory(source)

if(DMITRIEVMYSHELL_DEVELOPER)
    find_package(GTest REQUIRED)
    add_subdirectory(test)
endif()
    
if(DMITRIEVMYSHELL_BENCHMARK)
    find_package(GBenchmark REQUIRED)
    add_subdirectory(benchmark)
endif()
