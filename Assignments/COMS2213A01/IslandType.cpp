#include "IslandType.h"

/* Define the types of tiles there are here... */
const signed short int l_tileTypeBRIDGE = -2;
const signed short int l_tileTypeWATER  = -1;
const signed short int l_tileTypeLAND   =  0;
const signed short int l_tileTypeMOUSE  =  1;

/** Function: IslandType::IslandType() *********************
 *  Description:
 *      This is the default constructor of the class
 *        IslandType. It sets the value of NumBridge to 0
 *        because the check function will be incrementing
 *        it by doing NumBridges++
 *
 *  Preconditions:
 *      Is called when an object of the class is
 *        instantiated.
 *
 *  Postconditions:
 *      Sets the values of NumBridge to 0 so the program
 *        increments it properly while counting the number
 *        of bridges found inside the map file.
 * ********************************************************/
IslandType::IslandType()
{
    NumBridges = 0;
}

/** Function: IslangType::start() **************************
 *  Description:
 *      This is a simple function that returns the
 *        private OrderePair called 'Start'
 *
 *  Preconditions:
 *      This function is called if the program is given
 *        a valid map file.
 *
 *  Postconditions:
 *      This function does not modify anything.
 * ********************************************************/
OrderedPair IslandType::start()
{
    return Start;
}

/** Function: IslandType::printBridges() *******************
 *  Description:
 *      This function prints out the bridges by overloading
 *        the << operator. The bridge locations are printed
 *        in a Cartesian-like manner.
 *
 *  Preconditions:
 *      If this function is called, the program was fed
 *        a valid map file. While the program validated the
 *        map file in Island::getGrid(char *), it also found
 *        the locations of the bridges and created ordered
 *        pairs out of them based on the values of their
 *        indexes when stored into the double array
 *        IslandType::Island[][].
 *
 *  Postconditions:
 *      The function does not modify anything. It simple
 *        prints to the output coordinate pairs of the
 *        bridges in the map file.
 * ********************************************************/
void IslandType::printBridges()
{
    for(size_t i = 0; i < NumBridges; i++)
    {
        std::cout << "Bridge " << std::right << std::setw(2) << i+1 << " is at: " << Bridges[i];
        std::cout << std::endl;
    }
}

/** Function: IslandType::printGrid() **********************
 *  Description:
 *      This function will output whatever the grid is. How-
 *        ever, because the grid is going to be printed in
 *        such a way that the bridge, water, and unvisited
 *        areas represented different characters, the funct-
 *        ion checks each individual tile in the 2-D array
 *        to see if it is a certain tile. If it is a certain
 *        tile, the program outputs what character or letter
 *        that certain tile needs to represent.
 *
 *  Preconditions:
 *      The function IslandType::printGrid() is similar to
 *        the function IslandType::printBridges(). Before
 *        this function is ran, it already knows the values
 *        if IslandType::Island[][].
 *
 *  Postconditions:
 *      This function does not modify anything.
 * ********************************************************/
void IslandType::printGrid()
{
    for(size_t i = 0; i < Size; i++)
    {
        for(size_t k = 0; k < Size; k++)
        {   
            /* In these if-else statements, we are checking to see what type of
             * tile the map at [i][k] is. If it is a certain tile, we want to display
             * a certain thing to represent type of tile it is rather than displaying
             * its numerical. The whole point of this is that it makes it look pretty to the eye. */
            if(Island[i][k] == l_tileTypeWATER)
                std::cout << std::right << std::setw(3) << '~';
            else if(Island[i][k] == l_tileTypeBRIDGE)
                std::cout << std::right << std::setw(3) << 'B';
            else if(Island[i][k] == l_tileTypeLAND)
                std::cout << std::right << std::setw(3) << '.';
            else
                std::cout << std::right << std::setw(3) << Island[i][k];
        }
        std::cout << std::endl;
    }
}

/** Function: IslandType::reset() **************************
 *  Description:
 *      This function will "reset" the grid so that all the
 *        values of the array IslandType::Island[][] are set
 *        back to its original, which are the values that
 *        were read in from the file during the function
 *        IslandType::getGrid(char *).
 *
 *  Preconditions:
 *      This function is ran if the number of simulations
 *        does not exceed the value of NUM_SIMS from the
 *        Misc.h file.
 *
 *  Postconditions:
 *      The bridge values will be reseted back to the origi-
 *      al values. This means that the mouse starting locat-
 *      ion will be reset back to its original starting loc-
 *      ation and all areas visited by the mouse will be set
 *      back to 0 to indicate the mouse 
 * ********************************************************/
