#ifndef SORT_BUBBLE_SORT_H
#define SORT_BUBBLE_SORT_H
#include "UList.h"

/* -------------------------------------------------------------------
 * Function:
 *   void sort(UList<T>&)
 *
 * Description:
 *   Sorts an unordered list through bubble sort.
 *
 * Preconditions:
 *   The argument is a class object from the UList class. The things
 *   that are being sorted is the vector from the UList class.
 *
 * Postconditions:
 *   Sorts the vector from values low to high.
 * -----------------------------------------------------------------*/
template<class T>
void sort(UList<T>& list)
{
  for(size_t i = 1; i < list.size(); i++)
    for(size_t j = 0; j < list.size()-i; j++)
      if(list.items[j] > list.items[j+1])
        std::swap(list.items[j], list.items[j+1]);
}

#endif
