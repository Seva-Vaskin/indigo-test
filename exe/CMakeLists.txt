set(CMAKE_CXX_STANDARD 20)

add_executable(exe main.cpp)

target_include_directories(exe
        PUBLIC .
        PUBLIC ../third_party/Indigo/api/c/indigo
        PUBLIC ../third_party/Indigo/api/cpp/src
        PUBLIC ../third_party/Indigo/core/indigo-core
        PUBLIC ../third_party/Indigo/core/indigo-core/common
        PUBLIC ../third_party/Indigo/third_party/object_threadsafe
        PUBLIC ../third_party/abseil-cpp
        )

target_link_libraries(exe indigo indigo-cpp)
target_link_libraries(exe lib)