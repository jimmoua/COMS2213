/*  ***********************************************************************************
 *  
 *  Jim Moua
 *  Program 1: Dead Mouse Program
 *  Due: 21 September 2018
 *
 *  Description:
 *  This program simulates a mouse simulation and shows the output of the simulations
 *  ran. A valid map must be provided to the program as an argument.
 *
 *  Input:
 *  There are no user inputs required while the program is running. The only input that
 *  is required is the command line argument, which should be a file that resembles a
 *  map with bridges, water, land, only 1 mouse position.
 *
 *  Output:
 *  If a good map file is given to the command line, the output will generate
 *  informations of every simulation. This information contains how many times the
 *  mouse moved until it drowned, escaped, or starved, frquencies of the locations of
 *  land tiles it visited, how many moves the mouse made before its status was changed,
 *  locations of the mouse starting position, and the locations of the bridges. At the
 *  end of the all the simulations, the program will output the total number of times
 *  that the mouse has either starved, escaped, or drowned.
 *  If, on the other hand, an invalid map file is given the program, the program will
 *  generate error messages instead. Each error message will tell the user what is
 *  wrong with the map file they are providing to the program.
 *
 *  Special Processsing Requirements:
 *  The program does not require any specific version of c++ to compiled.
 *  required files are 'Misc.cpp', 'MouseType.cpp', 'Misc.cpp', and their respective
 *  header files.
 *
 *
 *  **********************************************************************************/

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "MouseType.h"
#include "IslandType.h"
#include "Misc.h"

int main(int argc, char *argv[])
{
    MouseType mouse;
    IslandType island;
    int starved = 0,
        escaped = 0,
        drowned = 0;
    std::srand(time(NULL));
    if(argc > 1)
    {
        switch(island.getGrid(argv[1]))
        {
            case 1:
                std::cerr << "Could not open file " << argv[1] << std::endl;
                return 1;
            case 2:
                std::cerr << "Missing or incorrect grid size in file " << argv[1] << std::endl;
                return 2;
            case 3:
                std::cerr << "Missing mouse starting location in file " << argv[1] << std::endl;
                return 3;
            case 4:
                std::cerr << "Too many mouse locations in file " << argv[1] << std::endl;
                return 4;
            case 5:
                std::cerr << "Missing bridges in file " << argv[1] << std::endl;
                return 5;
            case 6:
                std::cerr << "Too many bridges in file " << argv[1] << std::endl;
                return 6;
            case 7:
                std::cerr << "Grid not complete in file " << argv[1] << std::endl;
                return 7;
            case 8:
                std::cerr << "Too much grid information in file " << argv[1] << std::endl;
                return 8;
            case 9:
                std::cerr << "The file \"" << argv[1] << "\" is empty." << std::endl;
                return 9;
        }
    }
    else
    {
        std::cerr << "Filename not provided. Try again." << std::endl;
        return -1;
    }

    // Runs the simulation NUM_SIMS times.
    for(int i = 1; i <= NUM_SIMS; i++)
    {
        mouse.reset(island.start());
        while(mouse.status() == StatusType::ALIVE)
            mouse.move(island, rand()%4+1);

        std::cout << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << "Simulation " << i << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        switch(mouse.status())
        {
            case StatusType::DROWNED:
                std::cout << "The mouse drowned" << std::endl;
                drowned++;
                break;
            case StatusType::ESCAPED:
                std::cout << "The mouse escaped" << std::endl;
                escaped++;
                break;
            case StatusType::STARVED:
                std::cout << "The mouse starved" << std::endl;
                starved++;
                break;
        }
        std::cout << "The mouse's starting position was " << island.start() << "." << std::endl;
        std::cout << "The mouse's final position was " << mouse.position() << "." << std::endl;
        std::cout << "The mouse's total number of moves was " << mouse.moves() << "." << std::endl;
        island.printBridges();
        std::cout << "Frequency grid of mouse visitations." << std::endl;
        std::cout << "    ~ - water" << std::endl;
        std::cout << "    B - bridge location" << std::endl;
        std::cout << "    . - island location not visited" << std::endl;
        island.printGrid();
        std::cout << std::endl;
        island.reset();
    }

    std::cout << "The mouse drowned " << drowned << " times." << std::endl;
    std::cout << "The mouse starved " << starved << " times." << std::endl;
    std::cout << "The mouse escaped " << escaped << " times." << std::endl;

    return 0;
}
