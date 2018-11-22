#ifndef MOUSETYPE_H
#define MOUSETYPE_H

#include "Misc.h"
#include "IslandType.h"

class MouseType
{
    public:
                    MouseType();    // Default ctor
        void        move(IslandType &, int);
        void        reset(OrderedPair);        // Resets mouse pos
        int         moves();        // Returns Moves
        OrderedPair position();     // (x,y) coordinated of the mouse -> stored in struct
        StatusType  status();       // Returns Status of the mouse.
    private:
        OrderedPair Location;
        StatusType  Status;
        int         Moves;          // Keeps track of how many times the mouse have moved
};

#endif
