cmake_minimum_required(VERSION 3.10)

project(soal_2_oop)

set(CMAKE_CXX_STANDARD 17)

# include header folder
include_directories(include)

# output executable into bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# executable
add_executable(program
    src/main.cpp
    src/mcu.cpp
    src/mcu_cam_controller.cpp
    src/mcu_walker.cpp
)