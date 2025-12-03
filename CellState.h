#pragma once

class CellState {
protected:
    bool alive;

public:
    CellState(bool alive);
    virtual ~CellState();
    bool isAlive() const;
};
