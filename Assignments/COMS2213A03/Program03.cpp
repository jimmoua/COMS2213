/* ****************************************************************************************************************
 *
 * Jim Moua
 * Program 3: Linked Lists
 *
 * Description:
 * This program is just dealing with single linked lists. It deals with both ordered and unordered (via insert).
 *
 * Input:
 * For my driver file, the only inputs that are needed from the user are inputs for finding values. This is just to
 * test that the find functions work for both unordered and ordered lists.
 *
 * Output:
 * Shows both ordered and unordered lists and their contents.
 *
 * Special Processing Requirements:
 * For this driver file to compile, C++ version 11+ must be specified when compiling. If using GNU's c++ compiler,
 * you may compile via
 *
 *      g++ Program03.cpp -std=c++11
 *
 * The user defined header files for this driver program to compile are UListType.h, OListType.h, ListType.h.
 *
 * ****************************************************************************************************************/
#include "UListType.h"
#include "OListType.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

template<class T>
bool getInput(T &x);

void OLIST();
void ULIST();

int main()
{
    std::cout << "UNORDERED LIST\n";
    ULIST();
    std::cout << "\n\n\n\n\n";
    std::cout << "ORDERED LIST\n";
    OLIST();
    return EXIT_SUCCESS;
}

void OLIST()
{
    srand(time(NULL));
    OListType<int> asdf;
    for(int i = 0; i < 15; i++)
        asdf.insert(rand()%1000 - 500);
    std::cout << asdf << std::endl;
    unsigned short int valuesToFind = 2;
    for(auto i = valuesToFind; i > 0; i--)
    {
        std::cout << "Find " << i << " values.\n";
        int item;
        while(!getInput(item));

        if(!asdf.find(item))
            std::cout << item << " not found.\n";
        else
            std::cout << item << " found.\n";
    }

    /* Copy constructor */
    OListType<int> fdsa(asdf);
    std::cout << fdsa << std::endl;
    std::cout << "Size of fdsa: " << fdsa.size() << std::endl;

    /* Copy via operator overload */
    OListType<int> fdsa_ = asdf;
    std::cout << fdsa_ << std::endl;
    std::cout << "Size of fdsa_: " << fdsa_.size() << std::endl;
}


void ULIST()
{
    srand(time(NULL));
    UListType<int> asdf;
    for(int i = 0; i < 15; i++)
        asdf.insert(rand()%1000 - 500);
    std::cout << asdf << std::endl;
    unsigned short int valuesToFind = 2;
    for(auto i = valuesToFind; i > 0; i--)
    {
        std::cout << "Find " << i << " values.\n";
        int item;
        while(!getInput(item));

        if(!asdf.find(item))
            std::cout << item << " not found.\n";
        else
            std::cout << item << " found.\n";
    }

    /* Copy constructor */
    UListType<int> fdsa(asdf);
    std::cout << fdsa << std::endl;
    std::cout << "Size of fdsa: " << fdsa.size() << std::endl;

    /* Copy via operator overload */
    UListType<int> fdsa_ = asdf;
    std::cout << fdsa_ << std::endl;
    std::cout << "Size of fdsa_: " << fdsa_.size() << std::endl;
}

template<class T>
bool getInput(T &x)
{
    bool goodInput = false;
    std::cout << "  >>> ";
    std::cin >> x;
    std::cin.ignore();
    if(!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
    else
        goodInput = true;
    return goodInput;
}
