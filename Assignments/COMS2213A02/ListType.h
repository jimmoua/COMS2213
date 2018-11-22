#ifndef LISTTYPE_H
#define LISTTYPE_H
#include <iostream>
#include <limits>

/*  ********************************************************************************
 *  Class: template<class T> class ListType
 *
 *  Description:
 *  This class is an abstract class. There are two derived classes from this class,
 *  which are an unordered and ordered list.
 *
 *  *******************************************************************************/
template<class T>
class ListType
{
    public:
        ListType(size_t = 10);
        ListType(const ListType<T>&);
        virtual ~ListType();
        const ListType<T> &operator=(const ListType<T>&);
        virtual void eraseAll();
        virtual bool insert(const T&) = 0;
        virtual bool erase(const T&) = 0;
        virtual bool find(const T&) const = 0;
        size_t size() const;
        bool empty() const;
        bool full() const;
        size_t getCapacity() const;
        template<class U>
            friend std::ostream & operator<<(std::ostream&, const ListType<U>&);

        /* Functions for debugging purposes only! Delete later */
    protected:
        T *list;
        size_t capacity;
        size_t count = 0;
    private:
        void copy(const ListType<T>&); /* used by copy ctor and operator overload fn
                                            creates another array */
};

/*  ********************************************************************************
 *
 *  Function: const ListType<T> & ListType<T>::operator=(const ListType<T> & source)
 *
 *  Description:
 *  This function is overloads the = operator so that we can deep copy contents from
 *  another object of the same class.
 *
 *  Preconditions:
 *  The things required for this two instances of a derived class of the ListType
 *  base class.
 *
 *  Postconditions:
 *  This will perform a deep copy by using two objects of the derived classes. The
 *  left hand side of the = will be provided deep copies of whatever object the
 *  right-hand side is. For example, obj1 = obj2 will copy the list contents of obj2
 *  into obj1.
 *
 *  *******************************************************************************/
template<class T>
const ListType<T> &ListType<T>::operator=(const ListType<T> & source)
{
    this->copy(source);
    return this;
}

/*  ********************************************************************************
 *  Function: ListType<T>::ListType(size_t n)
 *  
 *  Description:
 *  This is a user-defined ctor. The default value of n is defaulted to 10 if the
 *  a size is not specified when instantiating an object of the derived classes.
 *
 *  Preconditions:
 *  none
 *
 *  Postconditions:
 *  Dynamically creates a list with a capacity size of n.
 *
 *  *******************************************************************************/
template<class T>
ListType<T>::ListType(size_t n)
{
    count = 0;
    capacity = n;
    list = new T[capacity];
}

/*  ********************************************************************************
 *  Function: 
 *  ListType<T>::ListType(const ListType<T> & source)
 *
 *  Description:
 *  This is a copy constructor. Instead of instatiating an object and setting it
 *  equal to another object, simply use the copy constructor to do something like
 *  this: UListType<int> object2(object1);
 *  This will create an object called object2 and perform a deep copy of object1.
 *
 *  Preconditions:
 *  None.
 *
 *  Postconditions:
 *  None.
 *
 *  *******************************************************************************/
template<class T>
ListType<T>::ListType(const ListType<T> & source)
{
    this->copy(source);
}

/*  ********************************************************************************
 *  Function: void ListType<T>::eraseAll()
 *
 *  Description:
 *  Erases the list.
 *
 *  Preconditions:
 *  None.
 *
 *  Postconditions:
 *  This "erases" the list. We are not actually doing any erasing, but just setting
 *  the size of the list to 0. That way, when we are inserting something, that
 *  value that was inserted will just replace the value.
 *
 *  *******************************************************************************/
template<class T>
void ListType<T>::eraseAll()
{
    this->count = 0;
}

/*  ********************************************************************************
 *  Function: bool ListType<T>::empty() const
 *
 *  Description:
 *  Checks to see if the list is empty.
 *
 *  Preconditions:
 *  None.
 *
 *  Postconditions:
 *  None.
 *
 *  *******************************************************************************/
template<class T>
bool ListType<T>::empty() const
{
    return (count == 0);
}

/*  ********************************************************************************
 *  Function: size_t ListType<T>::size() const
 *
 *  Description:
 *  Returns the current size of the list.
 *
 *  Preconditions:
 *  None.
 *
 *  Postconditions:
 *  None.
 *
 *  *******************************************************************************/
template<class T>
size_t ListType<T>::size() const
{
    return count;
}

/*  ********************************************************************************
 *  Function: bool ListType<T>::full() const
 *
 *  Description:
 *  Returns true if the list is full and false if the list is not full.
 *
 *  Preconditions:
 *  None.
 *
 *  Postconditions:
 *  None.
 *
 *  *******************************************************************************/
template<class T>
bool ListType<T>::full() const
{
    return (count == capacity);
}

/*  ********************************************************************************
 *  Function: ListType<T>::copy(const ListType<T> & source)
 *
 *  Description:
 *  This function is used by the copy constructor and the = operator overload
 *  function.
 *
 *  Preconditions:
 *  None.
 *
 *  Postconditions:
 *  Performs a deep copy with contents from the source.
 *
 *  *******************************************************************************/
template<class T>
void ListType<T>::copy(const ListType<T> & source)
{
    this->capacity = source.capacity;
    this->count = source.count;
    this->list = new T [capacity];
    for(size_t i = 0; i < source.count; i++)
        this->list[i] = source.list[i];
}

/*  ********************************************************************************
 *  Function: ListType<T>::~ListType<T>()
 *
 *  Description:
 *  The virtual destructor.
 *
 *  Preconditions:
 *  None.
 *
 *  Postconditions:
 *  Deletes the dynamically allocated lists once the objects go out of scope.
 *
 *  *******************************************************************************/
template<class T>
ListType<T>::~ListType<T>()
{
    delete [] list;
}

/*  ********************************************************************************
 *  Function: std::ostream & operator<<(std::ostream & os, const ListType<T> & source)
 *
 *  Description:
 *  The << operator is overloaded to print the list. When printing the list with
 *  the << operator, the right hand side must be an an object of the derived class
 *  of ListType. An example is -> std::cout << orderedListObject << std::endl;
 *
 *  Preconditions:
 *  None.
 *
 *  Postconditions:
 *  None. It simply prints and should not modify anything.
 *
 *  *******************************************************************************/
template<class T>
std::ostream & operator<<(std::ostream& os, const ListType<T>& source)
{
    if(!source.empty())
    {
        os << *source.list;
        for(size_t i = 1; i < source.count; i++)
        {
            os << ", " << source.list[i];
            //os << source.list[i] << std::endl;    // For my debugging
        }
    }
    else
        os << "empty!";
    return os;
}
template<class T>
size_t ListType<T>::getCapacity() const { return this->capacity; }

#endif
