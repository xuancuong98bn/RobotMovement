#include "cmd_dimension.h"

// Construct init value for m_x, m_y
CmdDimension::CmdDimension(int size)
{
    this->m_x = size;
    this->m_y = size;
}

// Request robot to init grid with the size value
void CmdDimension::SendTo(Robot *robot)
{
    robot->InitGrid(m_x);
}
