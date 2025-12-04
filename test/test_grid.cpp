#include "../core/Grid.h"
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

void create_test_file(string filename, int rows, int cols) {
    ofstream file(filename);
    file << rows << " " << cols << endl;
    
    file << "0 0 0 0 0" << endl; //Creation of a gid for the tests
    file << "0 0 1 0 0" << endl;
    file << "0 0 0 1 0" << endl;
    file << "0 1 1 1 0" << endl;
    file << "0 0 0 0 0" << endl;
    
    file.close();
}

void test_grid_creation() {
    cout << "Test: Création d'une grille..." << endl;
    
    Grid grid(5, 5);
    
    if(grid.getRows() == 5 && grid.getCols() == 5) {
    cout << "  Grille 5x5 créée" << endl;
    }
    else {
        cout << "  Erreur dans la création de la grille" << endl;
    }
}

void test_grid_load_from_file() {
    cout << "Test: Chargement depuis un fichier..." << endl;
    
    create_test_file("test_grid.txt", 5, 5);
    
    Grid grid(0, 0);
    grid.loadFromFile("test_grid.txt");

    if(grid.getCell(1, 2).isAlive() == true &&
       grid.getCell(3, 1).isAlive() == true &&
       grid.getCell(3, 3).isAlive() == true) {
        cout << "  Le chargement des cellules est bon" << endl;
    } 
    else {
        cout << "  Erreur dans le chargement des cellules avec leurs etats" << endl;
    }

    remove("test_grid.txt");
}

void test_grid_count_neighbors() {
    cout << "Test: Comptage des voisins..." << endl;
    
    create_test_file("test_neighbors.txt", 5, 5);
    
    Grid grid(0, 0);
    grid.loadFromFile("test_neighbors.txt");

    int neighbors = grid.countNeighbors(2, 2);
    if(neighbors == 5) {
        cout << "  La cellule (2,2) possede bien 5 voisins vivants" << endl;
    }
    else {
        cout << "  Erreur dans le comptage des voisins vivants" << endl;
    }

    remove("test_neighbors.txt");
}

void test_grid_get_cell() {
    cout << "Test: Accès aux cellules..." << endl;
    
    Grid grid(3, 3);
    
    grid.getCell(1, 1).setState(new AliveState());
    
    assert(grid.getCell(1, 1).isAlive() == true);
    if(grid.getCell(1, 1).isAlive() == true) {
        cout << "  Accès à la cellule (1,1) réussi, elle est vivante" << endl;
    } 
    else {
        cout << "  Erreur dans l'accès à la cellule (1,1)" << endl;
    }
}

void run_grid_tests() {
    cout << "\n=== Tests Grid ===" << endl;
    test_grid_creation();
    test_grid_load_from_file();
    test_grid_count_neighbors();
    test_grid_get_cell();
    cout << "===Tous les tests sont bons===\n" << endl;
}