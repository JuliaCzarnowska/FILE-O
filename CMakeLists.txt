cmake_minimum_required(VERSION 3.21)

if (NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

# Set the project props
project(loen LANGUAGES CXX C)

add_subdirectory(fileo)
add_subdirectory(algorithms)
