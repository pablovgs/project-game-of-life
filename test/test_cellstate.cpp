#include "../core/CellState.h"
#include "../core/AliveState.h"
#include "../core/DeadState.h"
#include <iostream>
#include <cassert>

using namespace std;

void test_cellstate_creation() {
    cout << "Test: Creation des etats..." << endl;    
    AliveState alive;
    DeadState dead;
    
    if (alive.isAlive() == true && dead.isAlive() == false) {
        cout << "  Les etats sont bon" << endl;
    } 
    else {
        cout << "  Erreur dans la creation des etats" << endl;
    }
}

void test_cellstate_polymorphism() {
    cout << "Test: Polymorphisme des etats..." << endl;    
    CellState* state1 = new AliveState();
    CellState* state2 = new DeadState();
    
    if (state1->isAlive() == true && state2->isAlive() == false) {
        cout << "  Le polymorphisme fonctionne" << endl;
    } 
    else {
        cout << "  Erreur dans le polymorphisme des etats" << endl;
    }
    
    delete state1;
    delete state2;
    
}

void run_cellstate_tests() {
    cout << "\n=== Tests CellState ===" << endl;
    test_cellstate_creation();
    test_cellstate_polymorphism();
    cout << "===Tous les tests sont bons===\n" << endl;
}