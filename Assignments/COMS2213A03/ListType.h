#ifndef LIST_TYPE_H
#define LIST_TYPE_H

#include <ostream>


/* Struct: NodeType
 *
 * Description:
 * This struct will be used in a class. It will act as the base for the linked lists
 *
 * */
template<class T>
struct NodeType
{
    T info;
    NodeType<T> *link;
};


/* class: ListType
 * 
 * Description:
 * This is a pure abstract class. It is, at the core, a linked list. The derived classes
 * are either going to be an unordered linked list or an ordered linked list
 *
 * */
template<class T>
class ListType
{
    public:
        /* Basic functions and ctor and dtor */
        ListType();
        ListType(const ListType<T> &);
        virtual ~ListType();
        const ListType & operator = (const ListType<T> &); // Deep copy
        virtual bool insert(const T &) = 0;             // Pure virtual
        virtual void eraseAll();                        // Used in dtor copy
        void erase(const T &);                          // Erases a node
        bool find(const T &) const;                     // Finds a node (seq search)
        size_t size() const;                            // Returns size
        bool empty() const;                             // Returns true if empty
        /* Friend Function */
        template<class U>
        friend std::ostream & operator << (std::ostream &, const ListType<U> &);

    protected:
        NodeType<T> *head;
        size_t count;

    private:
        void destroy();
        void copy(const ListType<T> &); // Use for deep copy
};


/* Function: ListType()
 *
 * Description:
 * This is the default constructor of the ListType class.
 *
 * Preconditions:
 * A derived class of this parent class must be instantiated for this constructor to be called. This constructor
 * is called via the derived class constructors.
 *
 * Postconditions:
 * Modifies the head to nullptr and sets count to 0. Basically initalizes the list to nothing. (New list should
 * be empty anyways.
 *
 * */
template<class T>
ListType<T>::ListType()
{
    this->head = nullptr;
    this->count = 0;
}

/* Function: ListType(const ListType<T> & src)
 *
 * Description:
 * This is essentially the copy constructor. If another object of the same dervived class is instantiated with
 * another object of the same dervied class, that other object's contents will be deep-copied into the newly
 * instantiated class.
 *
 * Preconditions:
 * A derived class of ListType must be instantiated and a source has to be fed into the parameter of the copy
 * constructor.
 *
 * Postconditions:
 * Performs a deep copy of another object into this one
 *
 * */
template<class T>
ListType<T>::ListType(const ListType<T> & src)
{
    this->head = nullptr;
    this->copy(src);
}

/* Function: operator<<(std::ostream &, const ListType<T> &)
 *
 * Description:
 * This is a function overload where we overload the << operator to print out the contents of whatever
 * is currently inside the list.
 *
 * Preconditions:
 * None
 *
 * Postconditions:
 * Does not modify anything.
 *
 * */
template<class T>
std::ostream & operator << (std::ostream & os, const ListType<T> & obj)
{
    /* First, check if the list is empty */
    if(obj.empty())
    {
        os << "Empty\n";
        return os;
    }
    else
    {
        /* Print the first item on the list and them direct it to the next one */
        os << obj.head->info;
        for(auto iter = obj.head->link; iter != nullptr; iter = iter->link)
            os << ", " << iter->info;
        return os;
    }
}

/* Function: ListType<T>::find(const T&) const
 *
 * Description:
 * This function will attempt to find a value that is given to it as a parameter.
 *
 * Preconditions:
 * A value is fed as a parameter and then the function will perform a search by going from the beginning of
 * the list to the end of list.
 *
 * Postconditions:
 * Does not modify anything
 *
 * */
template<class T>
bool ListType<T>::find(const T & valueToFind) const
{
    /* Create an iterator to traverse... */
    NodeType<T> *iterator = this->head;
    bool found = false;
    while(iterator != nullptr)
    {
        if(iterator->info == valueToFind)
        {
            found = true;
            break;
        }
        else
            iterator = iterator->link;
    }
    return found;
}


/* Function: ListType<T>::empty() const
 * 
 * Description:
 * This function checks to see whether count is 0. If it is, the list is empty, otherwise it is not empty.
 *
 * Preconditions:
 * None;
 *
 * Postconditions:
 * Does not modify anything
 *
 * */
template<class T>
bool ListType<T>::empty() const
{
    return (this->count == 0);
}

/* Function: ListType<T>::size() const
 *
 * Description:
 * This function returns the current size of the list.
 * 
 * Preconditions:
 * None
 *
 * Postconditions:
 * Does not modify anything.
 *
 * */
template<class T>
size_t ListType<T>::size() const
{
    return this->count;
}

