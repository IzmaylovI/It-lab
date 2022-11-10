cmake_minimum_required(VERSION 3.25.0)

set( CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")
set( CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")

project(it-lab_first_task)

set(HDR headers/function.hpp)
set(SRC source/function.cpp)

include_directories(.)
add_library(func_algo ${HDR} ${SRC})

find_package(OpenMP)

# OpenMP_FOUND -есть ли библиотека в системе
if(OpenMP_FOUND)
    message(STATUS "Link OpenMP")
else()
    message(STATUS "Not link OpenMP")
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")

add_executable(it-lab_first_task main.cpp)
target_link_libraries(it-lab_first_task func_algo)
target_link_libraries(it-lab_first_task ${OpenMP_LIBRARIES})

add_executable(program_for_launch program.cpp)
