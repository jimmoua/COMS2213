Data Struct Homework
====================
This repository contains the homework assignment of data structures class or COMS 2213. All the code is written in C++ and is compiled using GNU's C++ compiler. The homeworks and assignment for this class use the standard C++11.

All the homeworks are going to be the same header file. The UML code for the template is this:
```c++
#items: vector<T>

+UList(size_t=10)
+insert(const T&): void
+erase(const T&): bool
+find(const T&) const: bool
+size() const: size_t
+empty() const: bool
+friend operator << (ostream&, const UList<U>&): ostream&
+friend sort (UList<U>&): void
```
#### Homework #1 (Bubble Sort)
For this assignment you will create a stand-alone function, sort, that takes an UList<T> parameter and sorts it using the Bubble Sort algorithm. This sort function is to be placed in a file named sortBS.h and UList should be in a file named UList.h. The UML diagram for UList is given below:
Need to submit two files
+ sortBS.h
+ UList.h

#### Homework #2 (Selection Sort)
For this assignment you will create a stand-alone function, sort, that takes an UList<T> parameter and sorts it using the Selection Sort algorithm. This sort function is to be placed in a file named sortSS.h and UList should be in a file named UList.h. Use your UList.h from Homework 1.
Need to submit two files
+ sortSS.h
+ UList.h

#### Homework #3 (Insertion Sort)
For this assignment you will create a stand-alone function, sort, that takes an UList<T> parameter and sorts it using the Insertion Sort algorithm. This sort function is to be placed in a file named sortIS.h and UList should be in a file named UList.h. Use your UList.h from Homework 1.
Need to submit two files
+ sortIS.h
+ UList.h

#### Homework #4 (Quick Sort)
For this assignment you will create a stand-alone function, sort, that takes an UList<T> parameter and sorts it using the Quick Sort algorithm. This sort function is to be placed in a file named sortQS.h and UList should be in a file named UList.h. Use your UList.h from Homework 1.
Need to submit two files
+ sortQS.h
+ UList.h

