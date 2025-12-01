#pragma once

#include <vector>
#include <string>
#include "Cell.h"

using namespace std;

class Grid {
private:
    vector<vector<Cell>> cells;
    int rows;
    int cols;

public:
    Grid(int rows, int cols);
    void loadFromFile(string filename);
    Cell& getCell(int row, int col);
    int countNeighbors(int row, int col);
    int getRows() const;
    int getCols() const;
};

