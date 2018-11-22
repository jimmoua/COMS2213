#include "MouseType.h"

/** Function: MouseType::MouseType() ***********************
 *  Description: This is the default constructor of the
 *    MouseType class. It's empty because it isn't used for
 *    anything.
 * ********************************************************/
MouseType::MouseType()
{
    // Default ctor...
}

/** Funciton: MouseType::move(IslandType &, int) ***********
 *  Description: This function moves the mouse. In this fun-
 *    ction, we are just manipulating the indexes of 2-D
 *    array from the IslandType.h. For example, take a look
 *    at examplel map below and take into consideration the
 *    location of the mouce, which is defined as a value of
 *    1.
 *
 *    -1  -1  -1  -1  -1  -1
 *    -2   0   0   0   0  -1
 *    -1   0   0   0   0  -2
 *    -1   0   0   1   0  -2
 *    -1   0   0   0   0  -1
 *    -1  -1  -2  -2  -1  -1
 *
 *    If decided to move the mouse "up", we would simply be
 *    changing an value at a particular index.
 *
 *    -1  -1  -1  -1  -1  -1
 *    -2   0   0   0   0  -1
 *    -1   0   0   1   0  -2
 *    -1   0   0   1   0  -2
 *    -1   0   0   0   0  -1
 *    -1  -1  -2  -2  -1  -1
 *
 *    After the move has moved, it will now have traversed
 *    to two different location: the inital and "up" 1 unit.
 *
 *    If the mouse moves again back to its original location
 *    we will increment the value of that already visited
 *    location so the map would then look something like
 *    this:
 *
 *    -1  -1  -1  -1  -1  -1
 *    -2   0   0   0   0  -1
 *    -1   0   0   1   0  -2
 *    -1   0   0   2   0  -2    <-- There is a value 2 in
 *    -1   0   0   0   0  -1        this row, indiciating
 *    -1  -1  -2  -2  -1  -1        this area has been
 *                                  visited twice.
 *
 *  Preconditions:
 *      Before this function is called, it seems that the
 *        max number of moves of the has not been reached or
 *        that the mouse status is still alive. This number
 *        is represented as a contant named MAX_MOVES in the
 *        Misc.h file. 
 *
 *  Postconditions:
 *      This function modifies the value MouseType::Moves.
 *        It also modifies the status of the mouse, but only
 *        if MouseType::Moves is the same value of MAX_MOVES
 *        in the Misc.h file. If it is the same value of the
 *        MAX_MOVES, then this function will change the
 *        status of the mouse to STARVED and end the nth
 *        simulation.
 *        As well as modifying the number of moves that the
 *        mouse has taken, this function also modifies the
 *        loction of the mouse, which is the OrderedPair
 *        MouseType::Location
 *  *******************************************************/
void MouseType::move(IslandType &IslandTypeObj, int direction)
{
    Moves++;
    /* Define some directions... Since four possible  movement types...
     * Let 1 = Up
     *     2 = Left
     *     3 = Down
     *     4 = Right */
    if(direction  == 1)
    {
        // Moving up
        Location.row--;
    }
    else if(direction == 2)
    {
        // Moving left
        Location.col--;
    }
    else if(direction == 3)
    {
        // Moving down
        Location.row++;
    }
    else if(direction == 4)
    {
        // Moving right
        Location.col++;
    }

    /* Here, we are chekcing to see if the mouse starved or not.
     * If the mouse starved, the function will simply change the 
     * mouse status to starved. Otherwise, it will invoke the function
     * IslandType::Check(OrderedPair) to see whether the mouse has
     * landed on a water tile, land tile, or bridge tile. */
    if(Moves == MAX_MOVES)
        Status = StatusType::STARVED;
    else
        Status = IslandTypeObj.check(Location);
}

/** Function: MouseType::reset(OrderedPair) ****************
 *  Description: This function is called when the map is
 *  being reset. It resets the mouse location and its status
 *  to alive so another simulation is ran. The parameter in
 *  the function is the start location of the mouse, which
 *  is obtained from IslandType::start(). It also resets
 *  the number of moves the mouse has moved since another
 *  simulation has started.
 *
 *  Preconditions:
 *      This function is only ran if the status of the mouse
 *        is no longer alive and the number of simulations
 *        has not been maxed out to equal the value of 
 *        NUM_SIMS in the file Misc.h.
 *
 *  Postconditions:
 *      This function will modify the location of the mouse
 *        to be equal to the value in which the program had
 *        originally read the mouse values to be. The
 *        original values of the mouse starting position
 *        is stored in the OrderedPair IslandType::Start.
 *        The OrderedPair IslandType::Start is passed as a
 *        parameter into this function, which is named op.
 *        This function will also set the mouse back to the
 *        status of alive and reset the Moves counter back
 *        to 0 so another simulation can be ran.
 *  *******************************************************/
void MouseType::reset(OrderedPair op)
{
    // op == OrderedPair IslandType::Start
    Location = op;
    Status = StatusType::ALIVE;
    Moves = 0;
}

/** Function: MouseType::status() **************************
 *  Description: This returns the value of the private enum
 *  in the class, which is the status of the mouse.
 *
 *  Preconditions:
 *      The only way this function is ran is if the function
 *      IslandType::getGrid(char *) is ran successfully and
 *      does not return any error codes.
 *
 *  Postconditions:
 *      This function does not modify anything.
 * ********************************************************/
StatusType MouseType::status()
{
    return this->Status;
}


/** Function: MouseType::moves() ***************************
 *  Description: This function returns the total number of
 *  moves the mouse has made since simulation n has started.
 *  Its value is reset everytime a new simulation is ran.
 *
 *  Preconditions:
 *      This function can only be ran if the function
 *        IslandType::getGrid(char *) is ran successfully.
 *
 *  Postconditions:
 *      This function does not modify anything.
 *      
 * ********************************************************/
int MouseType::moves()
{
    return Moves;
}

/** Function: MouseType::position() ************************
 *  Description: This function returns the current location
 *  of the mouse.
 *
 *  Preconditions:
 *      This function is ran if the function
 *        IslandType::getGrid(char*) is ran successfully.
 *
 *  Postconditions:
 *      This function does not modify anything.
 * ********************************************************/
OrderedPair MouseType::position()
{
    return Location;
}
