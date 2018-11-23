COMS 2213 Assignment 03
================================
This assignment is similar to the second assignment, but instead of dealing with array-based list, we are dealing with a linked list.

What is a linked list?
+ In an array or array based list, each item (in memory) is right next to each other. Therefore, we if wanted to go to the next item in an array, we could simply do this

```c++
#include <iostream>
int main()
{
  int array[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int* ptrArray = array;
  for(size_t i = 0; i < 10; i++)
  {
    // Print out the array using a pointer and moving the pointer to the next memory address.
    std::cout << (*ptrArray)++ << std::endl;
  }
  return 0;
}
```
and that would output
```
1
2
3
4
5
6
7
8
9
10
```
