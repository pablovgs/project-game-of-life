#pragma once 
#include "CellState.h"

class Cell {
private:
    CellState* state;
    CellState* nextState;
    
public:
    Cell();
    Cell(const Cell& other);  
    ~Cell();
    bool isAlive() const;
    void setState(CellState* newState);
    void prepareNext(CellState* newState);
    void update();
};


