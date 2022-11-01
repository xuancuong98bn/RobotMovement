#ifndef UTILITY_H
#define UTILITY_H

/**
    Cpp17 RobotMovement, utility.h
    Purpose: Stores utitity function for project

    @author CuongNX
    @version 1.0 11/1/2022
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

/**
 * @brief The Utility class stores utitity function for project
 */
class Utility
{
public:

    /**
     * @brief Utility Constructor
     */
    Utility();

    /**
     * @brief GetCommand Get raw commands from source file
     * @param fileName Name of data file
     * @return The vector of tuple that contains raw commands
     *
     * @exceptsafe Error command will be not recorded
     * @exceptsafe Other errors make function to return the empty vector
     */
    static vector<tuple<string,int, int>> GetCommand(string);

    /**
     * @brief Split Split string by a single character delimiter
     * @param s Origin string address
     * @param c Character delimiter address
     * @return The vector of sub-string that split form origin string
     */
    static const vector<string> Split(const string &, const char &);
};

#endif // UTILITY_H
