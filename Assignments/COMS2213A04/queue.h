#ifndef QUEUE_U
#define QUEUE_U

#include <cstddef>
#include "QNodeType.h"
#include "expression.h"
#include <ostream>

template<class T>
class queue
{
  public:
    queue();
    queue(const queue<T>&);
    ~queue();
    const queue<T>& operator=(const queue<T>&);
    void push(const T&);
    void pop();
    T& front() const;
    const T& back() const;
    size_t size() const;
    bool empty() const;

    // Remove later
    template<class U>
      friend std::ostream& operator<<(std::ostream&, queue<U>&);
  private:
    void destroy();
    void copy(const queue<T>&);
    size_t count;
    QNodeType<T>* front_;
    QNodeType<T>* back_;
};

template<class T>
std::ostream& operator<<(std::ostream& os, queue<T>& obj)
{
  if(!obj.empty())
  {
    QNodeType<T>* iter = obj.front_;
    os << iter->item;
    iter = iter->next;
    while(iter != nullptr)
    {
      std::cout << ", " << iter->item;
      iter = iter->next;
    }
  }
  return os;
}

/* Function: queue<T>::queue() **********************************************************
 *
 * Description: This is the default constructor of the class. It "sets up" things before
 *   things are actually ran by modifying the front and back to nullptr.
 *
 * Preconditions: An object of class queue is instantiated, thus calling this default
 *   constructor.
 *
 * Postconditions: The front_ and back_ pointers are set to nullptr and the current count
 *   of the list if set to 0. This denotes that the list is empty.
 *
 * *************************************************************************************/
template<class T>
queue<T>::queue()
{
  this->front_ = nullptr;
  this->back_ = nullptr;
  this->count = 0;
}

/* Function: queue<T>::queue(const queue<T>&) *******************************************
 *
 * Description: This is a copy constructor. It relies on the copy function to perform a
 *   deep copy of another queue.
 *
 * Preconditions: Must require at least two different objects of the same queue class.
 *   Copy them as you would instantiated the second object and passing a source queue
 *   into the parameter.
 *
 * Postconditions: A (deep) copy of the source is copied into the new object.
 *
 * *************************************************************************************/
template<class T>
queue<T>::queue(const queue<T>& src)
{
  this->back_ = this->front_ = nullptr;
  this->count = 0;
  this->copy(src);
}

/* Function: queue<T>::~queue() *********************************************************
 *
 * Description: This is the destructor of the queue class. It will delete all the
 *   pointers of the class. Essentially, it traverses front_ to back_, deleting and
 *   freeing memory as it goes.
 *
 * Preconditions: The object of the queue class must go out of scope.
 *
 * Postconditions: Will deallocate the memory that was allocated for the pointers
 *
 * *************************************************************************************/
template<class T>
queue<T>::~queue()
{
  if(!this->empty())
    this->destroy();
}

/* Function: const queue<T> &queue<T>::operator(const queue<T>&) ************************
 *
 * Description: This assignment operator overload function will perform a deep copy
 *   using the copy function.
 *
 * Preconditions: Requires two objects of the queue class.
 *
 * Postconditions: Preforms a deep copy of a queue from the right hand side to the left
 *   hand side.
 *
 *   Example:
 *   obj1 = obj2;
 *     will deep copy contents of obj2 into obj1.
 *
 * *************************************************************************************/
template<class T>
const queue<T> &queue<T>::operator=(const queue<T>& src)
{
  if(this != &src)
    this->copy(src);
  return *this;
}

/* Function: void queue<T>::copy(const queue<T>& ) **************************************
 *
 * Description: This is the copy function.
 *
 * Preconditions: Requires at least two objects of the queue class.
 *
 * Postconditions: Performs a deep copy of a source queue into another.
 *
 * *************************************************************************************/
template<class T>
void queue<T>::copy(const queue<T>& src)
{
  /* if queue not empty, destroy it */
  if(!this->empty())
    this->destroy();

  /* If empty queue, then not much to do. Assign the front and back pointers to nullptr
   * and then set count to 0 */
  if(src.front_ == nullptr)
  {
    this->front_ = nullptr;
    this->back_ = nullptr;
    this->count = 0;
  }
  /* if queue no empty, begin copy starting with front */
  else
  {

    /* Similar to the linked list copy function. We will have an iterator to
     * traverse this queue list and an itereator to traverse the source list.
     * Once we have those two iterators, we simply copy over the head, and then
     * once we copy over the head, we will check to see if there are any more
     * items within the source queue that needs to be copied over as well.
     * If there is, we will keep copying until nullptr. If there isn't, we
     * will not copy anymore.
     *
     * The copy will look very similar to the linked lists one. Below is going
     * to be what happens in the algorithm.
     *
     * Example source
     *     [38] [12] [32] [19] [23] [N]
     *       
     *     This queue
     *     [N]
     *      ↑
     *      front_ and back_ are both nullptr since it's empty.
     *   
     * When we perform the first copy (copy of head), the list should now look
     * like this:
     *
     *     Source queue
     *     [38] [12] [32] [19] [23] [N]
     *    
     *     This queue
     *     [38] [N]
     *       ↑   ↑ nullptr
     *       front_ and back_
     * 
     * Since there is still something in the list, we need to allocate memory
     * as we go until we hit the nullptr of the source list. After copying the
     * second list, the list should now like this:
     *
     *     Source queue
     *     [38] [12] [32] [19] [23] [N]
     *    
     *     This queue
     *     [38] [12] [N]
     *       ↑    ↑   ↑ nullptr
     *       ↑    back_
     *       front_
     * 
     * As we copy, we will reassign the back_ pointer to the newly copied item
     * until the nullptr of the source pointer has reached nullptr. The end
     * copy could look something like this now:
     *     Source queue
     *     [38] [12] [32] [19] [23] [N]
     *    
     *     This queue
     *     [38] [12] [32] [19] [23] [N]
     *       ↑                   ↑   ↑ nullptr
     *       ↑                   back_
     *       front_
     */

    /* Create two iterators for "this" and the source queue */
    QNodeType<T>* thisIter = nullptr;
    QNodeType<T>* srcListIter = src.front_;

    /* Start by copying over front */
    this->front_ = new QNodeType<T>;
    this->front_->item = srcListIter->item;
    this->front_->next = nullptr;
    srcListIter = srcListIter->next;
    thisIter = this->front_;

    /* Assign back_ to front_ since there is only one item in the queue so far */
    this->back_ = this->front_;

    while(srcListIter != nullptr)
    {
      thisIter->next = new QNodeType<T>;
      thisIter = thisIter->next;
      thisIter->item = srcListIter->item;
      thisIter->next = nullptr;
      srcListIter = srcListIter->next;

      /* Assign back_ to the list item copied to to the queue */
      this->back_ = thisIter;
    }
  }

  /* Copy over count */
  this->count = src.count;
}

