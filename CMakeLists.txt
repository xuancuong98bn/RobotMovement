cmake_minimum_required(VERSION 3.5)

project(RobotMovement LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(RobotMovement main.cpp
        utility.h utility.cpp
        robot.h robot.cpp
        controller.h controller.cpp
        input.txt input2.txt input3.txt
                            )

install(TARGETS RobotMovement
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
