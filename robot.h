#ifndef ROBOT_H
#define ROBOT_H

#include <tuple>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

class Robot
{
public:
    enum RCmd {DIMENSION, MOVE_TO, LINE_TO};

    Robot(int size);
    void Handle(tuple<RCmd, int, int>);
    void MoveTo(int x, int y);
    void LineTo(int x, int y);
    vector<vector<bool>> RGrid();
private:
    vector<vector<bool>> mGrid;
    tuple<int, int> mPosition;

    vector<tuple<int, int>> getVLine(int x, int y1, int y2);
    vector<tuple<int, int>> getHLine(int x1, int x2, int y);
    vector<tuple<int, int>> getDLine(double oldP, double newP, double slope, double coe);
    vector<tuple<int, int>> symmetric(vector<tuple<int, int>> line);
    void move(int x, int y);
    void draw(vector<tuple<int, int>> line);
    void fill(int x, int y);
};

#endif // ROBOT_H
