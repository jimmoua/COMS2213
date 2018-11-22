#ifndef OLISTTYPE_H
#define OLISTTYPE_H
#include "ListType.h"

/* Class: OListType
 *
 * Description:
 * This is a derived class of the base class ListType. This class is also
 * ordered. Values that are inserted into this list are inserted from low to high
 *
 * */
template<class T>
class OListType: public ListType<T>
{
    public:
        OListType();
        virtual bool insert(const T &);
    protected:
    private:
};

/* Function: OListType<T>::OListType()
 *
 * Description:
 * This function is the default constructor of the OListType class. It just calls upon the
 * constructor of the base class. It does exactly the same thing as the constructor for the
 * UListType.
 *
 * Preconditions:
 * None.
 *
 * Postconditions:
 * Modifies head pointer to null and count to 0.
 *
 * */
template<class T>
OListType<T>::OListType(): ListType<T>::ListType() { }


/* Function: OListType<T>::insert(const T &)
 *
 * Description:
 * This function will insert values in order from low to high.
 *
 * Preconditions:
 * The parameter is the value to be inserted into the list.
 *
 * Postconditions:
 * Modifies the list to where a new value is inserted into a specific place.
 * Also modifies the count by incrementing it by 1 if inserting is successful.
 *
 * */
template<class T>
bool OListType<T>::insert(const T &valueToInsert)
{

    /*
     * In the case where it just needs to be inserted at the beginning of a list, the logic is
     * similar to ListType::erase, but we will not be deleting anything, but rather allocating
     * something.
     *
     * Value to insert (beginning): -4
     *
     * this->list
     * [ ]  [1]  3  6  7  13  14  17  [N]
     *  ↑    ↑ current head
     *  | ← Needs to become new head
     *
     *
     *
     * Value to insert: 10
     *
     * this->list
     * 1  3  6  7  13  [ ]  14  17  [N]
     *                  ↑ needs to be inserted here
     * 
     * For this reason, use two pointers
     * 1  3  6  7  13  [ ]  14  17  [N]
     *              ↑   ↑    ↑
     *              |        L right pointer
     *              L left poitner
     *
     * If something needs to be inserted at the end...
     * Value to insert (end): 20
     *
     * this->list
     * 1  3  6  7  13  14  17  [N]
     *                          ↑ needs to be inserted here where null ptr is
     * 
     * 1  3  6  7  13  14  [17]  [*]  [N]
     *                       ↑    ↑    ↑ right pointer
     *                       |    L new NodeType<T>
     *                       |         L right pointer
     *                       L left pointer
     *
     *
     * */

    bool inserted = false;
    
    NodeType<T> *thisListIterator = this->head;   // Create an iterator for traversing
    NodeType<T> *thisListIteratorPrev = nullptr;  // Pointer that is last location of thisListIterator

    /* If the value should be inserted at the head, or is the list is just empty*/
    if(this->empty() || valueToInsert <= thisListIterator->info)
    {
        NodeType<T> *newNode = nullptr;
        try
        {
            newNode = new NodeType<T>;
            newNode->info = valueToInsert;
            newNode->link = this->head;
            this->head = newNode;
            this->count++;
            inserted = true;
        }
        catch(std::bad_alloc &)
        {
            // Catch it, do nothing else.
        }
    }

    /* If we must search where to insert the value... */
    while(thisListIterator != nullptr && valueToInsert > thisListIterator->info)
    {
        thisListIteratorPrev = thisListIterator;   // Points it to thisListIterator
        thisListIterator = thisListIterator->link; // Traverse the next item on thisListIterator.
        if(thisListIterator != nullptr) // If the end of list isn't reached, do checking
        {
            if(valueToInsert > thisListIteratorPrev->info && valueToInsert <= thisListIterator->info)
            {

                /* [P]  [I] → [N]
                 *  ↑____↑  2)      Dynamically allocate [I] then point i to [N]. Then point previous to [I]
                 *    1)
                 *
                 *  */

                try
                {
                    NodeType<T> *newNode = new NodeType<T>; // This is going to be [I]
                    thisListIteratorPrev->link = newNode;   // Link the prev to the new one
                    newNode->info = valueToInsert;          // insert the value
                    newNode->link = thisListIterator;       // link the new to current iterator

                    /* After inserting, increment count and break away from loop */
                    this->count++;
                    inserted = true;
                    break;
                }
                catch(std::bad_alloc&)
                {
                    inserted = false;
                }
            }
        }
    }

    /* If the value should be inserted at the end of the list */
    if(!inserted && thisListIterator == nullptr) // If thisListIterator is nullptr, that means end of list reached
    {
        try
        {
            thisListIterator = new NodeType<T>;         // Allocate memory for the null
            thisListIterator->info = valueToInsert;     // Assign the value
            this->count++;                              // Increment count
            thisListIterator->link = nullptr;           // It's link set to nullptr
            thisListIteratorPrev->link = thisListIterator;
            inserted = true;
        }
        catch(std::bad_alloc&)
        {
            inserted = false;
        }
    }

    return inserted;
}

#endif
