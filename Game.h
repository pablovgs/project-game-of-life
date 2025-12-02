#pragma once
#include "Grid.h"
#include "Rule.h"
#include <string>


class Game {
private:
    Grid grid;
    Rule* rule;
    int iteration;
    std::string initialFilename;
    
    //Private method
    void saveGridToFile(std::string filename);

public:
    Game(std::string filename, Rule* rule);
    ~Game();
    Grid& getGrid();
    int getIteration() const;  
    void step();
    void reset();
    void runConsoleToFiles(int steps, std::string outputFolder);

};