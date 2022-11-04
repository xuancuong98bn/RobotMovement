#ifndef CMDMOVETO_H
#define CMDMOVETO_H

/**
    Cpp17 RobotMovement, cmd_moveto.h
    Purpose: Represent for command that ask robot to move

    @author CuongNX
    @version 1.0 11/4/2022
*/

#include "rcommand.h"

/**
 * @brief The CmdMoveTo class represent for command that ask robot to move
 */
class CmdMoveTo : public RCommand
{
public:
    /**
     * @brief Construct init value for m_x, m_y
     * @param x int, y int
     */
    CmdMoveTo(int x, int y);

    /**
     * @brief SendTo Request robot to move to (x,y) position
     * @param robot Object handle the command
     */
    void SendTo(Robot* robot);
};

#endif // CMDMOVETO_H
