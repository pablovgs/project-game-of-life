#pragma once
#include "Grid.h"
#include "Rule.h"
#include <string>

using namespace std;

class Game {
private:
    Grid grid;
    Rule* rule;
    int iteration;
    string initialFilename;
    
    //Private method
    void saveGridToFile(string filename);

public:
    Game(string filename, Rule* rule);
    ~Game();
    Grid& getGrid();
    int getIteration() const;  
    void step();
    void reset();
    void runConsoleToFiles(int steps, string outputFolder);

};