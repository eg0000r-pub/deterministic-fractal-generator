cmake_minimum_required(VERSION 3.25)
project(deterministic_aggregates)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Werror ${CMAKE_CXX_FLAGS}")

include_directories("/home/egor/Libraries/include")
link_directories("/home/egor/Libraries/bin")

add_executable(deterministic_aggregates main.cpp type-a.cpp type-b.cpp type-c.cpp type-d.cpp)

target_link_libraries(deterministic_aggregates FractalCommon)
