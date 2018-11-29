#ifndef ULIST_H
#define ULIST_H
#include <cstddef>
#include <vector>
#include <ostream>

/* =README============================================================
 * This header requires programs that use it to be compiled with c++11
 * =================================================================*/

template<class T>
class UList
{
  public:
    UList(size_t = 10);
    void insert(const T&);
    bool erase(const T&);
    bool find(const T&) const;
    size_t size() const;
    bool empty() const;
    template<class U>
      friend std::ostream& operator<<(std::ostream&, const UList<U>&);
    template<class U>
      void friend sort(UList<U>&);
  protected:
    std::vector<T> items;
};

/* -------------------------------------------------------------------
 * Function:
 *   UList<T>::UList(size_t)
 *
 * Description:
 *   Reserved a spot of n values for the vector. This n value is
 *   passed in as an argument to the function. If nothing is passed
 *   in, the ctor will use a default value of 10.
 *
 * Preconditions:
 *   An object of the UList class is instantiated with an positive
 *   integer as an argument.
 *
 * Postconditions:
 *   Reserved n spots for values in the vector.
 *
 * -----------------------------------------------------------------*/
template<class T>
UList<T>::UList(size_t n)
{
  items.reserve(n);
}

/* -------------------------------------------------------------------
 * Function:
 *   UList<T>::insert(const T&)
 *
 * Description:
 *   Inserts an item to the end of the vector by using the push_back
 *   function function from the standard vector class.
 *
 * Preconditions:
 *   An argument is passed into the parameter, which denotes the item
 *   to push back into the vector.
 *
 * Postconditions:
 *   Pushes the item into the vector.
 *
 * -----------------------------------------------------------------*/
template<class T>
void UList<T>::insert(const T& valueToInsert)
{
  items.push_back(valueToInsert);
}

/* -------------------------------------------------------------------
 * Function:
 *   bool UList<T>::erase(const T&)
 *
 * Description:
 *   Erases an item from the vector by using an iterator.
 *
 * Preconditions:
 *   The argument of this function is the item to be removed from the
 *   vector, provided that is exists. If the item doesn't exist, then
 *   nothing will be removed from the vector.
 *
 * Postconditions:
 *   If the item to be removed is in the vector, the item will be
 *   removed from the vector. Otherwise, the vector doesn't change.
 *
 * -----------------------------------------------------------------*/
template<class T>
bool UList<T>::erase(const T& itemToErase)
{
  bool itemErasedFromListSuccessfully = false;
  for(auto iter = items.begin(); iter != items.end(); iter++)
  {
    if(*iter == itemToErase)
    {
      items.erase(iter);
      itemErasedFromListSuccessfully = true;
      break;
    }
  }
  return itemErasedFromListSuccessfully;
}

/* -------------------------------------------------------------------
 * Function:
 *   bool UList<T>::find(const T&) const
 *
 * Description:
 *   Finds an item in the vector.
 *
 * Preconditions:
 *   The argument passed to this function is the item to find within
 *   the vector.
 *
 * Postconditions:
 *   This function does not modify anything. It simply returns true
 *   if the item is found within the vector and false if the item
 *   is not found within the vector.
 *
 * -----------------------------------------------------------------*/
template<class T>
bool UList<T>::find(const T& itemToFind) const
{
  bool itemFound = false;
  for(auto iter = items.begin(); iter != items.end(); iter++)
  {
    if(*iter == itemToFind)
    {
      itemFound = true;
      break;
    }
  }
  return itemFound;
}

/* -------------------------------------------------------------------
 * Function:
 *   size_t UList<T>::size() const
 *
 * Description:
 *   Returns the current size of the vector by using the size function
 *   from the vector class.
 *
 * Preconditions:
 *   None.
 *
 * Postconditions:
 *   Does not modify anything. Simply returns a size_t data type
 *   indicating the number of items in the vector.
 *
 * -----------------------------------------------------------------*/
template<class T>
size_t UList<T>::size() const
{
  return items.size();
}

/* -------------------------------------------------------------------
 * Function:
 *   std::ostream& operator<<std::ostream&, const UList<T>&)
 *
 * Description:
 *   Returns an output stream to an ostream. Essentially, this prints
 *   the items in the vector. If the vector is empty, this function
 *   will return the string "Empty." to the output stream. If the
 *   vector is not empty, it will print items in the list.
 *
 * Preconditions:
 *   None.
 *
 * Postconditions:
 *   Does not modify anything.
 *
 * -----------------------------------------------------------------*/
template<class T>
std::ostream& operator<<(std::ostream& os, const UList<T>& obj)
{
  if(!obj.items.empty())
  {
    os << *obj.items.begin();
    for(auto iter = obj.items.begin()+1; iter != obj.items.end(); iter++)
    {
      os << ", " << *iter;
    }
  }
  else
    os << "Empty.";
  return os;
}

/* -------------------------------------------------------------------
 * Function:
 *   bool UList<T>::empty() const
 *
 * Description:
 *   Returns true if the vector is empty. Returns false is the vector
 *   is not empty.
 *
 * Preconditions:
 *   None.
 *
 * Postconditions:
 *   Does not modify anything. Simply returns Boolean values.
 *
 * -----------------------------------------------------------------*/
template<class T>
bool UList<T>::empty() const { return items.empty(); }

#endif
