cmake_minimum_required(VERSION 3.9)
project(Htcpcp)
 
include_directories(include)

file(GLOB SOURCES "src/*.cpp")

set(EXECUTABLE_OUTPUT_PATH "../bin")

add_executable(HtcpcpMessage ${SOURCES})
