#ifndef RCOMMAND_H
#define RCOMMAND_H

/**
    Cpp17 RobotMovement, rcommand.h
    Purpose: Represent for command to control the robot

    @author CuongNX
    @version 1.0 11/4/2022
*/

#include <iostream>
#include "robot.h"

using namespace std;

/**
 * @brief The RCommand abstract class is base command for specific command to control the robot
 */
class RCommand
{
public:
    // Default destructor for abstract class
    virtual ~RCommand() = default;

    /**
     * @brief SendTo Request robot execute the command
     * Must be override in derived class to execute with each command description
     * @param robot Object handle the command
     */
    virtual void SendTo(Robot* robot) = 0;
protected:
    // store value of param 1 of command
    int m_x;

    // store value of param 2 of command
    int m_y;
};

#endif // RCOMMAND_H
