#ifndef OUTPUT_H
#define OUTPUT_H

/**
    Cpp17 RobotMovement, output.h
    Purpose: Represent for output expected to return after control robot

    @author CuongNX
    @version 1.0 11/4/2022
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief The Output class represent for output expected to return after control robot
 * Other output type must inherit this class
 */
class Output
{
public:
    Output();

    /**
     * @brief Export Express result after after robot handled the commands
     * Can be override in derived class to export with other expected result
     * @param RGrid the maxtrix store route after robot handled the commands
     */
    virtual void Export(vector<vector<bool>> RGrid);
};

#endif // OUTPUT_H
