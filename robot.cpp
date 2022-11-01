/**
    Cpp17 RobotMovement, robot.cpp
    Purpose: Represent for robot object

    @author CuongNX
    @version 1.0 11/1/2022
*/

#include "robot.h"

// Constructor initial size for grid that area for moving
Robot::Robot(int size) : mPosition {make_tuple(0,0)}
{
    for(int i = 0; i < size; ++i) {
        vector<bool> mem(size, false);
        mGrid.push_back(mem);
    }
}

// Ask the robot to execute the command
void Robot::Handle(tuple<RCmd, int, int> command)
{
    RCmd rcmd = get<0>(command);
    int x = get<1>(command);
    int y = get<2>(command);
    switch (rcmd) {
    case MOVE_TO:
        MoveTo(x, y);
        break;
    case LINE_TO:
        LineTo(x, y);
        break;
    default:
        break;
    }
}

// Ask the robot to move to position (x, y)
void Robot::MoveTo(int x, int y)
{
    move(x, y);
}

// Ask the robot to move to position (x, y) with drawing on the grid
void Robot::LineTo(int x, int y)
{
    if (x < mGrid.size() && y < mGrid.size()){
        double oldX = get<0>(mPosition);
        double oldY = get<1>(mPosition);
        vector<tuple<int, int>> cells;
        if (y == oldY) cells = getHLine(oldX, x , y);
        else if (x == oldX) cells = getVLine(x, y, oldY);
        else {
            //Calculate slope of y -> (y = ax + b)
            oldX += 0.5;
            oldY += 0.5;
            double newX = x + 0.5;
            double newY = y + 0.5;
            double slope = (newY - oldY)/(double)(newX - oldX);
            double coe = oldY - oldX*slope;
            // if slope y > 1, calculate slope of x -> (x = y/a - b/a)
            if (abs(slope) > 1) {
                coe = -coe/slope;
                slope = 1/slope;
                cells = symmetric(getDLine(oldY, newY, slope, coe));
            } else {
                cells = getDLine(oldX, newX, slope, coe);
            }
        }
        draw(cells);
        move(x, y);
    }
}

// Getter return grid saved in robot
vector<vector<bool> > Robot::RGrid()
{
    return mGrid;
}

// Get cells in vertical
vector<tuple<int, int> > Robot::getVLine(int x, int y1, int y2)
{
    vector<tuple<int, int>> cells;
    if (y1 > y2) swap(y1, y2);
    for(int i = y1; i <= y2; i++){
        tuple t = make_tuple(x, i);
        cells.push_back(t);
    }
    return cells;
}

// Get cells in horizontal
vector<tuple<int, int> > Robot::getHLine(int x1, int x2, int y)
{
    vector<tuple<int, int>> cells;
    if (x1 > x2) swap(x1, x2);
    for(int i = x1; i <= x2; i++){
        tuple t = make_tuple(i, y);
        cells.push_back(t);
    }
    return cells;
}

// Get cells in diagonal by equation with param of row or column
vector<tuple<int, int> > Robot::getDLine(double oldP, double newP, double slope, double coe)
{
    //calculate list point with double value
    vector<tuple<double, double>> points;
    if (oldP > newP) swap(newP, oldP);
    for(float i = oldP; i <= newP; i++){
        tuple t = make_tuple(i-0.5, (i-0.5)*slope + coe);
        points.push_back(t);
    }
    //convert to list cell
    vector<tuple<int, int>> cells;
    int checkY = floor(get<1>(points[0]));
    for (auto p : points){
        int nx = floor(get<0>(p));
        int ny = floor(get<1>(p));

        //check whether point and cell are duplicates (means that equation pass by integer value)
        //double - int may not have result as zero by floating point, using less than 1e-6 instead of
        if (abs(get<1>(p)-ny) < 1e-6){
            nx += slope < 0 ? -1 : 0;
            checkY = ny;
        }
        tuple<int, int> t = make_tuple(nx, ny);
        cells.push_back(t);

        //check whether current cell and saved cell (checkY) are different
        //(means that equation pass through 2 cells is not by integer value)
        if (ny != checkY){
            tuple<int, int> t2 = make_tuple(nx-1, ny);
            cells.push_back(t2);
            checkY = ny;
        }
    }
    return cells;
}

// Make symmetry the input cells
vector<tuple<int, int> > Robot::symmetric(vector<tuple<int, int>> line)
{
    vector<tuple<int, int>> res;
    for (auto sq : line){
        res.push_back(make_tuple(get<1>(sq), get<0>(sq)));
    }
    return res;
}

// Set the current position to position (x, y)
void Robot::move(int x, int y)
{
    if (x < mGrid.size() && y < mGrid.size() && x >= 0 && y >= 0)
        mPosition = make_tuple(x, y);
}

// Mark the line that robot passed
void Robot::draw(vector<tuple<int, int>> line)
{
    for (auto sq : line){
        fill(get<0>(sq), get<1>(sq));
    }
}

// Mark the current position to passed
void Robot::fill(int x, int y)
{
    if (x < mGrid.size() && y < mGrid.size() && x >= 0 && y >= 0)
        mGrid[x][y] = true;
}
