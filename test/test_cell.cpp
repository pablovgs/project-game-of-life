#include "../core/Cell.h"
#include "../core/AliveState.h"
#include "../core/DeadState.h"
#include <iostream>
#include <cassert>

using namespace std;

void test_cell_creation() {
    cout << "Test: Creation d'une cellule..." << endl;
    
    Cell cell;

    if (cell.isAlive() == false) {
        cout << "  Cellule cree avec le bon etat ( mort par default)" << endl;
    } 
    else {
        cout << "  Erreur dans la creation de la cellule" << endl;

    }
}

void test_cell_set_state() {
    cout << "Test: Changement d'etat d'une cellule..." << endl;
    
    Cell cell;
    
    // Rendre vivante
    cell.setState(new AliveState());

    if (cell.isAlive() == true) {
        cout << "  La Cell est devenue vivante" << endl;
    } 
    else {
        cout << "  Erreur dans le changemnt d'etat" << endl;

    }
    
    cell.setState(new DeadState());
    if(cell.isAlive() == false) {
        cout << "  La Cell est devenue morte" << endl;
    } 
    else {
        cout << "  Erreur dans le changemnt d'etat" << endl;

    }
    
    cout << "  Tout les changements d'etat possible dans setState() fonctionne" << endl;
}

void test_cell_prepare_and_update() {
    cout << "Test: Preparation et mise a jour..." << endl;
    
    Cell cell;
    cell.setState(new DeadState());
    
    cell.prepareNext(new AliveState());
    if (cell.isAlive() == false) {
        cout << "  La cellule est toujours morte avant update()" << endl;
    } 
    else {
        cout << "  Erreur: La cellule ne devrait pas encore avoir change d'état" << endl;

    }
    
    cell.update();
    if(cell.isAlive() == true) {
        cout << "  La cellule est maintenant vivante apres update()" << endl;
    } 
    else {
        cout << "  Erreur: La cellule devrait être vivante apres update()" << endl;

    }
    
    cout << "  Les methodes prepareNext() et update() fonctionnent" << endl;
}

void test_cell_copy_constructor() {
    cout << "Test: Constructeur de copie..." << endl;
    
    Cell cell1;
    cell1.setState(new AliveState());
    
    Cell cell2(cell1);  // Copie
    
    if(cell2.isAlive() == true) {
        cout << "  La cellule copiee est vivante comme l'originale" << endl;
    } 
    else {
        cout << "  Erreur: La cellule copiee devrait etre vivante" << endl;

    }
    
    // Vérifier que ce sont des copies indépendantes
    cell1.setState(new DeadState());
    if(cell1.isAlive() == false && cell2.isAlive() == true) {
        cout << "  Les cellules sont independantes apres la copie" << endl;
    } 
    else {
        cout << "  Erreur: Les cellules ne sont pas independantes après la copie" << endl;

    }    
    cout << "  Le constructeur par copie fonctionne" << endl;
}

void run_cell_tests() {
    cout << "\n=== Tests Cell ===" << endl;
    test_cell_creation();
    test_cell_set_state();
    test_cell_prepare_and_update();
    test_cell_copy_constructor();
    cout << "===Tous les tests sont bons===\n" << endl;
}