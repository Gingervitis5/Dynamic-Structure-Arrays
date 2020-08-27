cmake_minimum_required(VERSION 3.12)
project(Lab13 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(utils)

add_executable(Lab13
        utils/fileUtils.c
        utils/fileUtils.h
        utils/utils.c
        utils/utils.h
        cscd240Lab13.c
        lab13.h
        lab13.c)