/* Function: ListType<T>::copy(const ListType<T> &)
 *
 * Description:
 * This is the copy function. It performs a deep copy of a list into another list.
 *
 * Preconditions:
 * The parameter is the source list. The source list is copied into this list.
 *
 * Postconditions:
 * This list will be a copy of the source list.
 * 
 * */
template<class T>
void ListType<T>::copy(const ListType<T> & source)
{
    /* This is the deep copy function. Private function, but just need for copy ctor and
     * assignment operator overload
     *
     *
     * In order to do a deep copy with linked lists, this function must be provided a source as listed in the
     * parameters. For example, say we have linked list
     * 
     * Source
     * 10  20  30  40  50  60  70  80
     *  ^ <-- head
     *
     * New copied list (Will be relying on this). We will not be caring for whatever the list is, but just in case
     * the current list isn't empty (the one we are copying to), we have to check to see if it's empty first. If it
     * is not empty, we will deallocate all the pointers in it first, and then we can copy the list over.
     *
     * If the list was not empty, invoke the destroy function (private function)
     *
     *  */

    /* If the this->list is not empty, destroy everything from it. */
    if(this->head != nullptr)
    {
        this->destroy();
    }

    /* If the list is empty, just do this */
    if(source.head == nullptr)
    {
        this->head = nullptr;
        this->count = 0;
    }
    else
    {
        /* Copy over the linked list (from source into this). Logic behind this will look something like this:
         *
         * We have a source, as mentioned above...
         * Source
         * 10  20  30  40  50  60  70  80
         *
         * BEGIN COPY
         *
         * This
         *  ↓  <--- This is actually pointing towards null at first since we either deleted the list or it was empty
         * [ ]      to being with.
         *
         * Example Source
         * 10  20  30  40  50  60  70  80
         *
         * We will need an iterator to go through the source list. We also assign the iterator to this value:
         *     iterator = source->head;
         *     ↑ Use this until iterator = source.end() or nullptr
         *
         * 10  ← first element of this->list.info becomes source.info and this->list.link will now link
         *         link to the next.
         *
         * NodeType<T> *link;            <--- Links new data to previous
         * this->head = new NodeType<T>;
         * *this->head = *iterator;      <--- This points to the value of the source
         * iterator = iterator->next;    <--- Allows us to traverse through the list
         *
         * */

        /* First, create an iterator that will allow us to traverse through the source list */
        NodeType<T> *thisListIterator = nullptr;      // Traverses this list
        NodeType<T> *newListIterator = source.head;   // Traverses source list

        /* First, we copy over the head */
        this->head = new NodeType<T>;               // allocate mem for head
        this->head->info = newListIterator->info;   // copy over info
        this->head->link = nullptr;                 // assign this->list->link to nullptr
        newListIterator = newListIterator->link;    // Go to next item in the source
        thisListIterator = this->head;              // Assign thisListIterator to head so we can traverse it in the loop
        this->count = source.count;                 // set count equivalent

        /* While the iterator isn't at end of the source list*/
        while(newListIterator != nullptr)
        {
            thisListIterator->link = new NodeType<T>;       // ← Allocate mem for it first
            thisListIterator = thisListIterator->link;      // ← Then go to it
            thisListIterator->info = newListIterator->info; // ← Assign this->info to source info
            thisListIterator->link = nullptr;               // ← Assign the next in this->list to nullptr
            newListIterator = newListIterator->link;        // ← Go to the next item in the list
        }
    }
}

template<class T>
void ListType<T>::destroy()
{
    /* We need to go through the entire linked list and deallocate everything.
     *
     * Example list
     * 10  20  30  40  50
     * ^ <--- Head
     *
     * First we need to create a pointer that will also point to these heads
     *
     * 10  20  30  40  50
     * ^ <--- Head, but there will be another pointer that is assigned to Head->next
     *
     *      ↓  <--- Our other pointer points to this
     * 10  20  30  40  50
     * ^ <--- Delete this value
     *
     *       ↓  <--- Our other pointer points to this
     * [ ]  20  30  40  50
     *  ^ <--- The head now points to this address, which is garbage is we try to use it now.
     *         So we now need to point the new head pointer to the same as our local pointer, which
     *         should be pointing towards value of 20
     *
     *       ↓  <--- Our other pointer points to this
     * [ ]  20  30  40  50
     *       ^ <--- Repoint the head pointer by some like Head = otherPointer.
     *              Then we reassign the other pointer to somethine like otherPointer = otherPointer->next;
     *              which will then give us this....
     * 
     *           ↓  <--- Our other pointer points to this
     * [ ]  20  30  40  50
     *       ^ <--- The current head
     *
     * We simply repeat the above UNTIL the other pointer is pointing to NULL
     *                           ↓  <--- Our other pointer points to this
     * [ ]  [ ]  [ ]  [ ]  [ ]  NULL
     *                      ^ <--- The current head after deallocation
     *
     * After we've done all of this, we can use an if statement to check whether we've reached end of list:
     *
     *     delete head;
     *     if(otherPointer == nullptr)
     *         break;
     *     else
     *        head = otherPointer;
     *     (...)
     *     Loop it around, or use a loop here → main idea. This isn't my code is going to look, but the concept
     *     is very similar.
     *
     * */

    NodeType<T> * iterator;
    while(this->head != nullptr)
    {
        iterator = this->head;
        this->head = this->head->link;
        delete iterator;
    }
    this->count = 0;
}

