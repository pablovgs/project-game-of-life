#include "run_all_tests.h"

void runAll(){
    run_cell_tests();
    run_cellstate_tests();
    run_game_tests();
    run_grid_tests();
    run_rule_tests();
}