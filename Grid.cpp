
#include "Grid.h"
#include "AliveState.h"
#include "DeadState.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Grid::Grid(int rows, int cols) : rows(rows), cols(cols) {
    if (rows > 0 && cols > 0) {
        cells.resize(rows, vector<Cell>(cols));
    }
}

int Grid::getRows() const {
    return rows;
}

int Grid::getCols() const {
    return cols;
}

void Grid::loadFromFile(string filename) {
    ifstream fichier(filename);
    
    if (!fichier.is_open()) {
        cout << "Erreur: Impossible d'ouvrir le fichier " << filename << endl;
        return;
    }


    int heigh, width;
    fichier >> heigh >> width;
    
    if (heigh <= 0 || width <= 0) {
        cout << "Erreur: Dimensions invalides" << endl;
        fichier.close();
        return;
    }

    // Change grid size beacause the constructor have default size
    rows = heigh;
    cols = width;
    cells.clear();
    cells.resize(rows, vector<Cell>(cols));

    // Read the digits of the first line and ignore the \n
    string ligne;
    getline(fichier, ligne);
    
    // Read each line of the file except the first one
    for (int i = 0; i < rows; i++) {
        if (!getline(fichier, ligne)) {
            cout << "Erreur: Pas assez de lignes dans le fichier" << endl;
            fichier.close();
            return;
        }
        
        // Remover spaces 
        ligne.erase(remove(ligne.begin(), ligne.end(), ' '), ligne.end());
        
        if (ligne.length() < cols) {
            cout << "Erreur: Ligne " << i << " trop courte" << endl;
            fichier.close();
            return;
        }
        
        //Initialisation of the cells with their state
        for (int j = 0; j < cols; j++) {
            if (ligne[j] == '1') {
                cells[i][j].setState(new AliveState());
            } else {
                cells[i][j].setState(new DeadState());
            }
        }
    }
    
    fichier.close();
}

Cell& Grid::getCell(int row, int col) {
    return cells[row][col];
}

int Grid::countNeighbors(int row, int col) {
    int count = 0;
    // Run through the 3x3 grid around the cell
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            // Ignore the cell itself
            if (i == 0 && j == 0) continue;
            
            int newRow = row + i;
            int newCol = col + j;
            
            // Check boundaries
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                if (cells[newRow][newCol].isAlive()) {
                    count++;
                }
            }
        }
    }
    
    return count;
}


