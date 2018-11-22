#ifndef ULIST_TYPE_H
#define ULIST_TYPE_H
#include "ListType.h"

/* Class: UListType
 *
 * Description:
 * This is a derived class from the base class of ListType
 *
 * */
template<class T>
class UListType: public ListType<T>
{
    public:
        virtual bool insert(const T &);
        UListType();
    protected:
    private:
};

/* Function: UListType<T>::UListType()
 *
 * Description:
 * This function is the default constructor of the UListType class. It just calls upon the
 * constructor of the base class.
 *
 * Preconditions:
 * None.
 *
 * Postconditions:
 * Modifies head pointer to null and count to 0.
 *
 * */
template<class T>
UListType<T>::UListType(): ListType<T>::ListType() { }

/* Function: UListType<T>::insert(const T &)
 *
 * Description:
 * This function inserts a value to the beginning of the list, since it is an
 * unordered list.
 *
 * Preconditions:
 * A value must be passed in as a parameter to this function. This value is the value
 * that is going to be inserted into the list.
 *
 * Postconditions:
 * The list head will change, as it will become the new value of the list. If inserting
 * a value is successful, count will increase by 1 as well.
 *
 * */
template<class T>
bool UListType<T>::insert(const T &valueToInsert)
{
    bool inserted = false;
    NodeType<T> *newNode = nullptr;

    /* Try to allocate memory for the node first */
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
        return inserted;
    }
    return inserted;
}

#endif