void IslandType::reset()
{
    for(size_t i = 0; i < Size; i++)
    {
        for(size_t k = 0; k < Size; k++)
        {
            if(Island[i][k] >= 1)
            {
                Island[i][k] = 0;   // If this denotes any value >= 1, reset the map back to 0
            }
        }
    }

    /* The above double for loop had just cleared the map of everything
     *   except those of bridge and water. Now, we go back and grab the
     *   initial mouse starting location and set a value to it inside
     *   the map to denote that that location is where the mouse is
     *   going to start once the map is reseted. */
    Island[Start.row][Start.col] = 1;
}

/** Function: IslandType::GetGrid(char *) ******************
 *  Description:
 *      This function will verify the integrity of the map
 *        file that is fed into the program as a command
 *        line argument. The data char pointer is the file-
 *        name of the map file the program is given. This
 *        function is called inside main(). If the provided
 *        map file is not set up correctly, the function
 *        will return values back to the function main()
 *        which indicate error codes. main() will then show
 *        in the console what the error was, and the program
 *        will terminate until it's given a valid map file.
 *  
 *  Preconditions:
 *      The program must be given a valid map file.
 *
 *  Postconditions:
 *      This function modifies various variables. 
 * ********************************************************/
int IslandType::getGrid(char *fn)
{
    /* Declare some const variables to denote return codes for error checking */
    const int UNABLE_OPEN_FILE = 1;
    const int MISSING_INCORRECT_GRID_SIZE =  2;
    const int MISSING_MOUSE_STARTING_LOC = 3;
    const int TOO_MANY_MOUSE_LOC = 4;
    const int MISSING_BRIDGE = 5;
    const int TOO_MANY_BRIDGES = 6;
    const int INCOMPLETE_GRID = 7;
    const int GRID_TOO_MUCH_INFO = 8;
    const int FILE_IS_EMPTY = 9;
    
    /* We are declaring two variables so we can do some simple error checking.
     * Never should any of these indentifiers be negative, since they count starting
     * from 0.
     *
     * l_totalGridArea is incremented everytime the std::ifstream object is able to read in
     *   a value without any issues.
     *
     * l_mouseCounter is incremented everytime the std::ifstream objects reads in the value
     * that represented the mouse, which is the value of 1. There will be checking at the
     * end of the function. If this counter is greater than 1, the return code will be the
     * return code that indicated there are too many mice in the map. */
    unsigned short int l_totalGridArea = 0;
    unsigned short int l_mouseCounter = 0;
    
    std::ifstream infile;   // Create the std::ifstream object that allows for file reading.
    infile.open(fn);
    if(!infile)
    {
        return UNABLE_OPEN_FILE;   // Return code 1 = can't open file.
    }
    else // If can open file...
    {
        // First, check if the file is empty. If it is, the function returns 9 which indicates empty file.
        
        infile >> Size;// This line reads in the specified size of the grid
        if(!infile)
        {
            if(infile.eof())
                return FILE_IS_EMPTY;
            else
                /* If infile inserts something that doesn't fit data type for Island::Size, return error code */
                return MISSING_INCORRECT_GRID_SIZE; 
        }
        else
            infile.ignore();

        // If bad read bit or Size is too large/small...
        if(!infile or Size > MAX_SIZE or Size < MIN_SIZE)
        {
            return MISSING_INCORRECT_GRID_SIZE; // Return code 2 = Requirements of grid size is not met.
        }

        /* The following declares and initializes two identifiers of type size_t. They both keep track of indexes of the Island array.
         * Inside the while loop, we are continuously reading the from the file into the array. */
        size_t i = 0; // Index of rows
        size_t k = 0; // Index of col
        while(infile.peek() != '\0' and !infile.eof())
        {
            infile >> Island[i][k];
            if(!infile)
                return MISSING_INCORRECT_GRID_SIZE; 
            else
                infile.ignore();
            l_totalGridArea++; // Everytime it reads, increase the area by 1 unit.

            /* The following switch is for checking the type of type. We only care about whether it is a bridge
             * or if it is a mouse because we will be making ordered pairs out of them. */
            switch(Island[i][k])
            {
                case -2:    // If value is bridge
                {
                    /* Adding this if statement to check and see if the max number of bridge is
                     * created because lovely stack smashing is detected */
                    if(NumBridges == MAX_BRIDGES)
                    {
                        infile.close();
                        return TOO_MANY_BRIDGES;
                    }
                    Bridges[NumBridges].row = i;
                    Bridges[NumBridges].col = k;
                    NumBridges++;
                    break;
                }
                case -1:
                {
                    break;
                }
                case 1:     // If value is mouse
                {
                    /* Found the mouse! Store its position into an member OrderedPair
                     *   named Start */
                    if(l_mouseCounter == 0)
                    {
                        Start.row = i;
                        Start.col = k;
                    }
                    l_mouseCounter++;
                    break;
                }
                case 0:
                {
                    /* We read in a tile, so do nothing */
                    break;
                }
                default:
                {
                    /* The switch defaults if it read in something that isn't recognizable. This
                     *   means that it read in a value that doesn't represent a bridge, water, land,
                     *   or mouse */
                    return MISSING_INCORRECT_GRID_SIZE;
                }
            }

            /* k++ allows the next slot of the array to be pulled up since for loops aren't being used. Inside the
             * if statement, we are saying everytime k is equal to the total max that we are allowed to read in for
             * 1 row, which is the same value as Size, we will go to the next row and also reset the value of k back
             * to 0 so we can go index the array correctly. */
            k++;
            if(k == Size)
            {
                i++;
                k = 0;
            }
        }

        /* Do some error checking below, as mentioned above */

        /* Check to see if there was a mouse defined.
         *   We don't care to check if there are too many
         *   mice down here (after the loop), since we are
         *   already checking to see if there are already
         *   too many mice defined inside the loop. */
        if(l_mouseCounter == 0)
        {
            infile.close();
            return MISSING_MOUSE_STARTING_LOC;
        }
        else if(l_mouseCounter > 1)
        {
            infile.close();
            return TOO_MANY_MOUSE_LOC;
        }
        
        /* Does the map meet the satisfied number of bridges? */
        if(NumBridges < MIN_BRIDGES)
        {
            infile.close();
            return MISSING_BRIDGE;   // Not enough bridges
        }
        else if(NumBridges > MAX_BRIDGES)
        {
            infile.close();
            return TOO_MANY_BRIDGES;   // Too many bridges
        }

        // Is there enough grid information?
        if(l_totalGridArea < Size*Size)
        {
            infile.close();
            return INCOMPLETE_GRID;   // Not enough grid information.
        }
        else if(l_totalGridArea > Size*Size)
        {
            infile.close();
            return GRID_TOO_MUCH_INFO;   // Too much grid information.
        }
        infile.close();
    }

    return 0;
}

