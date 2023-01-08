cmake_minimum_required(VERSION 3.17)
project(scrabble C)

set(CMAKE_C_STANDARD 99)

add_executable(scrabble main.c Function.c Function.h)