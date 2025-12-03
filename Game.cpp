#include "Game.h"
#include <fstream> // Read and Write files
#include <iostream>
#include <filesystem> //Create directory

using namespace std;


Game::Game(string filename, Rule* rule) :
    grid(0, 0), rule(rule), iteration(0), initialFilename(filename) {
    grid.loadFromFile(filename);
}

Game::~Game() {}

// Reset the game
void Game::reset() {
    grid.loadFromFile(initialFilename);
    iteration = 0;
}

//Getters
Grid& Game::getGrid() {
    return grid;
}
int Game::getIteration() const {
    return iteration;
}

//Step by-step simulation
void Game::step() {
        for (int i = 0; i < grid.getRows(); i++) {
        for (int j = 0; j < grid.getCols(); j++) {
            int neighbors = grid.countNeighbors(i, j);
            bool currentState = grid.getCell(i, j).isAlive();
            bool nextState = rule->conwayRule(currentState, neighbors);
            
            if (nextState) {
                grid.getCell(i, j).prepareNext(new AliveState());
            } else {
                grid.getCell(i, j).prepareNext(new DeadState());
            }
        }
    }
    
    // Phase 2 : Appliquer tous les changements
    for (int i = 0; i < grid.getRows(); i++) {
        for (int j = 0; j < grid.getCols(); j++) {
            grid.getCell(i, j).update();
        }
    }
    
    iteration++;
}



void Game::runConsoleToFiles(int steps, string outputFolder) {}




void Game::saveGridToFile(string filename) {}
