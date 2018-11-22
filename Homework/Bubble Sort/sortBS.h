#include "UList.h"

template<class T>
void sort(UList<T>& list)
{
  for(size_t i = 1; i < list.size(); i++)
    for(size_t j = 0; j < list.size()-i; j++)
      if(list.items[j] > list.items[j+1])
        std::swap(list.items[j], list.items[j+1]);
}
