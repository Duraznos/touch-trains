cmake_minimum_required(VERSION 3.2)
project(touch_trains)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ")

set(SOURCE_FILES main.c)
add_executable(touch_trains ${SOURCE_FILES} train.h train.c line.h line.c track.h track.c defs.h station.h station.c include.h)