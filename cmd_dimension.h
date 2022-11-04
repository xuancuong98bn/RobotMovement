#ifndef CMDDIMENSION_H
#define CMDDIMENSION_H

/**
    Cpp17 RobotMovement, cmd_moveto.h
    Purpose: Represent for command that ask robot to init grid with a dimension value

    @author CuongNX
    @version 1.0 11/4/2022
*/

#include "rcommand.h"

/**
 * @brief The CmdDimension class represent for command that ask robot to init grid with a dimension value
 */
class CmdDimension : public RCommand
{
public:
    /**
     * @brief Construct init value for m_x, m_y
     * @param size int will be assigned for 2 members variable
     */
    CmdDimension(int size);

    /**
     * @brief SendTo Request robot to init grid with the size value
     * @param robot Object handle the command
     */
    void SendTo(Robot* robot);
};

#endif // CMDDIMENSION_H
