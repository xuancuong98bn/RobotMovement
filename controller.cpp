/**
    Cpp17 RobotMovement, controller.cpp
    Purpose: Getting commands and asking robot execute them

    @author CuongNX
    @version 1.0 11/1/2022
*/

#include "controller.h"
#include "utility.h"

#include "cmd_dimension.h"
#include "cmd_moveto.h"
#include "cmd_lineto.h"

// Constructor
Controller::Controller()
{
}

// Constructor
Controller::Controller(string commandFile)
{
    vector<tuple<string,int, int>> raw_commands = Utility::GetCommand("..\\RobotMovement\\"+commandFile);
    if (!raw_commands.empty()){
        convertCmd(raw_commands);
        robot = new Robot();
    }
}

// Destructor
Controller::~Controller()
{
    delete robot;
    for(auto cmd : commands){
        delete cmd;
    }
}

// Start to control robot
void Controller::Start()
{
    for(auto cmd : commands){
        cmd->SendTo(robot);
    }
}

// Export the result grid that describe route that robot passed by a type of Output
void Controller::ExportResult(Output* op)
{
    if (robot != nullptr) op->Export(robot->RGrid());
    delete op;
}

// Convert raw command with string to command by identify with enum
void Controller::convertCmd(vector<tuple<string, int, int>> raw_commands)
{
    for(auto cmd : raw_commands){
        string cmd_str = get<0>(cmd);
        if (cmd_str.compare("DIMENSION") == 0) commands.push_back(new CmdDimension(get<1>(cmd)));
        if (cmd_str.compare("MOVE_TO") == 0) commands.push_back(new CmdMoveTo(get<1>(cmd), get<2>(cmd)));
        if (cmd_str.compare("LINE_TO") == 0) commands.push_back(new CmdLineTo(get<1>(cmd), get<2>(cmd)));
    }
}

