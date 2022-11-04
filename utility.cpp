/**
    Cpp17 RobotMovement, utility.cpp
    Purpose: Stores utitity function for project

    @author CuongNX
    @version 1.0 11/1/2022
*/

#include "utility.h"

Utility::Utility()
{

}

// Get raw commands from source file
vector<tuple<string,int, int>> Utility::GetCommand(string fileName)
{
   ifstream ifile;
   vector<tuple<string,int, int>> commands;
   try {
       ifile.open(fileName, ios_base::in);
       if (ifile.is_open()){
           string line;
           while (getline(ifile, line)) {
               try {
                   vector<string> data = Split(line, ' ');
                   vector<string> position = Split(data[1], ',');
                   if (position.size() == 1) position.push_back("0");
                   tuple<string,int, int> command = make_tuple(data[0], stoi(position[0]), stoi(position[1]));
                   commands.push_back(command);
               } catch (...){
                   continue;
               }
           }
       }
   } catch (exception e){
       cerr << e.what() << endl;
       if (ifile.is_open()) ifile.close();
   }
   return commands;
}

// Split string by a single character delimiter
const vector<string> Utility::Split(const string & s, const char & c)
{
    string buff{""};
    vector<string> v;
    for (auto n : s)
    {
        if (n != c) buff += n;
        else if (n == c && buff != "")
        {
            v.push_back(buff);
            buff = "";
        }
    }
    if (buff != "") v.push_back(buff);
    return v;
}
