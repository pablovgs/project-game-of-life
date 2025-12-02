#include "Cell.h"
#include "CellState.h"


Cell::Cell() : state(new DeadState()), nextState(nullptr) {}

Cell::~Cell() {
    delete state;
    if (nextState != nullptr) {
        delete nextState;
    }
}

bool Cell::isAlive() const {
    return state->isAlive();
}

void Cell::setState(CellState* newState) {
    delete state;
    state = newState;
}

void Cell::prepareNext(CellState* newState) {
    if (nextState != nullptr) {
        delete nextState;
    }
    nextState = newState;
}

void Cell::update() {
    if (nextState != nullptr) {
        delete state;
        state = nextState;
        nextState = nullptr;
    }
}