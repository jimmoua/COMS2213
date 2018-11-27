COMS 2213 Assignment 4
======================

## Infix to postfix
We are to first design a stack and queue using the STL container stack and queue so we can use it with converting infix to postfix. After we get infix to postfix correct using the STL containers, design our own stack and queue based from the standard template library.

Example input from a file:
```
A+B;
A
   + C
;
A*B.
```

Example Output after processing file:

```
Infix:   A+B;
Postfix: AB+
Infix:   A+C;
Postfix: AC+
Infix:   A*B.
Postfix: AB*
```

To use the program, the user will have to do something like this:
```
./a.out inputfile outputfile
```

where `inputfile` contains contains of the infix expression. `outputfile` is the file where the the postfix expression is going to be directed to.

## QNodeType header file
This header file only contains a struct that will be used in the queue header file. It acts as a base to our linked list or queue. The struct is templated.

```c++
item: T
next: QNodeType<T>*
```

## queue header file
The queue header file follows the third data structs assignment with linked lists. Most of the code written here will look almost identical to the code written for the linked list assignment. The queue class is a templated class.

```c++
-front_: QNodeType<T>*
-back_: QNodeType<T>*
-count: size_t

+queue()
+queue(const queue<T>&)
+~queue()
+operator=(const queue<T>&): const queue<T>&
+push(const T&): void
+pop(): void
+front() const: const T&
+back() const: const T&
+size() const: size_t
+empty() const: bool
-destroy(): void
-copy(const queue<T>&): void
```

## stack header file
The code for the stack header file is going to look almost identical to the second data structures project, dealing with dynamically allocated lists using a pointer. The stack class is a template class.

```c++
-stack_: *T
-count: size_t
-capacity: size_T

+stack(size_t =10)
+~stack()
+stack(const stack<T>&)
+operator=(const stack<T>&): const stack<T>&
+push(const T&): void
+pop(): void
+size() const: size_t
+empty() const: bool
+top() const: const T
```

## expression header file
The expression header file is where converting from infix to postfix happens.

```c++
-ifix: string
-pfix: string
+last: bool

operator>>(istream&, expression&): istream&
operator<<(ostream&, const expression&): ostream&
-convertToPostfix(): void
-precedence(char, char) const: bool
+expression()
```

## in2pos.cpp
This is going to be the driver file for this program. As per his website, we are the design a driver such that it uses command line arguments. Take the file from the command line argument and then direct the output into a file.

+ a.out
+ inputfile
+ outputfile

The input file contains an infix expression. After converting to postfix, the output will be in the output file.
