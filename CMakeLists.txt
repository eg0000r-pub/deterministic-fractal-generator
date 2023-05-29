cmake_minimum_required(VERSION 3.25)
project(deterministic_aggregates)

set(CMAKE_CXX_STANDARD 17)

include_directories("/home/egor/Libraries/include")
link_directories("/home/egor/Libraries/bin")

add_executable(deterministic_aggregates main.cpp)

target_link_libraries(deterministic_aggregates FractalCommon)