/* Function: const T& queue<T>::back() const ********************************************
 *
 * Description: Returns the value at the very back of the queue.
 *
 * Preconditions: None.
 *
 * Postconditions: Does not modify anything.
 *
 * *************************************************************************************/
template<class T>
const T& queue<T>::back() const
{
  if(!this->empty())
    return this->back_->item;
}

/* Function: T& queue<T>front() const ***************************************************
 *
 * Description: Returns the value at the very front of the queue. This is also what I
 *   consider infamous one-liner functions.
 *
 * Preconditions: None.
 *
 * Postconditions: Does not modify anything.
 *
 * *************************************************************************************/
template<class T>
T& queue<T>::front() const { return this->front_->item; }

/* Function: void queue<T>::push(const T&) **********************************************
 *
 * Description: Pushed an item into the queue and increments the count by 1.
 *
 * Preconditions: None.
 *
 * Postconditions: Modifies the queue such that the pushed in item becomes the back_.
 *   This will also increment the count of the list.
 *
 * *************************************************************************************/
template<class T>
void queue<T>::push(const T& item)
{
  if(this->empty())
  {
    /* If the "this" queue is empty, then we will allocate new memory for it. This
     * means that front_ is going to be the same as back_, and we will simply set
     * back_->next to be nullptr.
     *
     * The queue, when it's empty and we want to push something should look something
     * like this:
     *
     * Item to push: 8
     *
     * Example queue
     * [N]
     *  ↑ nullptr
     *
     * After pushing item 8
     * [8] [N]
     *  ↑   ↑ nullptr
     *  ↑ front_ and back_
     *
     * */

    this->back_ = new QNodeType<T>;
    this->back_->item = item;
    this->back_->next = nullptr;
    this->count++;
    this->front_ = this->back_;
  }
  else
  {
    /* If there is already an item within the list, that means we need to allocate the
     * back_->next to a new QNodeType.
     *
     * Value to push: 4
     *
     * Example list
     * [5] [N]
     *  ↑ front_ and back_
     *
     * We set the [N] (nullptr) to a new node.
     *
     * Example queue
     * [5] [4] [N]
     *  ↑   ↑
     *  ↑   back_
     *  front_
     *
     *  After pushing an item, back_ points to the new node location and it's next is
     *  set to a nullptr.
     * */

    this->back_->next = new QNodeType<T>;
    this->back_->next->item = item;
    this->back_ = this->back_->next;
    this->back_->next = nullptr;
    this->count++;
  }
}

/* Function: void queue<T>::pop() *******************************************************
 *
 * Description: Removes the front of the list and repoints front_
 *
 * Preconditions: The list must not be empty if wanting to pop.
 *
 * Postconditions: If the pop is successful, the front_ pointer is going to be repointed
 *   front_next. Count is decremented by 1. If the count in the queue is 1, this meants
 *   front_ is the same as back_.
 *
 * *************************************************************************************/
template<class T>
void queue<T>::pop()
{
  if(!this->empty())
  {
    QNodeType<T>* iter = this->front_;
    this->front_ = this->front_->next;
    delete iter;
    this->count--;
  }
}

/* Function: bool queue<T>::empty() const ***********************************************
 *
 * Description: This function returns true if the queue is empty. If the queue is not
 *   empty, the function returns false.
 *
 * Preconditions: None.
 *
 * Postconditions: Does not modify anything.
 *
 * *************************************************************************************/
template<class T>
bool queue<T>::empty() const
{
  return(this->count == 0);
}

/* Function: void queue<T>::destroy() ***************************************************
 *
 * Description: Will pop the queue until everything is removed from it.
 *
 * Preconditions: The queue has to have items for the destroy function to pop items from
 *   the front.
 *
 * Postconditions: Will remove everything from the queue and set count to 0.
 *
 * *************************************************************************************/
template<class T>
void queue<T>::destroy()
{
  while(!this->empty())
    this->pop();
}

/* Function: size() const ***************************************************************
 *
 * Description: Returns the how many items there are in the queue.
 *
 * Preconditions: None.
 *
 * Postconditions: Nothing is modified.
 *
 * *************************************************************************************/
template<class T>
size_t queue<T>::size() const { return this->count; }

#endif
