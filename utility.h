#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

class Utility
{
public:

    Utility();
    static bool CheckExistingFileAnData(string);
    static vector<tuple<string,int, int>> GetCommand(string);
    static const vector<string> Split(const string &, const char &);
};

#endif // UTILITY_H
