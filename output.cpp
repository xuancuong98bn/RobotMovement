#include "output.h"

// Constructor
Output::Output()
{

}

// Express result after after robot handled the commands
void Output::Export(vector<vector<bool> > RGrid)
{
    for(int i = 0; i < RGrid.size(); i++){
        for (int j = 0; j < RGrid.size(); j++) {
            cout << (RGrid[i][j]? "+|" : " |");
        }
        cout << endl;
    }
}
