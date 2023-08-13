cmake_minimum_required(VERSION 3.13)

project(QtrFingerprint LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib)
add_subdirectory(exe)
add_subdirectory(Indigo)

