/* ----------------------------------------------------------------------------
 * Jim Moua
 *
 * Due: 2018 November 30
 *
 * Description:
 *   Contains functions that use quick sort to sort a vector.
 *
 * Special Processing Requirements:
 *   None.
 * --------------------------------------------------------------------------*/
#ifndef SORT_QS_H
#define SORT_QS_H
#include "UList.h"

/* ----------------------------------------------------------------------------
 * Function:
 *   int partition(std::vector<T>, int first, int last)
 *
 * Description:
 *   This function will get the index point of where to partition the vector
 *   list. This index is essentially used to "split" the vector into two
 *   vectors such that there is a lower vector and an upper vector.
 *
 * Preconditions:
 *   The first argument passed in is the vector. The second and third arguments
 *   are the beginning and the end elements of the partitioned vector.
 *
 * Postconditions:
 *   The returned value is the index location of the pivot. This is used for
 *   the other recursive quick sort functions. The partition is also sorted via
 *   comparison with the pivot index value.
 * --------------------------------------------------------------------------*/
template<class T>
int partition(std::vector<T>& src, int first, int last)
{
  /* First, we swap the first element of the partitioned vector with the middle
   * of the partitioned vector. This is essentially just swapping the first
   * element with the pivot, in which pivot is just the middle. */
  std::swap(src[first], src[ (first+last)/2 ]);
  T pivot = src[first];
  int smallIndex = first;

  /* We will start the second element of the partioned vector and iterate
   * through it sequentially and compare elements of the vector to each other.
   * If the current element of the vector is less than pivot, we will increment
   * the smallIndex and then swap them. */
  for(int i = first+1; i <= last; i++)
    if(src[i] < pivot)
      std::swap(src[++smallIndex], src[i]);

  // We then swap the pivot the vector element smallIndex.
  std::swap(src[first], src[smallIndex]);

  // The function will then return this index location so the recursive quick
  // sort may use it again.
  return smallIndex;
}

/* ----------------------------------------------------------------------------
 * Function:
 *   void qsortRecursive(std::vector<T>&, int, int)
 *
 * Description:
 *   If there is more than one item within the vector, this function will do a
 *   recursive quick sort function. It will sort the vector via recursion and
 *   stops when the pivot is at a certain index.
 *
 * Preconditions:
 *   The first argument is the vector. This vector is obtained from the friend
 *   function, since the friend function has access to the private vector. The
 *   second argument is essentially the pivot point of the vector when it has
 *   been partitioned. The third argument is the last element of the
 *   partitioned vector.
 *
 * Postconditions:
 *   The vector will be sorted.
 *
 * --------------------------------------------------------------------------*/
template<class T>
void qsortRecursive(std::vector<T>& src, int first, int last)
{
  int pivotLoc;
  if(first < last)
  {
    pivotLoc = partition(src, first, last);
    qsortRecursive(src, first, pivotLoc-1);
    qsortRecursive(src, pivotLoc+1, last);
  }
}

/* ----------------------------------------------------------------------------
 * Function:
 *   sort(UList<T>&)
 *
 * Description:
 *   This invoked the recursive quick sort function.
 *
 * Preconditions:
 *   The argument passed in is an object that belongs to the UList class. Since
 *   this is a friend function, we can pass the actual list within the vector
 *   that contains the value into the recursive quick sort function.
 *
 * Postconditions:
 *   Sorts the vector's container items from low to high.
 * --------------------------------------------------------------------------*/
template<class T>
void sort(UList<T>& src)
{
  qsortRecursive(src.items, 0, src.size()-1);
}

#endif
