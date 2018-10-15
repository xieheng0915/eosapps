cmake_minimum_required(VERSION 3.11)
project(student)
set(CMAKE_BUILD_TYPE Release)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_library(StudentLib SHARED ${SOURCES})
install(TARGETS StudentLib DESTINATION library)
