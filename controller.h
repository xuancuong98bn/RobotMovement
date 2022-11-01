#ifndef CONTROLLER_H
#define CONTROLLER_H

/**
    Cpp17 RobotMovement, controller.h
    Purpose: Getting commands and asking robot execute them

    @author CuongNX
    @version 1.0 11/1/2022
*/

#include <string>

#include "robot.h"

using namespace std;

// Store name of command file
static const string sCommandFile = "input2.txt";

/**
 * @brief The Controller class is responsible for getting commands and asking robot execute them
 */
class Controller
{
public:
    /**
     * @brief Controller Constructor
     */
    Controller();

    /**
     * @brief start Start to control robot
     */
    void start();

    ~Controller();
private:
    // Store size of grid
    int size;

    // Robot object pointer
    Robot* robot;

    //List of commads for robot execute
    vector<tuple<Robot::RCmd,int, int>> commands;

    /**
     * @brief convertCmd Convert raw command with string to command by identify with enum
     * @param raw_commands The commands had ready gotten from source file
     */
    void convertCmd(vector<tuple<string,int, int>>);

    /**
     * @brief printGrid Print grid that describe route that robot passed
     * @param RGrid The matrix saved route that robot passed
     */
    void printGrid(vector<vector<bool>>);
};

#endif // CONTROLLER_H
