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

// Destructor
Controller::~Controller()
{
    if (robot != nullptr) delete robot;
    clearCommand();
}

// Load all command into controller
void Controller::LoadCommand(string commandFile)
{
    vector<tuple<string,int, int>> raw_commands = Utility::GetCommand("..\\RobotMovement\\"+commandFile);
    if (!raw_commands.empty()){
        if (robot == nullptr) robot = new Robot();
        clearCommand();
        convertCmd(raw_commands);
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

// Delete pointer and clear command list
void Controller::clearCommand()
{
    for(auto cmd : commands){
        delete cmd;
    }
    if (!commands.empty()) commands.clear();
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

