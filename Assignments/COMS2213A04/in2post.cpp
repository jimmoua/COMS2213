/***************************************************************************
 *
 * Name: Jim Moua
 * Program #4
 * Due: 11/27/2018
 *
 * Description:
 *
 * Input: For inputing, the user must specify an input file. This input file
 *   contains the infix expressions.
 *
 * Output: If provided a file, the program will convert the infixes from
 *   said file and convert it to postfix. A message will pop up saying which
 *   file the output has been saved to, which is a file containing the post-
 *   fix expressions.
 *
 * Assumptions: None
 *
 * Special Processing Requirements: None
 *
 * ************************************************************************/
#include "expression.h"
#include "queue.h"
#include "QNodeType.h"
#include <string>
#include <fstream>

const std::string __FILE_NAME_INPUT__ = "inputfile";
const std::string __FILE_NAME_OUTPUT__ = "outputfile";

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr << "Error: Expected one file name. Received " << argc-1 << "\n";
        return EXIT_FAILURE;
    }
    else
    {
        /* Create an object to access files that will read and write to the
         * streams */
        std::ifstream inFile;
        std::ofstream outFile(__FILE_NAME_OUTPUT__);
        inFile.open(argv[1]);
        if(!inFile)
        {
            std::cerr << "Unable to open file: " << argv[1] << std::endl;
        }
        else
        {
            /* Create object for expression class */
            expression obj_expression;
            /* Create object for queue */
            queue<expression> obj_queue;
            while(inFile.is_open())
            {
                while(!obj_expression.last)
                {
                    inFile >> obj_expression;
                    obj_queue.push(obj_expression);
                }
                while(!obj_queue.empty())
                {
                    obj_expression = obj_queue.front();
                    outFile << obj_expression;
                    obj_queue.pop();
                }
                std::cout << "The postfix expressions has been saved to file: " << __FILE_NAME_OUTPUT__ << std::endl;
                inFile.close();
                outFile.close();
            }
        }
    }
    return EXIT_SUCCESS;
}
