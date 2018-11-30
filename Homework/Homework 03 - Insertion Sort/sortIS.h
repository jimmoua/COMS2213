#ifndef SORT_IS_H
#define SORT_IS_H
#include "UList.h"

template<class T>
void sort(UList<T>& list)
{
  for(size_t i = 1; i < list.size(); i++)
  {
    if(list.items[i] < list.items[i-1])
    {
      // The item we need to copy into a specific place.
      T temp = list.items[i];

      /* Get the location so we can modify it. We still want to keep
         i for iterating throught the for-loop. */
      int loc = i;

      /* Here, shift all the data to the left since we are
       * planning to insert a value to a location. */
      do
      {
        list.items[loc] = list.items[loc - 1];
        loc--;
      }while(loc > 0 && list.items[loc-1] > temp);

      // Copy the temp into the location
      list.items[loc] = temp;
    }
  }
}

#endif
