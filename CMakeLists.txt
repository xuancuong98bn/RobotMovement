cmake_minimum_required(VERSION 3.5)

project(RobotMovement LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(RobotMovement main.cpp
        utility.h utility.cpp
        rcommand.h
        cmd_dimension.h cmd_dimension.cpp
        cmd_moveto.h cmd_moveto.cpp
        cmd_lineto.h cmd_lineto.cpp
        robot.h robot.cpp
        output.h output.cpp
        controller.h controller.cpp
        input.txt input2.txt input3.txt
                            )

install(TARGETS RobotMovement
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
