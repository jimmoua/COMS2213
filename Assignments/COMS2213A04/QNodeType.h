#ifndef QNODE_TYPE_H
#define QNODE_TYPE_H

template<class T>
struct QNodeType
{
    T item;
    QNodeType<T>* next;
};


#endif
