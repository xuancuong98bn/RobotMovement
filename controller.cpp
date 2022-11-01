/**
    Cpp17 RobotMovement, controller.cpp
    Purpose: Getting commands and asking robot execute them

    @author CuongNX
    @version 1.0 11/1/2022
*/

#include "controller.h"
#include "utility.h"

// Constructor
Controller::Controller()
{
    vector<tuple<string,int, int>> raw_commands = Utility::GetCommand("..\\RobotMovement\\"+sCommandFile);
    if (!raw_commands.empty()){
        convertCmd(raw_commands);
        robot = new Robot(size);

    }
}

// Start to control robot
void Controller::start()
{
    for(auto cmd : commands){
        robot->Handle(cmd);
    }
    if (robot != nullptr) printGrid(robot->RGrid());
}

// Destructor
Controller::~Controller()
{
    delete robot;
}

// Convert raw command with string to command by identify with enum
void Controller::convertCmd(vector<tuple<string, int, int>> raw_commands)
{
    for(auto cmd : raw_commands){
        string raw_cmd = get<0>(cmd);
        tuple<string,int, int> rcmd;
        if (raw_cmd.compare("DIMENSION") == 0) {
            commands.push_back(make_tuple(Robot::DIMENSION, get<1>(cmd), get<2>(cmd)));
            size = get<1>(cmd);
        }
        if (raw_cmd.compare("MOVE_TO") == 0) commands.push_back(make_tuple(Robot::MOVE_TO, get<1>(cmd), get<2>(cmd)));
        if (raw_cmd.compare("LINE_TO") == 0) commands.push_back(make_tuple(Robot::LINE_TO, get<1>(cmd), get<2>(cmd)));
    }
}

// Print grid that describe route that robot passed
void Controller::printGrid(vector<vector<bool>> RGrid)
{
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
            cout << (RGrid[i][j]? "+|" : " |");
        }
        cout << endl;
    }
}
