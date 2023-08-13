cmake_minimum_required(VERSION 3.13)

project(IndigoTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER "9.4")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-maybe-uninitialized") # Disable -Werror=maybe-uninitialized flag,
    # needed to compile gtest on new gcc compilers
endif ()

SET(BUILD_BINGO OFF CACHE BOOL "BUILD_BINGO Indigo option")
SET(BUILD_BINGO_ELASTIC OFF CACHE BOOL "BUILD_BINGO_ELASTIC Indigo option")
SET(BUILD_INDIGO_WRAPPERS OFF CACHE BOOL "BUILD_INDIGO_WRAPPERS Indigo option")
SET(BUILD_INDIGO_UTILS OFF CACHE BOOL "BUILD_INDIGO_UTILS Indigo option")
SET(WITH_STATIC ON CACHE BOOL "WITH_STATIC Indigo option")
SET(ABSL_PROPAGATE_CXX_STD ON)

add_subdirectory(Indigo)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE sources *.cpp *.h)

add_executable(IndigoTest main.cpp ${sources})

target_include_directories(IndigoTest
        PUBLIC .
        PUBLIC ../third_party/Indigo/api/c/indigo
        PUBLIC ../third_party/Indigo/api/cpp/src
        )

target_link_libraries(IndigoTest indigo indigo-cpp indigo-core)


#####################################3


#project(IndigoTest)
#
#cmake_minimum_required(VERSION 3.25)
#set(CMAKE_CXX_STANDARD 20)
#
#add_executable(IndigoTest main.cpp)
#
#SET(BUILD_BINGO OFF CACHE BOOL "BUILD_BINGO Indigo option")
#SET(BUILD_BINGO_ELASTIC OFF CACHE BOOL "BUILD_BINGO_ELASTIC Indigo option")
#SET(BUILD_INDIGO_WRAPPERS OFF CACHE BOOL "BUILD_INDIGO_WRAPPERS Indigo option")
#SET(BUILD_INDIGO_UTILS OFF CACHE BOOL "BUILD_INDIGO_UTILS Indigo option")
#SET(WITH_STATIC ON CACHE BOOL "WITH_STATIC Indigo option")
#
#target_include_directories(IndigoTest
#        PUBLIC .
#        PUBLIC ./Indigo/api/c/indigo
#        PUBLIC ./Indigo/api/cpp/src
#        PUBLIC ./Indigo/core/indigo-core
#        PUBLIC ./Indigo/core/indigo-core/common
#        PUBLIC ./Indigo/third_party/object_threadsafe
#        )
#
#target_link_libraries(indigo indigo-cpp bingo-nosql indigo-core)


