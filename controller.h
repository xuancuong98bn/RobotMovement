#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

#include "robot.h"

using namespace std;

static const string sCommandFile = "input3.txt";

class Controller
{
public:
    Controller();
    void start();
    ~Controller();
private:
    int size;
    Robot* robot;
    vector<tuple<Robot::RCmd,int, int>> commands;

    void convertCmd(vector<tuple<string,int, int>>);
    void printGrid(vector<vector<bool>>);
};

#endif // CONTROLLER_H
