#ifndef OLISTTYPE_H
#define OLISTTYPE_H
#include "ListType.h"

/*  ********************************************************************************
 *  Class: OListType
 *
 *  Description:
 *  This class holds an ordered list and is derived from ListType class. The type
 *  of ordering this class has is that is orders its values from low to high.
 *
 *  *******************************************************************************/
template<class T>
class OListType: public ListType<T>
{
    public:
        OListType(size_t = 10);
        bool insert(const T&);
        bool erase(const T&);
        bool find(const T&) const;
    private:
};

/*  ********************************************************************************
 *  Function: OListType<T>::OListType(size_t n): ListType<T>::ListType(n)
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
OListType<T>::OListType(size_t n): ListType<T>(n)
{

}

/*  ********************************************************************************
 *  Function: bool OListType<T>::erase(const T & valueToErase)
 *
 *  Description:
 *  This function will perform binary search on the list since it is an ordered
 *  list and remove the item, if the at the end of binary search, the value is
 *  found. If the item is erased successfully, which implies that it was also found
 *  within the list, the function returns true, otherwise it returns false.
 *
 *  Preconditions:
 *  The parameter it takes is the value to be erased.
 *
 *  Postconditions:
 *  If the value is found, the list size will decrease by 1 and the value will be
 *  removed from the ordered list.
 *
 *  *******************************************************************************/
template<class T>
bool OListType<T>::erase(const T & valueToErase)
{
    bool erasedSucceed = false;
    if(this->empty())
    {
        return erasedSucceed;
    }
    else
    {
        bool found = false;
        int high = this->size() - 1;
        int low = 0;
        int mid;
        while(low <= high)
        {
            mid = (low+high) >> 1;
            if(valueToErase == this->list[mid])
            {
                found = true;
                break;
            }
            if(valueToErase < this->list[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        if(found)
        {
            for(size_t i = mid; i < this->size()-1; i++)
            {
                this->list[i] = this->list[i+1];
            }
            this->count--;
            erasedSucceed = true;
        }
    }
    return erasedSucceed;
}

/*  ********************************************************************************
 *  Function: bool OListType<T>::insert(const T & valueToInsert)
 *
 *  Description:
 *  This function will perform a binary search on the list to see where a value
 *  should be inserted. The binary search is only considered if the list is not
 *  full. After the binary search, it will compare to see if the current position
 *  of the list that binary search provided if greater than or equal to the value
 *  to be inserted. If it is greater than or equal to the value to be inserted,
 *  the list will be shifted to the one to the left at that position and the value
 *  will be inserted there. For example...
 *    Value to be inserted: 29
 *    Example list: 0  1  28  40  58  69
 *    
 *                  0  1  28  --  40  58  69
 *                            ^^ <--- the list is shifted right and the value is
 *                                    inserted here.
 *
 *    It is important that the position is incremented by 1 if the value is
 *      greater than or equal to the position. If not, the insertion would be like
 *      this...
 *        
 *    Value to be inserted: 29
 *    Example list: 0  1  28  40  58  69
 *    
 *                  0  1  --  28  40  58  69
 *                        ^^ <--- the list is shifted right and the value is
 *                                inserted here, but the list would look like...
 *
 *                  0  1  29  28  40  58  69
 *                        ^^ <--- Not correct.
 *  If the function manages to insert the value, the function will return true.
 *  If the does not manage to insert the value, the function will return false.
 *
 *  Preconditions:
 *  The parameter the function takes is a value to be inserted to the list.
 *
 *  Postconditions:
 *  If the list is not empty, the size of the list will increment by a value of one
 *  and a value will be inserted into the list. If the list is full, a new list will
 *  be created with twice the capaity. If the program is unable to dynamically
 *  allocate memory for an array of size n, an exception of bad allocation will be
 *  thrown, and nothing in the class will change.
 *
 *  *******************************************************************************/
template<class T>
bool OListType<T>::insert(const T & valueToInsert)
{
    bool insertSucceed = true;;
    if(this->full())
    {
        try
        {
            size_t newCapacity = 2*this->capacity;
            T *tempList = new T[newCapacity];
            this->capacity = newCapacity;
            for(size_t i = 0; i < this->size(); i++)
            {
                tempList[i] = this->list[i];
            }
            delete [] this->list;
            this->list = tempList;
        }
        catch(std::bad_alloc &)
        {
            insertSucceed = false;
            return insertSucceed;
        }
    }
    if(insertSucceed)
    {
        if(this->empty())
        {
            *this->list = valueToInsert;
            this->count++;
            return true;
        }
        int high = this->size()-1;
        int low = 0;
        int mid;
        while(low <= high)
        {
            mid = (low+high) >> 1;
            if(valueToInsert < this->list[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        if(valueToInsert >= this->list[mid])
            ++mid;
        this->count++;
        for(int i = this->size()-1; i > mid; i--)
        {
            this->list[i] = this->list[i-1];
        }
        this->list[mid] = valueToInsert;
        insertSucceed = true;
    }
    return insertSucceed;
}

/*  ********************************************************************************
 *  Function: bool OListType<T>::find(const T & valueToFind) const
 *
 *  Description:
 *  This function is just plain ol' binary search. If the item is found, the
 *  function returns true and if it is not found, the function will return false.
 *
 *  Preconditions:
 *  The parameter is the value to be found in the list.
 *
 *  Postconditions:
 *  The function does not modify anything.
 *
 *  *******************************************************************************/
template<class T>
bool OListType<T>::find(const T & valueToFind) const
{
    bool found = false;
    if(this->empty())
        return false;
    else
    {
        int high = this->count - 1;
        int low = 0;
        int middle;
        while(low <= high)
        {
            middle = (low + high)/2;
            if(valueToFind == this->list[middle])
            {
                found = true;
                break;
            }
            if(valueToFind < this->list[middle])
            {
                high = middle - 1;
            }
            else if(valueToFind > this->list[middle])
            {
                low = middle + 1;
            }
        }
    }
    return found;
}

#endif
