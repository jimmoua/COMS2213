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
 *   An object of the BSTType class is instantiated without any
 *   parameters.
 *
 * Postconditions:
 *   Sets the root node and its left and rode node to nullptr. Also
 *   sets the count of the tree to 0.
 * ----------------------------------------------------------------*/
template<class T>
BSTType<T>::BSTType()
{
  count = 0;
  root = nullptr;
  root->left = nullptr;
  root->right = nullptr;
}

/* ------------------------------------------------------------------
 * Function:
 *   BSTType<T>::BSTType(const BSTType<T>&)
 *
 * Description:
 *   The copy constructor. Performs deep copy.
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T>
BSTType<T>::BSTType(const BSTType<T>& src)
{
  // copy ctor
}

/* ------------------------------------------------------------------
 * Function:
 *   const BSTType<T>& BSTType<T>::operator=(const BSTType<T>&)
 *
 * Description:
 *   The assignment operator overload. Performs deep copy.
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
 *   Destructor of the class. Traverses the tree and deallocates
 *   everything that was dynamically allocated.
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
 *   BSTType<T>::erase(const T&)
 *
 * Description:
 *   This function will remove an item from the tree.
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
  /* Since the tree is ordered from values low → high, we are going
   * to compare the item of the left/right node to the item that is
   * to be searched for. If the item is greater than the left node,
   * we should obviously search by traversing the right branches, but
   * if the value is less than or equal to the left node, then we
   * should traverse the left branches. However, we need to check
   * what item the root node holds. If the item matches the item that
   * the root node holds, then we don't need to do any traversal. We
   * simply return that it has been found */
  if(empty())
    return false;
  else
  {
    if(root->item == item)
      return true;
    else if(root->left != nullptr && root->item <= root->left->item)
      find(item, root->left);
    else if(root->right != nullptr)
        find(item, root->right);
    else
      return false;
  }
}

/* ------------------------------------------------------------------
 * Function:
 *   bool BSTType<T>::find(const T&, BTNodeType<T>*) const
 *
 * Description:
 *   Find function that is used for recurrsion.
 *
 * Preconditions:
 *   The find(const T&) is invoked.
 *
 * Postconditions:
 *   Does not modify anything.
 * ----------------------------------------------------------------*/
template<class T>
bool BSTType<T>::find(const T& item, BTNodeType<T>* obj) const
{
  if(obj->item == item)
    return true;
  else if(obj->left != nullptr && obj->item <= obj->left->item)
    find(item, obj->left);
  else if (obj->right != nullptr)
    find(item, obj->right);
  else
    return false;
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
  /* Here, an item needs to be inserted. When the insert function is
   * first invoked, it will check to see if the root node is nullptr.
   * If the root node is nullptr, dynamically allocate memory for it
   * and then set the root->item to the item that is going to be
   * inserted into the tree.
   *
   * If the list, however, is not empty, then traverse the tree
   * similar to the find function, and then insert where necessary */
  if(root == nullptr)
  {
    root = new BTNodeType<T>;
    root->item = item;
    count++;
  }
  else if(item < root->item)
  {
    insert(item, root->left);
  }
  else if(item > root->item)
    insert(item, root->right);
  else
  {
  }
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
  if(obj == nullptr)
  {
    // If the obj is a null
    obj = new BTNodeType<T>;
    obj->item = item;
  }
  else if(item < obj->item)
  {
    // Insert left
  }
  else if(item > obj->item)
  {
    // insert right
  }
  else if(item == obj->item)
  {
    // Create an iterator and insert
  }
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
