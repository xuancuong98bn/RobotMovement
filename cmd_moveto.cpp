#include "cmd_moveto.h"

// Construct init value for m_x, m_y
CmdMoveTo::CmdMoveTo(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}

// Request robot to move to (x,y) position
void CmdMoveTo::SendTo(Robot* robot)
{
    robot->Move(m_x, m_y);
}
