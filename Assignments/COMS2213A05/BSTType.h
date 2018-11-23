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

template<class T>
BSTType<T>::BSTType()
{
}

template<class T>
BSTType<T>::BSTType(const BSTType<T>& src)
{
}

template<class T>
const BSTType<T>& BSTType<T>::operator=(const BSTType<T>& src)
{
}

template<class T>
BSTType<T>::~BSTType()
{
}

template<class T>
bool BSTType<T>::empty() const { return (this->count == 0); }

template<class T>
void BSTType<T>::erase(const T& item)
{
}

template<class T>
bool BSTType<T>::find(const T& item) const
{
}

template<class T>
void BSTType<T>::insert(const T& item)
{
}

template<class T> // public
size_t BSTType<T>::size() const { return this->count; }

/* Begin Private function declarations */

template<class T> // private
void BSTType<T>::copy(BTNodeType<T>*& obj1, BTNodeType<T>* obj2)
{
}

template<class T> // private
void BSTType<T>::destroy(BTNodeType<T>*& obj)
{
}
  
template<class T> // private
void BSTType<T>::erase(const T& item, BTNodeType<T>*& obj)
{
}

template<class T> // private
bool BSTType<T>::find(const T& item, BTNodeType<T>* obj) const
{
}

template<class T> // private
void BSTType<T>::inorder(std::ostream&, BTNodeType<T>*) const
{
}

template<class T> // private
void BSTType<T>::insert(const T& item, BTNodeType<T>*& obj)
{
}

template<class T> // private
void BSTType<T>::postorder(std::ostream& os, BTNodeType<T>* obj) const
{
}

template<class T> // private
const T& BSTType<T>::predecessor(BTNodeType<T>* obj)
{
}

template<class T> // private
void BSTType<T>::preorder(std::ostream& os, BTNodeType<T>* obj) const
{
}

#endif
