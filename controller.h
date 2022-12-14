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
#include "rcommand.h"
#include "output.h"
#include "utility.h"

using namespace std;

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
    ~Controller();

    /**
     * @brief LoadCommand Load all command into controller
     * @param commandFile Command file name string
     */
    void LoadCommand(string commandFile);

    /**
     * @brief Start to control robot
     */
    void Start();

    /**
     * @brief ExportResult Export the result grid that describe route that robot passed by a type of Output
     * @param op The object identify type of output to express result
     */
    void ExportResult(Output* op);

private:
    // Robot object pointer
    Robot* robot = nullptr;

    //List of commads for robot execute
    vector<RCommand*> commands;

    /**
     * @brief clearCommand delete pointer and clear command list
     */
    void clearCommand();

    /**
     * @brief convertCmd Convert raw command with string to command by identify with enum
     * @param raw_commands The commands had ready gotten from source file
     */
    void convertCmd(vector<tuple<string,int, int>>);
};

#endif // CONTROLLER_H
