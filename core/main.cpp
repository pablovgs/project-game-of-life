#include "Game.h"
#include "Rule.h"
#include "../GUI/GameGraphics.h"
#include "../test/run_all_tests.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    
    // Help message 
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <fichier_grille> [mode] [options]" << endl;
        cout << "  -Pour console: " << argv[0] << " fichier.txt console <nb_steps>" << endl;
        cout << "  -Pour graphics: " << argv[0] << " fichier.txt graphics" << endl;
        cout << "  -Pour les tests unitaires: " << argv[0] << " test" << endl;
        return 1;
    }
    

    if (string(argv[1]) == "test") {
        cout << "Mode test" << endl;
        runAll();
        return 0;
    }

    cout << "==========Conway's Game of Life==========" << endl << endl;

    string filename = argv[1];
    
    string mode;
    if (argc >= 3) {
        mode = argv[2];    
    } else {
        mode = "graphics";
    }
    
    
    Rule conwayRule;
    Game game(filename, &conwayRule);
    
    if (mode == "console") { // Console mode
        if (argc < 4) {
            cout << "Erreur: Vous devez fournir un nombre de générations" << endl;
            cout << "Usage: " << argv[0] << " " << filename << " console <nb_steps>" << endl;
            return 1;
        }
        
        int steps = atoi(argv[3]);   
        
        if (steps <= 0) {
            cout << "Erreur: Le nombre de générations doit être positif" << endl;
            return 1;
        }
        
        size_t pos = filename.find_last_of('.'); //Find the position of the last dot
        string basename;
        if (pos != string::npos) {
            basename = filename.substr(0, pos);
        } 
        else {
            basename = filename;
        }
        string outputFolder = basename + "_out";
        
        cout << "Mode console: " << steps << " générations" << endl;
        game.runConsoleToFiles(steps, outputFolder);
    } 

    else { // Graphics mode
        cout << "Mode graphique" << endl;
        GameGraphics graphics(game, 800, 940);
        graphics.run();
    }
    

    return 0;
}