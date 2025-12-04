#include "../core/Game.h"
#include "../core/Rule.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <filesystem>

using namespace std;

void create_blinker_file() {
    ofstream file("test_blinker.txt"); //Creation of a gid for the tests
    file << "5 5" << endl;
    file << "0 0 0 0 0" << endl;
    file << "0 0 1 0 0" << endl;
    file << "0 0 1 0 0" << endl;
    file << "0 0 1 0 0" << endl;
    file << "0 0 0 0 0" << endl;
    file.close();
}

void test_game_creation() {
    cout << "Test: Creation d'un jeu..." << endl;
    
    create_blinker_file();
    Rule rule;
    Game game("test_blinker.txt", &rule);

    if (game.getIteration()==0){
        cout << "  Le jeu commence bien a la generation 0" << endl;
    } 
    else {
        cout << "  Erreur: le jeu ne commence pas à l'iteration 0" << endl;
    }    

    if (game.getGrid().getRows() == 5 && game.getGrid().getCols() == 5){
        cout << "  Les methodes getRows() et getCols() fonctionnent" << endl;
    } 
    else {
        cout << "  Erreur: la grille ne possede pas les bonnes dimmensions " << endl;
    }
        
    remove("test_blinker.txt"); //Remove the test file to keep the directory clean
}

void test_game_step() {
    cout << "Test: Avancement d'une generation..." << endl;
    
    create_blinker_file();
    Rule rule;
    Game game("test_blinker.txt", &rule);
        
    game.step();

    if (game.getIteration() == 1){
        cout << "  Le jeu a bien avance d'une generation" << endl;
    } 
    else {
        cout << "  Erreur: le jeu n'avance pas correctement" << endl;
    }
    
    game.step();
    game.step();

    if (game.getIteration() == 3){
        cout << "  Le jeu a bien avance de trois generations" << endl;
    } 
    else {
        cout << "  Erreur: le jeu n'avance pas correctement apres plusieurs generations" << endl;
    }

    remove("test_blinker.txt");
}

void test_game_blinker_oscillation() {
    cout << "Test: Verifications des etats apres pluieurs generations... " << endl;
    
    create_blinker_file();
    Rule rule;
    Game game("test_blinker.txt", &rule);
    
    // Après 1 step : horizontal
    game.step();
    if (game.getGrid().getCell(2, 1).isAlive() == true &&
        game.getGrid().getCell(2, 2).isAlive() == true &&
        game.getGrid().getCell(2, 3).isAlive() == true) {
        cout << "  Le blinker passe bien à l'horizontale " << endl;
    } 
    else {
        cout << "  Erreur: Le blinker n'est pas passe a l'horizontale" << endl;
    }
    
    game.step();
    if(game.getGrid().getCell(1, 2).isAlive() == true &&
       game.getGrid().getCell(2, 2).isAlive() == true &&
       game.getGrid().getCell(3, 2).isAlive() == true) {
        cout << "  Le blinker repasse bien à la verticale " << endl;
    } 
    else {
        cout << "  Erreur: Le blinker n'est pas repasse a la verticale" << endl;
    }
        
    remove("test_blinker.txt");
}

void test_game_reset() {
    cout << "Test: Reset du jeu..." << endl;
    
    create_blinker_file();
    Rule rule;
    Game game("test_blinker.txt", &rule);
    
    game.step();
    game.step();
    game.step();

    game.reset();

    if(game.getIteration() == 0) {
        cout << "  La generation est revenue a 0" << endl;
    } 
    else {
        cout << "  Erreur: la generation n'est pas revenue a 0" << endl;
    }
    
    if(game.getGrid().getCell(1, 2).isAlive() == true &&
       game.getGrid().getCell(2, 2).isAlive() == true &&
       game.getGrid().getCell(3, 2).isAlive() == true) {
        cout << "  La grille est revenue a l'etat initial" << endl;
    } 
    else {
        cout << "  Erreur: la grille n'est pas revenue a l'etat initial" << endl;
    }
    
    remove("test_blinker.txt");
}

void test_game_run_console_to_files() {
    cout << "Test: Génération de fichiers..." << endl;
    
    create_blinker_file();
    Rule rule;
    Game game("test_blinker.txt", &rule);

    game.runConsoleToFiles(3, "test_output");
    
    if(filesystem::exists("test_output")) {
        cout << "  Le dossier de sortie a bien ete cree" << endl;
    }
    else {
        cout << "  Erreur: le dossier de sortie n'a pas ete cree" << endl;
    }

    if(filesystem::exists("test_output/generation_0.txt") &&
       filesystem::exists("test_output/generation_1.txt") &&
       filesystem::exists("test_output/generation_2.txt") &&
       filesystem::exists("test_output/generation_3.txt")) {
        cout << "  Les fichiers generes existent bien" << endl;
    } 
    else {
        cout << "  Erreur: les fichiers generes n'existent pas" << endl;
    }
    
    filesystem::remove_all("test_output");
    remove("test_blinker.txt");
}

void run_game_tests() {
    cout << "\n=== Tests Game ===" << endl;
    test_game_creation();
    test_game_step();
    test_game_blinker_oscillation();
    test_game_reset();
    test_game_run_console_to_files();
    cout << "===Tous les tests sont bons===\n" << endl;
}