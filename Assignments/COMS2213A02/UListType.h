#ifndef ULISTTYPE_H
#define ULISTTYPE_H
#include "ListType.h"

/*  ********************************************************************************
 *  Class: UListType
 *
 *  Description:
 *  This is an "unordered" list. Values that are inserted through this class will
 *  simply be appended to the end of the list, and values that are removed from the
 *  list are whichever values came first into the list.
 *
 *  *******************************************************************************/
template<class T>
class UListType: public ListType<T>     // Unordered
{
    public:
        UListType(size_t = 10);
        bool insert(const T&);
        bool erase(const T&);
        bool find(const T&) const;
    private:
};

/*  ********************************************************************************
 *  Function: UListType<T>::UListType(size_t n): ListType<T>(n)
 *
 *  Description:
 *  This is the ctor of the class. When an object of this class is instantiated, the
 *  default value of n will be 10 or whichever number is specified by invoking the
 *  ctor of the base class.
 *
 *  Preconditions:
 *  None.
 *
 *  Postconditions:
 *  Modified the value of n, which is the capacity of the list.
 *
 *  *******************************************************************************/
template<class T>
UListType<T>::UListType(size_t n): ListType<T>(n)
{
    
}

/*  ********************************************************************************
 *  Function: bool UListType<T>::find(const T & valueSearchingFor) const
 *
 *  Description:
 *  This function does a sequential search on the list to see if a specific value
 *  is the on the list. If the value is found, the function returns true, and if the
 *  item is not found, the function returns false.
 *
 *  Preconditions:
 *  The function requires a value fed as a parameter. This parameter is what the
 *  function will then try to find in the list.
 *
 *  Postconditions:
 *  None.
 *
 *  *******************************************************************************/
template<class T>
bool UListType<T>::find(const T & valueSearchingFor) const
{
    bool found = false;
    for(size_t i = 0; i < this->size(); i++)
    {
        if(this->list[i] == valueSearchingFor)
            found = true;
    }
    return found;
}

/*  ********************************************************************************
 *  Function: bool UListType<T>::insert(const T & valueToBeInserted)
 *
 *  Description:
 *  This function will append a value to the list if it is not full. If the item is
 *  appended to the list, the function will return true, and if the item is not
 *  appended to the list, the function will return false.
 *
 *  Preconditions:
 *  Function takes a parameter of what value is to be appended to the list.
 *
 *  Postconditions:
 *  Modifies the list by appending whatever value was specified to be appended and
 *  modifies the list size. If the list is full, a new list will be created and a
 *  deep copy will be performed such that the list of the class is copied over to
 *  the new list. The new list will have twice the capacity of the old list if a new
 *  list is created. If a new list of size n is unable to be allocated, the function
 *  will throw an exception of bad allocation, and nothing inside the class object
 *  will change.
 *
 *  *******************************************************************************/
template<class T>
bool UListType<T>::insert(const T & valueToBeInserted)
{
    bool didAppend = true;
    if(this->full())
    {
        try
        {
            /* Create a new list twice the size of the current list and then deep copy.
             * After performing deep copy, delete the old list an repoint the pointer
             * to the new list */
            size_t newCapacity = 2*this->count;
            T *temp = new T[newCapacity];
            this->capacity = newCapacity;
            for(size_t i = 0; i < this->count; i++)
            {
                temp[i] = this->list[i];
            }
            delete [] this->list;
            this->list = temp;
        }
        catch(std::bad_alloc &)
        {
            didAppend = false;
        }
    }
    if(didAppend)
        this->list[this->count++] = valueToBeInserted;
    return didAppend;
}

/*  ********************************************************************************
 *  Function: bool UListType<T>::erase(const T & valueToBeErased)
 *
 *  Description:
 *  This function will perform a sequential search until a specific value is found.
 *  If the value is found, the value is removed from the list. If there are
 *  multiples of the same value, whichever value it finds first is removed from the
 *  list. If the value is erased from the list, the function will return true, and
 *  if the item is not erased from the list, the function will return false.
 *
 *  Preconditions:
 *  The function requires 1 parameter, which is the value to be removed from the
 *  list.
 *
 *  Postconditions:
 *  Will modify the list and the size of the list if a value is found.
 *
 *  *******************************************************************************/
template<class T>
bool UListType<T>::erase(const T & valueToBeErased)
{
    bool isErased = false;
    if(!this->empty())
    {
        for(size_t i = 0; i < this->count; i++)
        {
            if(this->list[i] == valueToBeErased)
            {
                for(size_t k = i; k < this->count-1; k++)
                {
                    this->list[k] = this->list[k+1];
                }
                this->count--;
                isErased = true;
                break; // Remove this break statement if wanting to remove all values.
            }
        }
    }
    return isErased;
}

#endif
