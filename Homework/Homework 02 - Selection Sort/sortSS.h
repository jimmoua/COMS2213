#include "UList.h"

/*==========================================================
 * Function: void sort(UList<T>&)
 *
 * Description: Sorts a vector using selection sort.
 *
 * Preconditions: None.
 *
 * Postconditions: Modifies the vector such that items are
 *   sorted from low to high.
 * =======================================================*/
template<class T>
void sort(UList<T>& list)
{
  /* Say we have an unordered list of integers.
   * [23] [19] [42] [01] [68]
   *
   * Selection sort will "select" the lowest value in the
   * list and move it to a specific part within the list.
   * For example, in the list above, the smallest value in
   * the list is 1, so we go through the list and we will
   * eventually select 1.
   * [23] [19] [42] [01] [68]
   *   ↑              ↑ selected
   *   front          After selection, move swap with front.
   *
   * 01 is swapped with 23, but now the list is divded in
   * such a way like this:
   *
   *     |
   * [01]|[19] [42] [23] [68]
   *     |  ↑      
   *        front (The back/front of the ordered list is 01)
   *
   * If we wanted to sort the 19, we still have to compare
   * it with every other value within the list first. But
   * since 19 is the lowest in the list, we just simply leave
   * it there and denote the new "back" of the sorted list.
   *
   *          |
   * [01] [19]|[42] [23] [68]
   *          |  ↑     
   *             front (Here, 19 is the back of the ordered
   *                    list)
   *
   * Since the lowest value in the unordered list is 23,
   * it will be selected evetually and then swapped to
   * be the back of the ordered list.
   *
   *               |
   * [01] [19] [23]|[42] [68]
   *               |  ↑     
   *                  front of unordered
   *                  (23 is the back of the ordered list)
   * 
   * Above, the list is already sorted, but the algorithm does
   * not know that yet because it will still be iteratoring until
   * the array is no longer "divided" into two groups.
   *
   *                    |
   * [01] [19] [23] [42]|[68]
   *                  ↑ |   
   *                  back of ordered, and since there is
   *                  only one element left, everything is
   *                  now sorted.
   * 
   * */
  for(size_t i = 0; i < list.items.size()-1; i++)
  {
    size_t min = i;
    for(size_t j = i+1; j < list.items.size(); j++)
    {
      if(list.items[min] > list.items[j])
        min = j;
      std::swap(list.items[min], list.items[i]);
    }
  }
}
