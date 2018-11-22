#include "Misc.h"

/** Function: operator<<(std::ostream&, OrderedPair) *******
 *  Description: This function is an operator overload func-
 *  tion. Its LHS parameter is an std::ostream while its RHS
 *  parameter is an object of the struct OrderedPair.
 *
 *  The function returns the pieces that are stored into the
 *  os object.
 * ********************************************************/
std::ostream & operator<<(std::ostream& os, OrderedPair op)
{
    os << '(' << op.row << ", " << op.col << ')';
    return os;
}

