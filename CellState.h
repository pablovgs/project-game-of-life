#pragma once

class CellState {
protected:
    bool alive;
public:
    CellState(bool alive) : alive(alive) {}
    virtual ~CellState() {}
    bool isAlive() const { return alive; }
};


class AliveState : public CellState {
public:
    AliveState() : CellState(true) {}
};


class DeadState : public CellState {
public:
    DeadState() : CellState(false) {}
};