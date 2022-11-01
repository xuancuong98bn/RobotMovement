#ifndef ROBOT_H
#define ROBOT_H

#include <tuple>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>

/**
    Cpp17 RobotMovement, robot.h
    Purpose: Represent for robot object

    @author CuongNX
    @version 1.0 11/1/2022
*/

using namespace std;

/**
 * @brief The Robot class is represent for robot in problem
 */
class Robot
{
public:
    //Commands code using for robot
    enum RCmd {DIMENSION, MOVE_TO, LINE_TO};

    /**
     * @brief Robot constructor initial size for grid that area for moving
     * @param size of grid
     */
    Robot(int size);

    /**
     * @brief Handle Ask the robot to execute the command
     * @param command Store command
     */
    void Handle(tuple<RCmd, int, int>);

    /**
     * @brief MoveTo Ask the robot to move to position (x, y)
     * @param x row of next position in the grid
     * @param y column of next position in the grid
     */
    void MoveTo(int x, int y);

    /**
     * @brief LineTo Ask the robot to move to position (x, y) with drawing on the grid
     * @param x row of next position in the grid
     * @param y column of next position in the grid
     */
    void LineTo(int x, int y);

    /**
     * @brief RGrid getter return grid saved in robot
     * @return maxtrix of grid saved in robot
     */
    vector<vector<bool>> RGrid();
private:
    // Store matrix of area that robot can move
    vector<vector<bool>> mGrid;

    // Store current position of robot
    tuple<int, int> mPosition;

    /**
     * @brief getVLine Get cells in vertical
     * @param x row of the grid
     * @param y1 column of start position in the grid
     * @param y2 column of end position in the grid
     * @return vector of vertical cells between y1 and y2, include y1, y2
     */
    vector<tuple<int, int>> getVLine(int x, int y1, int y2);

    /**
     * @brief getHLine Get cells in horizontal
     * @param x1 row of start position in the grid
     * @param x1 row of end position in the grid
     * @param y column of the grid
     * @return vector of horizontal cells between x1 and x2, include x1, x2
     */
    vector<tuple<int, int>> getHLine(int x1, int x2, int y);

    /**
     * @brief getDLine Get cells in diagonal by equation with param of row or column
     * @param oldP Param of start position
     * @param newP Param of end position
     * @param slope Slope of diagonal equation
     * @param coe Coefficient of diagonal equation
     * @return vector of diagonal cells between oldP and newP, include oldP, newP
     */
    vector<tuple<int, int>> getDLine(double oldP, double newP, double slope, double coe);

    /**
     * @brief symmetric Make symmetry the input cells
     * @param line vector of cells
     * @return vector of cells that made symmetry
     */
    vector<tuple<int, int>> symmetric(vector<tuple<int, int>> line);

    /**
     * @brief move Set the current position to position (x, y)
     * @param x row of next position in the grid
     * @param y column of next position in the grid
     */
    void move(int x, int y);

    /**
     * @brief draw Mark the line that robot passed
     * @param line vector of route that robot passed
     */
    void draw(vector<tuple<int, int>> line);

    /**
     * @brief fill Mark the current position to passed
     * @param x row of current position in the grid
     * @param y column of current position in the grid
     */
    void fill(int x, int y);
};

#endif // ROBOT_H
