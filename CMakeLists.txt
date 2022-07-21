cmake_minimum_required(VERSION 3.1.0)
project(CppSerial)

add_definitions(-std=c++14)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


include_directories(include)

# add the library
add_library(serial SHARED src/serial.cpp)

#add the executable
add_executable(serial_node src/serial_node.cpp)
target_link_libraries(serial_node serial)