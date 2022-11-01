#include "controller.h"
#include "utility.h"

Controller::Controller()
{
    vector<tuple<string,int, int>> raw_commands = Utility::GetCommand("..\\RobotMovement\\"+sCommandFile);
    if (!raw_commands.empty()){
        size = get<1>(raw_commands[0]);
        robot = new Robot(size);
        convertCmd(raw_commands);
    }
}

void Controller::start()
{
    for(auto cmd : commands){
        robot->Handle(cmd);
    }
    if (robot != nullptr) printGrid(robot->RGrid());
}

Controller::~Controller()
{
    delete robot;
}

void Controller::convertCmd(vector<tuple<string, int, int>> raw_commands)
{
    for(auto cmd : raw_commands){
        string raw_cmd = get<0>(cmd);
        tuple<string,int, int> rcmd;
        if (raw_cmd.compare("DIMENSION") == 0) commands.push_back(make_tuple(Robot::DIMENSION, get<1>(cmd), get<2>(cmd)));
        if (raw_cmd.compare("MOVE_TO") == 0) commands.push_back(make_tuple(Robot::MOVE_TO, get<1>(cmd), get<2>(cmd)));
        if (raw_cmd.compare("LINE_TO") == 0) commands.push_back(make_tuple(Robot::LINE_TO, get<1>(cmd), get<2>(cmd)));
    }
}

void Controller::printGrid(vector<vector<bool>> RGrid)
{
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
            cout << (RGrid[i][j]? "+|" : " |");
        }
        cout << endl;
    }
}
