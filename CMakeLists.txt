cmake_minimum_required(VERSION 3.22)
project(deque)

set(CMAKE_CXX_STANDARD 14)

add_executable(deque main.cpp deque.h fila_circular.h)
