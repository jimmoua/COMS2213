/*  ***********************************************************************************
 *  
 *  Jim Moua
 *  Program 2: ListType
 *  Due: Fri Sep 28 23:00:00 CDT 2018 (Original Due Date)
 *
 *  Description:
 *  This program is a demonstration to how an ordered and unordered list work.
 *
 *  Input:
 *  No user inputs are required for the lists themselves, but my driver file allows
 *  the user the choose between fiddling with an ordered list or an unordered list of
 *  a int or string type.
 *
 *  Output:
 *  There is only output for the driver file. The driver file will just demonstrate
 *  that both the ordered and unordered lists work correctly.
 *
 *  Special Processsing Requirements:
 *  The program requires c++11 in order to compile. The header files themself do not
 *  require c++11 to work in other programs, but my driver file requires c++11. When
 *  compiling my driver file, "ListType.h", "UListType.h", and "OListType.h" header
 *  files are required.
 *
 *  **********************************************************************************/
#include "UListType.h"
#include "OListType.h"
#include <iostream>
#include <string>

enum class type
{
    TYPE_INT,
    TYPE_STRING,
};

void clearScreen() { std::cout << std::string (100, '\n'); }
void pause() { std::string dummyString; std::cout << "Press return to continue."; std::getline(std::cin, dummyString); }

template<class T>
bool getInput(T &x);
template<class T>
void fiddleWithUListType(UListType<T> * object);
template<class T>
void fiddleWithOListType(OListType<T> * object);

int main()
{
    bool dataTypeChosen = false;
    type chosenDataType;
    while(!dataTypeChosen)
    {
        clearScreen();
        int userChoiceDataType;
        std::cout << "Choose a data type\n";
        std::cout << "[1] int\n";
        std::cout << "[2] string\n";
        getInput(userChoiceDataType);
        switch(userChoiceDataType)
        {
            case 1:
            {
                chosenDataType = type::TYPE_INT;
                dataTypeChosen = true;
                break;
            }
            case 2:
            {
                chosenDataType = type::TYPE_STRING;
                dataTypeChosen = true;
                break;
            }
            default: ;
        }
    }
    size_t capacity;
    bool choosetoFillCapacity = false;
    bool chosenCapacity = false;
    for(;;)
    {
        clearScreen();
        std::cout << "Choose to specify a capacity for the list? <y/n>\n";
        char yesOrno;
        bool validYesOrNo = false;
        if(getInput(yesOrno))
        {
            switch(yesOrno)
            {
                case 'y':
                case 'Y':
                    {
                        choosetoFillCapacity = true;
                        validYesOrNo = true;
                        break;
                    }
                case 'n':
                case 'N':
                    {
                        choosetoFillCapacity = false;
                        validYesOrNo = true;
                        break;
                    }
                default:
                    {
                        std::cout << "Bad value was given. Try agian.\n";
                        pause();
                        break;
                    }
            }
            if(validYesOrNo)
                break;
        }
    }
    while(!chosenCapacity and choosetoFillCapacity)
    {
        clearScreen();
        std::cout << "Choose a list capacity.\n";
        if(getInput(capacity))
        {
            chosenCapacity = true;
        }
        else
        {
            std::cout << "Bad value was given. Try agian.\n";
            pause();
        }
    }
    bool menuRunning = true;
    while(menuRunning)
    {
        clearScreen();
        std::cout << "[1] Fiddle with an unordered list\n";
        std::cout << "[2] Fiddle with an ordered list\n";
        std::cout << "[3] Exit\n";
        int userChoice;
        getInput(userChoice);
        switch(userChoice)
        {
            case 1:
            {
                if(chosenDataType == type::TYPE_INT)
                {
                    UListType<int> * object = nullptr;
                    if(chosenCapacity)
                    {
                        object = new UListType<int>(capacity);   
                        fiddleWithUListType(object);
                    }
                    else
                    {
                        object = new UListType<int>;
                        fiddleWithUListType(object);
                    }
                    delete object;
                }
                else if(chosenDataType == type::TYPE_STRING)
                {
                    UListType<std::string> * object = nullptr;
                    if(chosenCapacity)
                    {
                        object = new UListType<std::string>(capacity);
                        fiddleWithUListType(object);
                    }
                    else
                    {
                        object = new UListType<std::string>;
                        fiddleWithUListType(object);
                    }
                    delete object;
                }
                menuRunning = false;
                break;
            }
            case 2:
            {
                if(chosenDataType == type::TYPE_INT)
                {
                    OListType<int> * object = nullptr;
                    if(chosenCapacity)
                    {
                        object = new OListType<int>(capacity);   
                        fiddleWithOListType(object);
                    }
                    else
                    {
                        object = new OListType<int>;
                        fiddleWithOListType(object);
                    }
                    delete object;
                }
                else if(chosenDataType == type::TYPE_STRING)
                {
                    OListType<std::string> * object = nullptr;
                    if(chosenCapacity)
                    {
                        object = new OListType<std::string>(capacity);
                        fiddleWithOListType(object);
                    }
                    else
                    {
                        object = new OListType<std::string>;
                        fiddleWithOListType(object);
                    }
                    delete object;
                }
                menuRunning = false;
                break;
            }
            case 3:
            {
                menuRunning = false;
                break;
            }
            default: ;
        }
    }
    return EXIT_SUCCESS;
}

