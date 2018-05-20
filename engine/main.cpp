#include "../solver/Solver.hpp"

#include <string>
#include <iostream>
#include <csignal>
#include <algorithm>

#define WIDTH 3
#define LENGTH 5
#define objectx 1
#define objecty 2

#define FOR(k, lb, ub) for (int k = (lb); (k) < (ub); (k)++)

//
// Variables
//

int A[WIDTH][LENGTH];           // A room, house, area...

Solver solver;
vec<Lit> literals;


//
// Initializing all variables
//

void init_A() {
    FOR(i, 0, WIDTH) {
        FOR(j, 0, LENGTH) {
            A[i][j] = solver.newVar();
        }
    }
}

//
// Constraints
//

void constraint_1() {
    literals.clear();
    FOR(i, 0, WIDTH) {
        FOR(j, 0, LENGTH) {
            if (i == objectx and j == objecty){
                literals.push(Lit(A[i][j]));
                solver.addClause(literals);
                literals.clear();
            }
        }
    }
}


//
// Output display
//

void print_state() {
    FOR(i, 0, WIDTH) {
        std::cout << " |";
        FOR(j, 0, LENGTH) {
            if (solver.model[A[i][j]] == l_True) {
                std::cout << "X";
            } else {
                std::cout << "-";
            }
        }
        std::cout << '|' << std::endl;
    }
}

//
// Main
//

int main() {
    // ---------- Variables ---------- //
    init_A();


    // ---------- Constraints ---------- //
    constraint_1();


    // ---------- Solver ---------- //
    printf("\n\n");
    solver.solve();
    printf("\n");


    // ---------- Printer ---------- //
    if (solver.okay()) {
        printf("\nYES\n"); print_state();
    } else {
        printf("\nNO\n");
    }

    // ---------- Printer ---------- //


    // ---------- Delete ---------- //
    return EXIT_SUCCESS;
}
