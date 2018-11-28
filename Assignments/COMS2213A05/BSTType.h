#ifndef BST_TYPE_H
#define BST_TYPE_H
#include "BTNodeType.h"
#include <cstddef>
#include <ostream>
#include <iostream>

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

    /* Debug function */
    template<class U>
      void friend jimboDebug(BSTType<U>&);
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
BSTType<T>::BSTType() { count = 0; }

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
  {
    /* If the tree is empty, there isn't really anything to search for.
     * In this, the function will return false */
    return false;
  }
  else
  {
    /* If there is something to search for, the code inside this else
     * scope is executed, and recurrsion is used to find the value */
    if(root->item == item)
      return true;
    else if(root->left != nullptr && item < root->left->item)
      // Left traversal
      find(item, root->left);
    else if(root->right != nullptr)
      // Right traversal
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
 *   Find function that is used to find the item via recurrsion.
 *
 * Preconditions:
 *   The find(const T&) is invoked somewhere in the program. This
 *   causes the reccursive function to be called.
 *
 * Postconditions:
 *   Does not modify anything.
 * ----------------------------------------------------------------*/
template<class T>
bool BSTType<T>::find(const T& item, BTNodeType<T>* obj) const
{
  if(obj->item == item)
    return true;
  else if(obj->left != nullptr && item < obj->left->item)
    /* If the left isn't a nullptr and the item that we are trying
     * to find less than the left item */
    find(item, obj->left);
  else if (obj->right != nullptr)
    /* If the left isn't what we're looking for, we are going to
     * check the right to see if it's nullptr. If it isn't, we will
     * traverse the right branches instead. */
    find(item, obj->right);
  else
    /* If none of the above is true, that means we are on a node that
     * is nullptr, indicating the end of traveresal. Since there is
     * no longer anything for us to traverse, we will simply return
     * false to denote that the item was not found. */
    return false;
}

/* ------------------------------------------------------------------
 * Function:
 *   BSTType<T>::insert(const T&)
 *
 * Description:
 *   The non-recursive function of insert. This insert function will
 *   invoke the recursive function of insert.
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
   * If the list, however, is not empty, then 
   * similar to the find function, and then insert where necessary
   *
   * It's going to look something like this: Say we want to insert
   * a value of 10 into list, and assume the list is list.
   *
   * Item to insert: 10
   * let NP = nullptr
   *
   *         [NP] ← This means we are going to insert it here
   *        /    \
   *      [NP]  [NP]
   *  
   * Tree after insertion...
   *         [10]
   *        /    \
   *      [NP]  [NP]
   *
   * The left and right still are nullptr. If we wish to insert
   * more, that means there will be more traversal, and we have to
   * rely on recursion to determine where the item should now be
   * inserted
   * */

  if(root == nullptr)
  {
    std::cout << "Item " << item << " inserted at root\n";
    try
    {
      root = new BTNodeType<T>;
      root->item = item;
      count++;
    }
    catch(std::bad_alloc&)
    {
      // Do nothing, just catch
    }
  }
  else if(item <= root->item)
  {
    std::cout << "Inserting: " << item << std::endl << "  " << item
      << " is leq to " << item << ". " << "Descending left...\n";
    insert(item, root->left);
  }
  else if(item >= root->item)
  {
    std::cout << "Inserting: " << item << std::endl << "  " << item
      << " is geq to " << item << ". " << "Descending right...\n";
    insert(item, root->right);
  }
}

/* ------------------------------------------------------------------
 * Function:
 *   void BSTType<T>::insert(const T&, BTNodeType<T>*&)
 *
 * Description:
 *   The recursive insert function.
 *
 * Preconditions:
 *
 * Postconditions:
 * ----------------------------------------------------------------*/