/** Function: IslandType::check(OrderedPair) ***************
 *  Description:
 *      This function checks to see whether the mouse has
 *        landed on a water, bridge, or land tile.
 *
 *  Preconditions:
 *      This function is called after the function
 *        Mouse::move(IslandType &, int) function is called.
 *
 *  Postconditions:
 *      This function modifies land tiles to show the
 *        frequency a mouse has visited the area. If the
 *        mouse moves and lands on a water tile, the status
 *        returned by the function will indicate that the
 *        mouse has drowned. If the mouse has moved to an
 *        area that denotes a bridge, the function will
 *        return the status that the mouse have escaped.
 *        If it is neither of the cases above, it will
 *        return that the mouse is alive. Checking the
 *        starvation of the mouse is actually checked in
 *        the function that calls this function, which is
 *        the MouseType::move()
 *  *******************************************************/
StatusType IslandType::check(OrderedPair mouseLocOP)
{
    // Checks to see if the mouse location op intersects w/ bridge or water or land.
    if(Island[mouseLocOP.row][mouseLocOP.col] == l_tileTypeBRIDGE)
        return StatusType::ESCAPED; // Mouse stepped on bridge --> ESCAPED
    else if(Island[mouseLocOP.row][mouseLocOP.col] == l_tileTypeWATER)
        return StatusType::DROWNED; // Mouse stepped in water  --> DROWNED
    else // If not a bridge or water, it's land.
    {   
        /* If the mouse didn't step step in water or a bridge, that means it must have
         * stepped on a piece of land. Therefore if it does, we will change the land tile,
         * which originally represented a 0,  to a 1 to show that the mouse has travered
         * at the tile already. Since it only stepped on a harmless tile, the return
         * value will just be StatusType::ALIVE. */
        Island[mouseLocOP.row][mouseLocOP.col]++; // Increase the times mouse has visited this area
        return StatusType::ALIVE;
    }
}
