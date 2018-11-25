#ifndef BST_TYPE_H
#define BST_TYPE_H
#include "BTNodeType.h"
#include <cstddef>
#include <ostream>

enum TravType { PRE, POST, IN };

template<class T>
class BSTType
{
  public:
    BSTType();
    BSTType(const BSTType<T>&);
    const BSTType<T>& operator=(const BSTType<T>&);
    virtual ~BSTType();
    bool empty() const;
    void erase(const T&);
    bool find(const T&) const;
    void insert(const T&);
    size_t size() const;
    void traverse(std::ostream&, TravType) const;
  protected:
    BTNodeType<T>* root;
    size_t count;
  private:
    void copy(BTNodeType<T>*&, BTNodeType<T>*);
    void destroy(BTNodeType<T>*&);
    void erase(const T&, BTNodeType<T>*&);
    bool find(const T&, BTNodeType<T>*) const;
    void inorder(std::ostream&, BTNodeType<T>*) const;
    void insert(const T&, BTNodeType<T>*&);
    void postorder(std::ostream&, BTNodeType<T>*) const;
    const T& predecessor(BTNodeType<T>*);
    void preorder(std::ostream&, BTNodeType<T>*) const;
};

/* ------------------------------------------------------------------
 * Function:
 *   BSTType<T>::BSTType()
 *
 * Description:
 *   The default constructor of the class.
 *
 * Preconditions:
 *   An object of the BSTType class as instantiated
 * without any passing on any parameters to imply that there exists a
 * user-defined constructor.
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // public
BSTType<T>::BSTType()
{
  count = 0;
  root = nullptr;
}

/* ------------------------------------------------------------------
 * Function:
 *   BSTType<T>::BSTType(const BSTType<T>&)
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // public
BSTType<T>::BSTType(const BSTType<T>& src)
{
  // copy ctor
}

/* ------------------------------------------------------------------
 * Function:
 *   const BSTType<T>& BSTType<T>::operator=(const BSTType<T>&)
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // public
const BSTType<T>& BSTType<T>::operator=(const BSTType<T>& src)
{
  // Assignment operator overload for deep copy
}

/* ------------------------------------------------------------------
 * Function:
 *   BSTType<T>::~BSTType()
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // public
BSTType<T>::~BSTType()
{
}

/* ------------------------------------------------------------------
 * Function:
 *   bool BSTTyppe<T>::empty() const
 *
 * Description:
 *   This function returns a bool value. The returned bool
 *   value is true if the tree is empty. If the returned bool value
 *   is false, there exists items in the tree.
 *
 * Preconditions: None.
 *
 * Postconditions: None.
 * ----------------------------------------------------------------*/
template<class T> // public
bool BSTType<T>::empty() const { return (this->count == 0); }

/* ------------------------------------------------------------------
 * Function:
 *   BSTType<T>::empty() const
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // public
void BSTType<T>::erase(const T& item)
{
}

/* ------------------------------------------------------------------
 * Function:
 *   BSTType<T>::find(const T&) const
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // public
bool BSTType<T>::find(const T& item) const
{
}

/* ------------------------------------------------------------------
 * Function:
 *   BSTType<T>::insert(const T&)
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // public
void BSTType<T>::insert(const T& item)
{
}

/* ------------------------------------------------------------------
 * Function:
 *   size_t BSTType<T>::size() const
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // public
size_t BSTType<T>::size() const { return this->count; }

/* Begin Private function implementations */

/* ------------------------------------------------------------------
 * Function:
 *   void BSTType<T>::copy(BTNodeType<T>&, BTNodeType<T>&)
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // private
void BSTType<T>::copy(BTNodeType<T>*& obj1, BTNodeType<T>* obj2)
{
}

/* ------------------------------------------------------------------
 * Function:
 *   void BSTType<T>::destroy(BTNodeType<T>*&)
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // private
void BSTType<T>::destroy(BTNodeType<T>*& obj)
{
}
  
/* ------------------------------------------------------------------
 * Function:
 *   void BSTType<T>::erase(const T&, BTNodeType<T>*&)
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // private
void BSTType<T>::erase(const T& item, BTNodeType<T>*& obj)
{
}

/* ------------------------------------------------------------------
 * Function:
 *   bool BSTType<T>::find(const T&, BTNodeType<T>*) const
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // private
bool BSTType<T>::find(const T& item, BTNodeType<T>* obj) const
{
}

/* ------------------------------------------------------------------
 * Function:
 *   void BSTType<T>::inorder(std::ostream&, BTNodeType<T>*) const
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // private
void BSTType<T>::inorder(std::ostream&, BTNodeType<T>*) const
{
}

/* ------------------------------------------------------------------
 * Function:
 *   void BSTType<T>::insert(const T&, BTNodeType<T>*&)
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // private
void BSTType<T>::insert(const T& item, BTNodeType<T>*& obj)
{
}

/* ------------------------------------------------------------------
 * Function:
 *   void BSTType<T>::postorder(std::ostream&, BTNodeType<T>*) const
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // private
void BSTType<T>::postorder(std::ostream& os, BTNodeType<T>* obj) const
{
}

/* ------------------------------------------------------------------
 * Function:
 *   const T& BSTType<T>::predecessor(BTNodeType<T>*)
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // private
const T& BSTType<T>::predecessor(BTNodeType<T>* obj)
{
}

/* ------------------------------------------------------------------
 * Function:
 *   void BSTType<T>::preorder(std::ostream&, BTNodeType<T>*) const
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // private
void BSTType<T>::preorder(std::ostream& os, BTNodeType<T>* obj) const
{
}

#endif
