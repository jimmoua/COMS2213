# Data Structures Assignment 02
Dealing with unordered and ordered list types by using implementing sequential methods and binary insert/searches depending on the type of list.

### Files
##### ListType
ListType is a templated abstract class. Derived classes are UListType and OListType.
```c++
#*list: T
#capacity: size_t
#count: size_t

+ListType(size_t =10)
+ListType(const ListType<T>&)
+~ListType(): virtual
+operator=(const ListType<T>&): const ListType<T>&
+insert(const T&)=0: virtual bool
+eraseAll(): virtual void
+erase(const T&)=0: virtual bool
+find(const T&) const=0: virtual bool
+size() const: size_t
+empty() const: bool
+full() const: bool
-copy(const ListType<T>&): void
operator << (ostream&, const ListType<U>&): ostream&
```

##### UListType
UListType is a templated class. Is a derived class from ListType.
```c++
+UListType(size_t =10)
+insert(const T&): bool
+erase(const T&): bool
+find(const T&) const: bool
```
 For inserting, we just append it to the end of the list. Searching is done through a sequential search. Erasing is using a sequential sort and then removing it. I chose to shift the array after the sort, but you can also just swap it with the back item of the list and decrement the count of the list by one.

##### OListType
OListType is a templated class. Is a derived class from ListType.
```c++
+UListType(size_t =10)
+insert(const T&): bool
+erase(const T&): bool
+find(const T&) const: bool
```
I implemented a binary insertion sort, but Dr. Hoelzeman said that the sequential sort would be fine as well. For the search function, implement a binary search. Erasing is almost the same as the insert, but instead of inserting, we will be removing the item from the list.
