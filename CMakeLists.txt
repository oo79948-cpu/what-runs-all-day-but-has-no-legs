cmake_minimum_required(VERSION 3.24)

project("What Runs All Day But Has No Legs")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp src/timer.cpp)