/* Function: ListType<T>::~ListType()
 *
 * Description:
 * This is the destructor. Is calls the destroy() function and deallocates all the nodes.
 *
 * Preconditions:
 * None.
 *
 * Postconditions:
 * Delete all nodes. Is called when object of derived class goes out of scope.
 *
 * */
template<class T>
ListType<T>::~ListType()
{
    /* Deallocate everything. We are simply going to traverse throught the list using an iterator that points to the next.
     * Delete the current node, repoint the head node to the iterator and point that iterator again to the next */
    if(!this->empty())
        destroy();
}

/* Function: ListType<T>::erase(const T & valueToErase)
 *
 * Description:
 * This class finds the value to erase and erases it from the, provided that it actually exists
 *
 * Preconditions:
 * The value to be erased from the list must be passed on as a parameter into the function.
 *
 * Postconditions:
 * If the value does exist within the list, it will be removed from the list and count will be decremented
 * by a value of 1. If the value does not exist on the list, nothing will be modified.
 *
 * */
template<class T>
void ListType<T>::erase(const T & valueToErase)
{
    bool erased = false;

    NodeType<T> *thisListIterator = this->head;   // Create an iterator to traverse this list
    NodeType<T> *thisListIteratorPrev = nullptr;  // Points to previous pointer of thisListIterator

    /* This while loop only ran IF the this->head->info isn't valueToErase */
    while (thisListIterator != nullptr && thisListIterator->info != valueToErase)
    {
        thisListIteratorPrev = thisListIterator;   // Points it to thisListIterator
        thisListIterator = thisListIterator->link; // Traverse the next item on thisListIterator.
        if(thisListIterator!= nullptr && thisListIterator->info == valueToErase)
        {
            /* [P]  [D]  [N]
             *  ↑_________↑   Create a link between these two and delete [D]
             *
             *  */

            /* Create the link between [P] and [N] */
            thisListIteratorPrev->link = thisListIterator->link;

            /* Delete the iterator after the link is created and decrement count */
            delete thisListIterator;
            this->count--;
            erased = true;
            break;
        }
    }
    /* If the item needed to be erased was the head of the list... */
    if(!erased && this->head->info == valueToErase)
    {
        this->head = this->head->link;
        delete thisListIterator;
        this->count--;
    }
}

/* Function: ListType<T>::eraseAll()
 *
 * Description:
 * This function erases all nodes. By that definition, all nodes are deallocated via the delete
 * key. Count is set to 0 and the head pointer is set to nullptr.
 *
 * Preconditions:
 * None.
 *
 * Postconditions:
 * Deallocated every node on the linked list and sets count to zero and head pointer to nullptr.
 *
 * */
template<class T>
void ListType<T>::eraseAll()
{
    this->destroy();
    this->count = 0;
    this->head = nullptr;
}

/* Function: ListType<T> *ListType<T>::operator=(const ListType<T> &)
 *
 * Description:
 * This is the operator overload for the assignment operator. It acts similar to the copy
 * constructor, but instead, you can perform a deep copy (this function relies on the
 * copy function for deep-copy) for the object on the left hand side from the object on the
 * right hand side.
 * 
 * Preconditions:
 * A source must be set on the right hand side of the assignment operator for overloading. They also must
 * be derived classes of the ListType class.
 * Example 
 *     A = B;
 *     A now has its own copy of B, assuming that are of both of the same derived class.
 *
 * Postconditions:
 * The left hand side will now have a hard copy of the list on the right hand side, as seen as above.
 *
 * */
template<class T>
const ListType<T> &ListType<T>::operator=(const ListType<T> & source)
{
    /* Check to see if list it is copying is just itself. If not copy, if is → do nothing. */
    if(this != &source)
    {
        this->destroy();
        this->copy(source);
    }
    return *this;
}


#endif
