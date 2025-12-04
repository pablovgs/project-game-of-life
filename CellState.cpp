#include "CellState.h"

CellState::CellState(bool alive) : alive(alive) {} // Constructor with parameter

CellState::~CellState() {} // Virtual destructor

bool CellState::isAlive() const { 
    return alive; // Return the alive status
}

