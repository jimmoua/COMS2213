#ifndef ISLANDTYPE_H
#define ISLANDTYPE_H

#include "Misc.h"
#include <fstream>
#include <iomanip>
#include <iostream>

class IslandType
{
    public:
                    IslandType(); // Default ctor
        int         getGrid(char *fn);
        OrderedPair start();
        StatusType  check(OrderedPair op);
        void        printBridges();
        void        printGrid();
        void        reset();

    private:
        int         Island[MAX_SIZE][MAX_SIZE];
        OrderedPair Start;
        OrderedPair Bridges[MAX_BRIDGES];
        int         Size;
        int         NumBridges;
};

#endif
