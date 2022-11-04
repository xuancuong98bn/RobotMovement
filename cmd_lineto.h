#ifndef CMDLINETO_H
#define CMDLINETO_H

/**
    Cpp17 RobotMovement, cmd_moveto.h
    Purpose: Represent for command that ask robot to draw a line

    @author CuongNX
    @version 1.0 11/4/2022
*/

#include "rcommand.h"

/**
 * @brief The CmdLineTo class represent for command that ask robot to draw a line
 */
class CmdLineTo : public RCommand
{
public:
    /**
     * @brief Construct init value for m_x, m_y
     * @param x int, y int
     */
    CmdLineTo(int x, int y);

    /**
     * @brief SendTo Request robot to draw a line
     * @param robot Object handle the command
     */
    void SendTo(Robot* robot);
private:
    /**
     * @brief LineFrom Get cell of the robot when move from current to position (x, y)
     * @param x row of next position in the grid
     * @param y column of next position in the grid
     */
    vector<tuple<int, int>> lineFrom(tuple<int, int> pos, int size);

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
     * @brief getDLine Get cells in diagonal by equation with x is variable
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
};

#endif // CMDLINETO_H
