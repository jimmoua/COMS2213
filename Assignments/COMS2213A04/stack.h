#ifndef STACK_H
#define STACK_H

#include <ostream>

template<class T>
class stack
{
  public:
    stack(size_t = 10);
    stack(const stack<T>&);
    ~stack();
    const stack<T>& operator=(const stack<T>&);
    void push(const T&);
    bool empty() const;
    const T& top() const;
    size_t size() const;
    void pop();

    // Remove later, needed for testing
    template<class U>
      friend std::ostream& operator<<(std::ostream&, stack<U>&);

  private:
    T* stack_;
    size_t count;
    size_t capacity;
};

template<class T>
std::ostream& operator<<(std::ostream& os, stack<T>& obj)
{
  if(!obj.empty())
  {
    os << obj.stack_[0] << " ";
    for(size_t i = 1; i < obj.count; i++)
      os << ", " << obj.stack_[i];
  }
  return os;
}

/* Function: stack<T>::stack(size_t) ****************************************************
 *
 * Description: User defined constructor of the class. Sets capacity to n and sets the
 *   capacity current count to n. Also allocates memory for the stack of size n.
 *
 * Preconditions: An object of the stack class is instantiated with a size_t parameter
 *   denoted by n.
 *
 * Postconditions: Dynamically allocates room for data type of T with size of n. Modifies
 *   count to 0 and capacity to n.
 *
 * *************************************************************************************/
template<class T>
stack<T>::stack(size_t n)
{
  this->count = 0;
  this->capacity = n;
  this->stack_ = new T[capacity];
}

/* Function: void stack<T>::push(const T&) **********************************************
 *
 * Description: Adds an item to the end of stack.
 *
 * Preconditions: None.
 *
 * Postconditions: An item will be added to the end of the stack. Count will be incremen-
 *   ted by a value of 1.
 *
 * *************************************************************************************/
template<class T>
void stack<T>::push(const T& item)
{
  bool inserted = false;

  /* If the list is full, try allocating new space for it by expanding it twice the
   * amount */
  if(this->count == this->capacity)
  {
    try
    {
      size_t newCapacity = 2*this->count;
      T* temp = new T[newCapacity];
      for(size_t i = 0; i < this->count; i++)
        temp[i] = this->stack_[i];
      delete [] this->stack_;
      this->stack_ = temp;
      inserted = true;
    }
    catch(std::bad_alloc &)
    {
      return;
    }
    if(inserted)
      this->stack_[this->count++] = item;
  }
  /* If the list isn't empty, simply add the item to the end of the list and increment
   * the count of the list */
  else
    this->stack_[this->count++] = item;
}

/* Function: stack<T>::empty() const ****************************************************
 *
 * Description: This is a one-liner function that returns true if the stack is empty and
 *   false if the stack is not.
 *
 * Preconditions: None.
 *
 * Postconditions: Does not modify anything.
 *
 * *************************************************************************************/
template<class T>
bool stack<T>::empty() const { return (this->count == 0); }

/* Function: const T& stack<T>::top() const *********************************************
 *
 * Description: If the stack isn't empty, returns the value of the end of the stack.
 *
 * Preconditions: None.
 *
 * Postconditions: Does not modify anything.
 *
 * *************************************************************************************/
template<class T>
const T& stack<T>::top() const
{
  if(!this->empty())
    return this->stack_[this->count-1];
}

/* Function: void stack<T>::pop() *******************************************************
 *
 * Description: Removes the item from the end of the stack if it isn't empty.
 *
 * Preconditions: None.
 *
 * Postconditions: If the stack was not empty, the count is decremented by a value of 1.
 *
 * *************************************************************************************/
template<class T>
void stack<T>::pop()
{
  if(!this->empty())
    this->count--;
}

/* Function: stack<T>::~stack() *********************************************************
 *
 * Description: The destructor of the class. Once the object of stack class goes out of
 *   scope, the destructor will run and deallocate the list.
 *
 * Preconditions: None.
 *
 * Postconditions: If the stack was not empty, the stack will be deleted and count will be
 *   set to 0.
 *
 * *************************************************************************************/
template<class T>
stack<T>::~stack()
{
  if(!this->empty())
    delete [] this->stack_;
}

/* Function: const stack<T>& stack<T>::operator=(const stack<T>&) ***********************
 *
 * Description: Assignment operator overload that performs a deep copy of the right hand
 *   side into the left hand side.
 *
 * Preconditions: Requires two objects of the stack class.
 *
 * Postconditions: The right hand side of the operator is deep copied into the object in
 *   the left hand side.
 *
 * *************************************************************************************/
template<class T>
const stack<T>& stack<T>::operator=(const stack<T> &src)
{
  /* If the stack isn't empty, we first delete it */
  if(!this->empty())
    delete [] this->stack_;

  /* Copy over the source capacity, source count, and source items via deep copy into
   * "this" stack */
  this->capacity = src.capacity;
  this->count = src.count;
  this->stack_ = new T[this->capacity];
  for(size_t i = 0; i < src.count; i++)
    this->stack_[i] = src.stack_[i];
  return this;
}

/* Function: stack<T>::stack(const stack<T>&) *******************************************
 *
 * Description: This is the copy constructor. It performs a deep copy of a source stack
 *   into the "this" stack.
 *
 * Preconditions: Requires two objects of the stack class.
 *
 * Postconditions: A copy of source stack is deep copied into the "this" stack.
 *
 * *************************************************************************************/
template<class T>
stack<T>::stack(const stack<T>&src)
{
  this->count = 0;
  /* If we aren't copying from the same source, go ahead and perform the deep copy */
  if(&src != this)
  {
    this->capacity = src.capacity;
    this->count = src.count;
    this->stack_ = new T[src.capacity];
    for(size_t i = 0; i < src.count; i++)
      this->stack_[i] = src.stack_[i];
  }
}

/* Function: size_t stack<T>::size() const **********************************************
 *
 * Description: This is another one-liner function that returns the count of how many
 *   items there are in the stack.
 *
 * Preconditions: None.
 *
 * Postconditions: Does not modify anything.
 *
 * *************************************************************************************/
template<class T>
size_t stack<T>::size() const { return this->count; }

#endif