template<class T> // private
void BSTType<T>::insert(const T& item, BTNodeType<T>*& obj)
{
  /* If we have an item to insert, and we already have the given list
   * and another value of 10, this means:
   *
   * Value to insert: 10
   *
   *         [10]    This is the current tree.
   *        /    \
   *      [NP]  [NP]
   *
   * If we want to insert a value of 10, we will have to create
   * an an iterator and then insert the iterator into the tree.
   * Since 10 is just a duplicate value, we will simply say that
   * it is the parent and then move the test of the tree down by
   * repointing things.
   *
   * Here, prepare the iterator for insertion.
   * -----------------------------------------
   *   [10]
   *         [10] ← Current root (or parent)
   *        /    \
   *      [NP]  [NP]
   *
   *
   * Then we can reroute some pointers
   * ---------------------------------
   *     [10] 
   *    /    \
   *  [NP]  [10] ← Inserted here (for duplicate values insert right)
   *        /  \
   *      [NP][NP]
   *
   * However, if we had a heavily populated list already, things 
   * would still be quite similar.
   *
   *   Value to insert: 28
   *
   *               [11]
   *               /  \
   *              /    \
   *             /      \
   *            /        \
   *         [06]       [19]
   *         /  \       /  \
   *        /    \     /    \
   *      [04]  [08] [17]  [43]
   *        \      \       /  \
   *       [05]   [10]   [31][49]
   *
   *   This means that the value 28 needs to be inserted to the left 
   *   of 31. With some repoint the pointers. When traversing for
   *   insert, we will eventally get to the point where we are at the
   *   node that holds item 31. Once there, insert 28 to the left of
   *   31 since 28 is less than 31.
   *   
   *   CODE EXAMPLE FOR THIS
   *   ---------------------
   *     if(item == obj->item)
   *       // Do what was described above
   *     else if(item > obj->item)
   *       insert(item, obj->right;
   *     else if(item < obj->item)
   *       insert(item, obj->left);
   *     else
   *       // The only option left is nullptr
   *       // So need to allocate memory for it
   *    
   *
   *                                    
   *            [11]                             [11]
   *            /  \                             /  \
   *           /    \                           /    \
   *          /      \                         /      \
   *         /        \                       /        \
   *      [06]       [19]                  [06]       [19]
   *      /  \       /  \                  /  \       /  \
   *     /    \     /    \                /    \     /    \
   *   [04]  [08] [17]  [43]            [04]  [08] [17]  [43]  
   *     \      \       /  \              \      \       /  \
   *    [05]   [10]   [31][49]           [05]   [10]   [31][49]
   *                  /                                /
   *                [NP]       Value inserted here → [28]
   *                 ↑        ----------------------------
   *                 It gets here eventually, and when it does, we
   *                 will allocate memory for it.
   *
   *
   * What if we had a duplicate item needed to be inserted, but it
   *  isn't the root node this time?
   *
   *    Item to insert: 43
   *
   *
   *            [11]                             [11]
   *            /  \                             /  \
   *           /    \                           /    \
   *          /      \                         /      \
   *         /        \                       /        \
   *      [06]       [19]      ------>     [06]       [19]
   *      /  \       /  \                  /  \       /  \
   *     /    \     /    \                /    \     /    \
   *   [04]  [08] [17]  [43]            [04]  [08] [17]  [43]
   *     \      \       /  \              \      \       /  \
   *    [05]   [10]   [31][49]           [05]   [10]   [31][49]
   * ----------------------------------------------------------------
   *
   *            [11]                             [11]
   *            /  \                             /  \
   *           /    \                           /    \
   *          /      \                         /      \
   *         /        \                       /        \
   *      [06]       [19]      ------>     [06]       [19]
   *      /  \       /  \                  /  \       /  \
   *     /    \     /    \                /    \     /    \
   *   [04]  [08] [17]  [43]            [04]  [08] [17]  [43]
   *     \      \       /  \              \      \       /  \
   *    [05]   [10]   [31][49]           [05]   [10]   [31][49]
   *                                                       /
   *                                                     [43]
   *                          The value is inserted here  ↑↑
   *                            
   * */
  if(obj == nullptr)
  {
    std::cout << "Null pointer reached. Allocating memory for item "
      << item << std::endl;
    try
    {
      // Dynamically allocate
      obj = new BTNodeType<T>;

      // Iterator item is set to value of item to inserted.
      obj->item = item;

      // Increment count
      count++;
    }
    catch(std::bad_alloc&)
    {
      // Do nothing, just catch.
    }
  }
  else if(item <= obj->item)
  {
    std::cout << "Inserting: " << item << std::endl << "  " << item
      << " is leq to " << obj->item << ". " << "Descending left..."
      << std::endl;
    insert(item, obj->left);
  }
  else if(item >= obj->item)
  {
    // insert right
    std::cout << "Inserting: " << item << std::endl << "  " << item
      << " is geq to " << obj->item << ". " << "Descending right..."
      << std::endl;
    insert(item, obj->right);
  }
}

/* ------------------------------------------------------------------
 * Function:
 *   size_t BSTType<T>::size() const
 *
 * Description:
 *   This is the infamous one-liner function, if you exclude the
 *   template. Anyways, it just returns the current count of the list
 *   which denotes how many items there are in the list.
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

/* ------------------------------------------------------------------
 * Function:
 *  void BSTType<T>::traverse(std::ostream&, TravType) const
 *
 * Description:
 *   This function traverses the tree and outputs whatever is on the
 *   tree depending on the traversal type.
 *
 * Preconditions:
 *   An object of the BSTType class is the on the right hand side of
 *   the extraction operator.
 *
 * Postconditions:
 *   Does not modify anything.
 * ----------------------------------------------------------------*/
template<class T>
void BSTType<T>::traverse(std::ostream& os, TravType) const
{
  /* In this function, we are going to traverse a tree and output the
   * contents according the what the traverse type is. There are 3
   * different traversal types that are going to be used for this
   * function: Inorder, Preorder, and Postorder.
   *
   *               [11]
   *               /  \
   *              /    \
   *             /      \
   *            /        \
   *         [06]       [19]
   *         /  \       /  \
   *        /    \     /    \
   *      [04]  [08] [17]  [43]
   *        \      \       /  \
   *       [05]   [10]   [31][49]
   *
   * Inorder output:
   *   
   * */
}

/* ------------------------------------------------------------------
 * Function:
 *  void jimboDebug()
 *
 * Description:
 *  This is an extremely powerful function because it's a function
 *  for debugging.
 *
 * Preconditions: None
 *
 * Postconditions: Whatever it wants.
 * ----------------------------------------------------------------*/
template<class T>
void jimboDebug(BSTType<T>& obj)
{
  obj.insert(10);
  obj.insert(20);
  obj.insert(30);
  obj.insert(40);
  obj.insert(50);
  obj.insert(60);
  obj.insert(70);
  obj.insert(80);
  obj.insert(90);
  obj.insert(100);

  /* Use the following for a way to check for leaks before the exit
   * in the program so we can have better understanding of where the
   * leak is. In this case, the single leak is due to a bad exit.
   * Nothing is deallocated when dynamically allocated. */
  std::string asdf;
  std::getline(std::cin, asdf);
}
#endif
