#include "Cell.h"
#include "CellState.h"
#include "AliveState.h"
#include "DeadState.h"


Cell::Cell() : state(new DeadState()), nextState(nullptr) {}

Cell::Cell(const Cell& other) : nextState(nullptr) {
    if (other.state->isAlive()) {
        state = new AliveState();
    } else {
        state = new DeadState();
    }
    
    if (other.nextState != nullptr) {
        if (other.nextState->isAlive()) {
            nextState = new AliveState();
        } else {
            nextState = new DeadState();
        }
    }
}

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