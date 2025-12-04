#include "Game.h"
#include "Rule.h"
#include "GameGraphics.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    cout << "==========Conway’s Game of Life==========" << endl << endl;
    
    // Help message 
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <fichier_grille> [mode] [options]" << endl;
        cout << "  mode: console ou graphics (défaut: graphics)" << endl;
        cout << "  Pour console: " << argv[0] << " fichier.txt console <nb_steps>" << endl;
        cout << "  Pour graphics: " << argv[0] << " fichier.txt graphics" << endl;
        return 1;
    }
    
    string filename = argv[1];
    string mode = (argc >= 3) ? argv[2] : "graphics";
    
    // Create the rule
    Rule conwayRule;

    // Create the game
    Game game(filename, &conwayRule);
    
    if (mode == "console") { //Console mode
        int steps = (argc >= 4) ? atoi(argv[3]) : 10;
        
        size_t pos = filename.find_last_of('.');
        string basename = (pos != string::npos) ? filename.substr(0, pos) : filename;
        string outputFolder = basename + "_out";
        
        cout << "Mode console " << endl;
        cout << "Simulation de " << steps << " générations..." << endl;
        cout << "Résultats dans le dossier: " << outputFolder << "/" << endl << endl;
        
        game.runConsoleToFiles(steps, outputFolder);
        
        
    } else { //Graphics mode
        GameGraphics graphics(game, 800, 940);
        graphics.run();
    }
    
    return 0;
}