#ifndef ROBOT_H
#define ROBOT_H

/**
    Cpp17 RobotMovement, robot.h
    Purpose: Represent for robot object

    @author CuongNX
    @version 1.0 11/1/2022
*/

#include <tuple>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

/**
 * @brief The Robot class is represent for robot in problem
 */
class Robot
{
public:
    /**
     * @brief Robot constructor
     */
    Robot();

    /**
     * @brief InitGrid Ask the robot to reset grid by a new size
     * @param size Store size for grid
     */
    void InitGrid(int);

    /**
     * @brief Move Set the current position to position (x, y)
     * @param x row of next position in the grid
     * @param y column of next position in the grid
     */
    void Move(int x, int y);

    /**
     * @brief Draw Mark the line that robot passed
     * @param line vector of route that robot passed
     */
    void Draw(vector<tuple<int, int>> line);

    /**
     * @brief RGrid getter return grid saved in robot
     * @return maxtrix of grid saved in robot
     */
    vector<vector<bool>> RGrid();

    /**
     * @brief Position getter return current position of robot
     * @return tuple store position of robot
     */
    tuple<int, int> Position();
private:
    // Store matrix of area that robot can move
    vector<vector<bool>> m_grid;

    // Store current position of robot
    tuple<int, int> m_position;

    /**
     * @brief fill Mark the current position to passed
     * @param x row of current position in the grid
     * @param y column of current position in the grid
     */
    void fill(int x, int y);
};

#endif // ROBOT_H
