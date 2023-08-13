cmake_minimum_required(VERSION 3.12)

set(This lib)

file(GLOB_RECURSE ${This}-sources
        "SomeLibHeader.h"
        "../Indigo/api/c/indigo/src/*.cpp"
        )

add_library(${This} STATIC ${${This}-sources})

target_link_libraries(${This} indigo indigo-cpp indigo-core)

target_include_directories(${This} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/src)
include(../Indigo/api/indigo-version.cmake)
configure_file(../Indigo/api/c/indigo/src/indigo_version.h.in ${CMAKE_CURRENT_BINARY_DIR}/src/indigo_version.h)
