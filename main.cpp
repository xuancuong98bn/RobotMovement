/**
    Cpp17 RobotMovement, main.cpp
    Purpose: Main of project

    @author CuongNX
    @version 1.0 11/1/2022
*/

#include <iostream>
#include "controller.h"

using namespace std;

int main()
{
    Controller control = Controller();
    control.start();
}
