#ifndef MISC_H
#define MISC_H

#include <iostream>

const int NUM_SIMS = 1000;  // Number of simulations to run
const int MAX_SIZE = 20;    // Max grid size
const int MIN_SIZE = 3;     // Minimum grid size
const int MAX_MOVES = 100;  // Max mouse moves
const int MAX_BRIDGES = 10; // Max bridges
const int MIN_BRIDGES = 2;  // Min bridges


enum StatusType { ALIVE, DROWNED, ESCAPED, STARVED };

struct OrderedPair
{
    int row;
    int col;
};

std::ostream &operator<<(std::ostream& os, OrderedPair op);

#endif