template<class T>
void fiddleWithUListType(UListType<T> * object)
{
    bool menu = true;
    bool erasedAllSignalExit = false;
    while(menu)
    {
        clearScreen();
        UListType<T> copy1 = *object;
        UListType<T> copy2(*object);
        std::cout << "The capacity of the list is: " << object->getCapacity() << std::endl;
        std::cout << "The current list has a size of: " << object->size() << std::endl;
        std::cout << "The list is: " << *object << std::endl;
        std::cout << "Here's a copy via operator: " << copy1 << std::endl;
        std::cout << "Here's a copy via constructor: " << copy1 << std::endl;
        if(erasedAllSignalExit)
        {
            std::cout << "The last command was to erase the whole list. The program will now exit.\n";
            pause();
            std::cout << "Goodbye!\n";
            return;
        }
        std::cout << "[1] Insert an item\n";
        std::cout << "[2] Erase an item\n";
        std::cout << "[3] Find an item\n";
        std::cout << "[4] Erase all items (closes program after erasing all)\n";
        int userChoice;
        getInput(userChoice);
        T valueToAction;
        switch(userChoice)
        {
            case 1:
            {
                for(;;)
                {
                    std::cout << "Insert";
                    while(!getInput(valueToAction))
                    {
                        std::cout << "Bad value given, try again\n";
                        pause();
                    }
                    if(!object->insert(valueToAction))
                    {
                        std::cout << "Could not insert value " << valueToAction << std::endl;;
                        pause();
                    }
                    break;
                }
                break;
            }
            case 2:
            {
                for(;;)
                {
                    std::cout << "Erase";
                    while(!getInput(valueToAction))
                    {
                        std::cout << "Bad value given, try again\n";
                        pause();
                    }
                    if(!object->erase(valueToAction))
                    {
                        std::cout << "Could not erase value " << valueToAction;
                        if(object->empty())
                            std::cout << ", the list is empty\n";
                        else
                            std::cout << std::endl;
                        pause();
                    }
                    break;
                }
                break;
            }
            case 3:
            {
                for(;;)
                {
                    std::cout << "Find";
                    while(!getInput(valueToAction))
                    {
                        std::cout << "Bad value given, try again\n";
                        pause();
                    }
                    if(object->find(valueToAction))
                        std::cout << "Found the value: " << valueToAction << std::endl;
                    else
                        std::cout << "Could not find the value: " << valueToAction << std::endl;
                    pause();
                    break;
                }
                break;
            }
            case 4:
            {            
                object->eraseAll();
                erasedAllSignalExit = true;
            }
        }
    }
}

template<class T>
void fiddleWithOListType(OListType<T> * object)
{
    bool menu = true;
    bool erasedAllSignalExit = false;
    while(menu)
    {
        clearScreen();
        OListType<T> copy1 = *object;
        OListType<T> copy2(*object);
        std::cout << "The capacity of the list is: " << object->getCapacity() << std::endl;
        std::cout << "The current list has a size of: " << object->size() << std::endl;
        std::cout << "The list is: " << *object << std::endl;
        std::cout << "Here's a copy via operator: " << copy1 << std::endl;
        std::cout << "Here's a copy via constructor: " << copy1 << std::endl;
        if(erasedAllSignalExit)
        {
            std::cout << "The last command was to erase the whole list. The program will now exit.\n";
            pause();
            std::cout << "Goodbye!\n";
            return;
        }
        std::cout << "[1] Insert an item\n";
        std::cout << "[2] Erase an item\n";
        std::cout << "[3] Find an item\n";
        std::cout << "[4] Erase all items (closes program after erasing all)\n";
        int userChoice;
        getInput(userChoice);
        T valueToAction;
        switch(userChoice)
        {
            case 1:
            {
                for(;;)
                {
                    std::cout << "Insert";
                    while(!getInput(valueToAction))
                    {
                        std::cout << "Bad value given, try again\n";
                        pause();
                    }
                    if(!object->insert(valueToAction) && object->full())
                    {
                        std::cout << "Could not insert value " << valueToAction << std::endl;
                        pause();
                    }
                    break;
                }
                break;
            }
            case 2:
            {
                for(;;)
                {
                    std::cout << "Erase";
                    while(!getInput(valueToAction))
                    {
                        std::cout << "Bad value given, try again\n";
                        pause();
                    }
                    if(!object->erase(valueToAction))
                    {
                        std::cout << "Could not erase value " << valueToAction;
                        if(object->empty())
                            std::cout << ", the list is empty\n";
                        else
                            std::cout << std::endl;
                        pause();
                    }
                    break;
                }
                break;
            }
            case 3:
            {
                for(;;)
                {
                    std::cout << "Find";
                    while(!getInput(valueToAction))
                    {
                        std::cout << "Bad value given, try again\n";
                        pause();
                    }
                    if(object->find(valueToAction))
                        std::cout << "Found the value: " << valueToAction << std::endl;
                    else
                        std::cout << "Could not find the value: " << valueToAction << std::endl;
                    pause();
                    break;
                }
                break;
            }
            case 4:
            {            
                object->eraseAll();
                erasedAllSignalExit = true;
            }
        }
    }
}

template<class T>
bool getInput(T &x)
{
    std::cout << " >>> ";
    std::cin >> x;
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        return false;
    }
    else
    {
        std::cin.ignore();
        return true;
    }
}

