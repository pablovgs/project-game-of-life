#include "../core/Rule.h"
#include <iostream>
#include <cassert>

using namespace std;

void test_rule_alive_with_2_neighbors() {
    cout << "Test: Cellule vivante avec 2 voisins..." << endl;
    
    Rule rule;
    
    bool result = rule.conwayRule(true, 2);
    if(result == true) {
        cout << "  La cellule survit grace a ses deux voisins vivants" << endl;
    }
    else {
        cout << "  Erreur: la cellule devrait survivre avec deux voisins vivants" << endl;
    }
}

void test_rule_alive_with_3_neighbors() {
    cout << "Test: Cellule vivante avec 3 voisins..." << endl;
    
    Rule rule;
    
    bool result0 = rule.conwayRule(true, 3);
    if(result0 == true) {
        cout << "  La cellule survit grace a ses trois voisins vivants" << endl;
    }
    else {
        cout << "  Erreur: la cellule devrait survivre avec trois voisins vivants" << endl;
    }
}

void test_rule_alive_underpopulation() {
    cout << "Test: Sous-population" << endl;
    
    Rule rule;

    bool result1 = rule.conwayRule(true, 0);
    bool result2 = rule.conwayRule(true, 1);
    if(result1 == false && result2 == false) {
        cout << "  La cellule meurt bien de sous-population" << endl;
    }
    else {
        cout << "  Erreur: la cellule devrait mourir de sous-population" << endl;
    }
}

void test_rule_alive_overpopulation() {
    cout << "Test: Surpopulation..." << endl;
    
    Rule rule;
    
    bool result3 = rule.conwayRule(true, 4);
    bool result4 = rule.conwayRule(true, 5);
    bool result5 = rule.conwayRule(true, 8);

    if(result3 == false && result4 == false && result5 == false) {
        cout << "  La cellule meurt bien de surpopulation" << endl;
    }
    else {
        cout << "  Erreur: la cellule devrait mourir de surpopulation" << endl;
    }
}

void test_rule_dead_with_3_neighbors() {
    cout << "Test: Cellule morte avec 3 voisins..." << endl;
    
    Rule rule;
    
    // Morte avec 3 voisins → naît
    bool result6 = rule.conwayRule(false, 3);

    if(result6 == true) {
        cout << "  La cellule nait bien avec 3 voisins" << endl;
    }
    else {
        cout << "  Erreur: la cellule devrait naitre avec trois voisins" << endl;
    }
}

void test_rule_dead_stays_dead() {
    cout << "Test: Cellule morte reste morte..." << endl;
    
    Rule rule;

    bool result7 = rule.conwayRule(false, 0);
    bool result8 = rule.conwayRule(false, 2);
    bool result9 = rule.conwayRule(false, 4);
    bool result10 = rule.conwayRule(false, 8);

    if(result7 == false && 
        result8 == false && 
        result9 == false && 
        result10 == false) {
        cout << "  La cellule morte reste morte sans 3 voisins vivants" << endl;
    }
    else {
        cout << "  Erreur: la cellule morte devrait rester morte sans trois voisins vivants" << endl;
    }
}

void run_rule_tests() {
    cout << "\n=== Tests Rule ===" << endl;
    test_rule_alive_with_2_neighbors();
    test_rule_alive_with_3_neighbors();
    test_rule_alive_underpopulation();
    test_rule_alive_overpopulation();
    test_rule_dead_with_3_neighbors();
    test_rule_dead_stays_dead();
    cout << "===Tous les tests sont bons===\n" << endl;
}