/**
    Cpp17 RobotMovement, robot.cpp
    Purpose: Represent for robot object

    @author CuongNX
    @version 1.0 11/1/2022
*/

#include "robot.h"
#include <iostream>

// Constructor initial size for grid that area for moving
Robot::Robot() : m_position {make_tuple(0,0)}
{
}

//Ask the robot to reset grid by a new size
void Robot::InitGrid(int size)
{
    if (!m_grid.empty()) {
            Move(0,0);
            m_grid.clear();
    }
    for(int i = 0; i < size; ++i) {
        vector<bool> mem(size, false);
        m_grid.push_back(mem);
    }
}

// Set the current position to position (x, y)
void Robot::Move(int x, int y)
{
    if (x < m_grid.size() && y < m_grid.size() && x >= 0 && y >= 0)
        m_position = make_tuple(x, y);
}

// Mark the line that robot passed
void Robot::Draw(vector<tuple<int, int>> line)
{
    for (auto sq : line){
        fill(get<0>(sq), get<1>(sq));
    }
}

// Getter return grid saved in robot
vector<vector<bool> > Robot::RGrid()
{
    return m_grid;
}

// Getter return current position of robot
tuple<int, int> Robot::Position()
{
    return m_position;
}

// Mark the current position to passed
void Robot::fill(int x, int y)
{
    if (x < m_grid.size() && y < m_grid.size() && x >= 0 && y >= 0)
        m_grid[x][y] = true;
}
