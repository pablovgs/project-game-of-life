#include "Cell.h"
#include "CellState.h"
#include "AliveState.h"
#include "DeadState.h"


Cell::Cell() : state(new DeadState()), nextState(nullptr) {} // Default constructor initializes cell as dead

Cell::Cell(const Cell& other) : nextState(nullptr) { //Constructor by copy
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

Cell::~Cell() { //Destructor
    delete state;
    if (nextState != nullptr) {
        delete nextState;
    }
}

bool Cell::isAlive() const { //Check if the cell is alive
    return state->isAlive();
}

void Cell::setState(CellState* newState) { //Set the current state of the cell
    delete state;
    state = newState;
}

void Cell::prepareNext(CellState* newState) { //Prepare the next state of the cell
    if (nextState != nullptr) {
        delete nextState;
    }
    nextState = newState;
}

void Cell::update() { //Update the cell to its next state
    if (nextState != nullptr) {
        delete state;
        state = nextState;
        nextState = nullptr;
    }
}