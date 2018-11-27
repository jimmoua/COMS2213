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

### Inserting
If we have an item to insert, and we already have the given list
and another value of 10, this means:

Value to insert: 10

```
   [10]    This is the current tree.
  /    \
[NP]  [NP]
```

If we want to insert a value of 10, we will have to create
an an iterator and then insert the iterator into the tree.
Since 10 is just a duplicate value, we will simply say that
it is the parent and then move the test of the tree down by
repointing things.

Here, we are wanting to insert the value 10. So to do that, we have to traverse the tree. Since 10 is greater than or equal to the root node 10, we go right and since the right is `nullptr`, we can allocate memory for it.
```
[10]
      [10] ← Current root (or parent)
     /    \
   [NP]  [NP]
```


Then we can reroute some pointers
```
    [10] 
   /    \
 [NP]  [10] ← Inserted here (for duplicate values insert right)
       /  \
     [NP][NP]
```

Even if we had a heavily populated list already, things would still be similar.
```
Value to insert: 28

            [11]
            /  \
           /    \
          /      \
         /        \
      [06]       [19]
      /  \       /  \
     /    \     /    \
   [04]  [08] [17]  [43]
     \      \       /  \
    [05]   [10]   [31][49]
```
This means that the value 28 needs to be inserted to the left 
of 31. When traversing for
insert, we will eventally get to the point where we are at the
node that holds item 31. Once there, insert 28 to the left of
31 since 28 is less than 31.

**Example Code**
```
if(item >= obj->item)
  insert(item, obj->right;
else if(item <= obj->item)
  insert(item, obj->left);
else
  // The only option left is nullptr
  // So need to allocate memory for it
```
Notice in the example code how we descend down first. This is because we want to check the right first, because if it's equal to right, traverse the right. We want items greater than or equal to on the right, not the left.
```
           [11]                             [11]
           /  \                             /  \
          /    \                           /    \
         /      \                         /      \
        /        \                       /        \
     [06]       [19]                  [06]       [19]
     /  \       /  \                  /  \       /  \
    /    \     /    \                /    \     /    \
  [04]  [08] [17]  [43]            [04]  [08] [17]  [43]  
    \      \       /  \              \      \       /  \
   [05]   [10]   [31][49]           [05]   [10]   [31][49]
                 /                                /
               [NP]       Value inserted here → [28]
                ↑        ----------------------------
                It gets here eventually, and when it does, we
                will allocate memory for it.


What if we had a duplicate item needed to be inserted, but it
 isn't the root node this time?

   Item to insert: 43


           [11]                             [11]
           /  \                             /  \
          /    \                           /    \
         /      \                         /      \
        /        \                       /        \
     [06]       [19]      ------>     [06]       [19]
     /  \       /  \                  /  \       /  \
    /    \     /    \                /    \     /    \
  [04]  [08] [17]  [43]            [04]  [08] [17]  [43]
    \      \       /  \              \      \       /  \
   [05]   [10]   [31][49]           [05]   [10]   [31][49]

----------------------------------------------------------------


           [11]                             [11]
           /  \                             /  \
          /    \                           /    \
         /      \                         /      \
        /        \                       /        \
     [06]       [19]      ------>     [06]       [19]
     /  \       /  \                  /  \       /  \
    /    \     /    \                /    \     /    \
  [04]  [08] [17]  [43]            [04]  [08] [17]  [43]
    \      \       /  \              \      \       /  \
   [05]   [10]   [31][49]           [05]   [10]   [31][49]
                                                      /
                                                    [43]
                         The value is inserted here  ↑↑
```
