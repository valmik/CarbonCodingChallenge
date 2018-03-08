cmake_minimum_required(VERSION 3.1)
project(roboagents)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package (Threads)

include_directories(
  include/
)

add_executable(roboagents
  src/main.cpp
  src/robot.cpp
  src/world.cpp
)
target_link_libraries (roboagents ${CMAKE_THREAD_LIBS_INIT})
