#pragma once

#include <vector>
#include <string>
#include "Cell.h"

class Grid {
private:
    std::vector<std::vector<Cell>> cells;
    int rows;
    int cols;

public:
    Grid(int rows, int cols);
    void loadFromFile(std::string filename);
    Cell& getCell(int row, int col);
    int countNeighbors(int row, int col);
    int getRows() const;
    int getCols() const;
};

