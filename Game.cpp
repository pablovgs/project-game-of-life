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
void Game::step() {}



void Game::runConsoleToFiles(int steps, string outputFolder) {}




void Game::saveGridToFile(string filename) {}
