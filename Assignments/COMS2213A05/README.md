COMS2213 Assignment 05
======================
### Assignment description
>Name your files `BTNodeType.h` and `BSTType.h`. In addition to the above, you will need to create an enumerated data type in `BSTType.h`. This enumerated data type should be declared as `TravType` with values of `PRE`, `POST`, and `IN`. You also need to create a driver program that should illustrate that every method was tested. Your driver program should be named `Program05.cpp`. Since I will also be using my own driver program to perform testing of your code, it is critical that all of the public and protected members are declared and implemented as given in the above UML diagrams. Private members can be modified or left out as long as the public and protected members behave as expected. (You'll likely make it more difficult on yourself if you choose to leave out the private methods given...)
This assignment is going to deal with using a binary search tree on a linked list. This assignment is probably the most difficult of all of them. The UML diagram is given as such:

### UML Diagrams

**BTNodeType**

This is a templated `struct`.
```c++
T item;
BTNodeType<T> *left;
BTNodeType<T> *right;
```

**BSTType**

This is a templated `class`.
```c++
#*root:BTNodeType<T>
#count:size_t

+BSTType()
+BSTType(const BSTType<T>&)
+operator=(const BSTType<T>&): const BSTType<T>&
+~BSTType()
+empty() const: bool
+erase(const T&): void
+find(const T&) const: bool
+insert(const T&): void
+size() const: size_t
+traverse(std::ostream&, TravType) const: void
-copy(BTNodeType<T>*&, BTNodeType<T>*):void
-destroy(BTNodeType<T>*&): void
-erase(const T&, BTNodeType<T>*&):void
-find(const T&, BTNodeType<T>*) const:bool
-inorder(std::ostream&, BTNodeType<T>*) const:void
-insert(const T&, BTNodeType<T>*&): void
-postorder(std::ostream&, BTNodeType<T>*) const:void
-predecessor(BTNodeType<T>*): const T&
-preorder(std::ostream&, BTNodeType<T>*) const:void
```


In short, we will be needing
+ An enumerated data type for traveling.
+ Our own driver file (in case something goes wrong).

### Root Node
Notice how in the above UML diagram, we have two `protected` members: `BTNodeType<T>* root` and `size_t count`. Most of the class functions will have to deal with `root` pointer This is very important because `root` is used to traverse our tree.

### Recursion
Recursion is basically when a function invokes itself. This program will be dealing heavily with recurrsion for the any functions that traverses the tree.
