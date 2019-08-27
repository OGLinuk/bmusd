cmake_minimum_required(VERSION 3.10)

project(upd)

add_executable(
    bmusd
    bmusd.cpp
    daemon.h
    daemon.cpp
    init.h
    init.cpp
    mapper.h
    mapper.cpp
)