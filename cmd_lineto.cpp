#include "cmd_lineto.h"

// Construct init value for m_x, m_y
CmdLineTo::CmdLineTo(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}

// Request robot to draw a line
void CmdLineTo::SendTo(Robot *robot)
{
    vector<tuple<int, int>> cells = lineFrom(robot->Position(), robot->RGrid().size());
    robot->Move(m_x, m_y);
    robot->Draw(cells);
}

/* Get cell of the robot when move from current to position (x, y)
 * If line is horizontal -> get a line of cells in horizontal
 * If line is vertical -> get a line of cells in vertical
 * If line is diagonal -> get a line by line equation y = ax + b or x = y/a - b/a
 *  the equation variable depends on slope value > 1 or not
 */
vector<tuple<int, int>> CmdLineTo::lineFrom(tuple<int, int> pos, int size)
{
    vector<tuple<int, int>> cells;
    if (m_x < size && m_y < size){
        double oldX = get<0>(pos);
        double oldY = get<1>(pos);
        if (m_y == oldY) cells = getHLine(oldX, m_x , m_y);
        else if (m_x == oldX) cells = getVLine(m_x, m_y, oldY);
        else {
            //Calculate slope of y -> (y = ax + b)
            oldX += 0.5;
            oldY += 0.5;
            double newX = m_x + 0.5;
            double newY = m_y + 0.5;
            double slope = (newY - oldY)/(double)(newX - oldX);
            double coe = oldY - oldX*slope;
            // if slope y > 1, calculate slope of x -> (x = y/a - b/a)
            if (abs(slope) > 1) {
                coe = -coe/slope;
                slope = 1/slope;
                cells = symmetric(getDLine(oldY, newY, slope, coe));
            } else {
                cells = getDLine(oldX, newX, slope, coe);
            }
        }
    }
    return cells;
}

// Get cells in vertical
vector<tuple<int, int> > CmdLineTo::getVLine(int x, int y1, int y2)
{
    vector<tuple<int, int>> cells;
    if (y1 > y2) swap(y1, y2);
    for(int i = y1; i <= y2; i++){
        tuple t = make_tuple(x, i);
        cells.push_back(t);
    }
    return cells;
}

// Get cells in horizontal
vector<tuple<int, int> > CmdLineTo::getHLine(int x1, int x2, int y)
{
    vector<tuple<int, int>> cells;
    if (x1 > x2) swap(x1, x2);
    for(int i = x1; i <= x2; i++){
        tuple t = make_tuple(i, y);
        cells.push_back(t);
    }
    return cells;
}

// Get cells in diagonal by equation with x is variable
vector<tuple<int, int> > CmdLineTo::getDLine(double oldP, double newP, double slope, double coe)
{
    //calculate list point with double value
    vector<tuple<double, double>> points;
    if (oldP > newP) swap(newP, oldP);
    for(float i = oldP; i <= newP; i++){
        tuple t = make_tuple(i-0.5, (i-0.5)*slope + coe);
        points.push_back(t);
    }
    //convert to list cell
    vector<tuple<int, int>> cells;
    int checkY = floor(get<1>(points[0]));
    for (auto p : points){
        int nx = floor(get<0>(p));
        int ny = floor(get<1>(p));

        //check whether point and cell are duplicates (means that equation pass by integer value)
        //double - int may not have result as zero by floating point, using less than 1e-6 instead of
        if (abs(get<1>(p)-ny) < 1e-6){
            nx += slope < 0 ? -1 : 0;
            checkY = ny;
        }
        tuple<int, int> t = make_tuple(nx, ny);
        cells.push_back(t);

        //check whether current cell and saved cell (checkY) are different
        //(means that equation pass through 2 cells is not by integer value)
        if (ny != checkY){
            tuple<int, int> t2 = make_tuple(nx-1, ny);
            cells.push_back(t2);
            checkY = ny;
        }
    }
    return cells;
}

// Make symmetry the input cells
vector<tuple<int, int> > CmdLineTo::symmetric(vector<tuple<int, int>> line)
{
    vector<tuple<int, int>> res;
    for (auto sq : line){
        res.push_back(make_tuple(get<1>(sq), get<0>(sq)));
    }
    return res;
}
