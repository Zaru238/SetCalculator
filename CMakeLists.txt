cmake_minimum_required(VERSION 3.5)
project(Template LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Boost REQUIRED)

add_subdirectory(library)
add_subdirectory(program)
add_subdirectory(tests)
