#ifndef BT_NODE_TYPE_H
#define BT_NODE_TYPE_H
#include <cstddef>

template<class T>
struct BTNodeType
{
  T item;
  BTNodeType<T>* left = nullptr;
  BTNodeType<T>* right = nullptr;
};

#endif
