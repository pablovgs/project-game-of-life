#include "CellState.h"

CellState::CellState(bool alive) : alive(alive) {}

CellState::~CellState() {}

bool CellState::isAlive() const {
    return alive;
}

