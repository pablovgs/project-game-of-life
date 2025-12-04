#include "Rule.h"

bool Rule::conwayRule(bool currentState, int neighbors) {
    
    bool newState = false;
    
    if (currentState) { //Stay alive condition
        if (neighbors == 2 || neighbors == 3) {
            newState = true; 
        }

    }

    else { //Birth condition

        if (neighbors == 3) {
            newState = true; 
        }     
    }
    
    return newState;
}