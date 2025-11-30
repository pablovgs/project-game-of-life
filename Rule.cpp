#include "Rule.h"

bool Rule::conwayRule(bool currentState, int neighbors) {
    
    bool newState = false;
    
    if (currentState) {
        if (neighbors == 2 || neighbors == 3) {
            newState = true; 
        }

    }

    else {

        if (neighbors == 3) {
            newState = true; 
        }     
    }
    
    return newState;
}