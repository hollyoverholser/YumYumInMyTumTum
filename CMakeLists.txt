cmake_minimum_required(VERSION 4.0)
project(YumYumInMyTumTum)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(YumYumInMyTumTum
        food.cpp
        food.h
        main.cpp
        maxHeap.cpp
        maxHeap.h
        mergeSort.cpp
        mergeSort.h)
