
#ifndef ORD_ARRLIST_H
#define ORD_ARRLIST_H

#include "AbstractList.h"

class OrderedArrayList : public AbstractList {

private:
    int* array;
    int* newArray;
    int capacity;
    int currentPos;
    int value;
    int resultSize;
    int sep;
    int newCapacity;
    int binarySearchInsertion(int data);
    int binarySearch(int data);
    void reSize(int newCapacity);



public:
    OrderedArrayList();
    OrderedArrayList(int initialCapacity) ;

    virtual bool add(int data) ;
    virtual bool add(int index, int data) ;
    virtual void clear() ;
    virtual bool contains(int data) ;
    virtual int  get(int index) ;
    virtual int  indexOf(int data) ;
    virtual bool isEmpty() ;
    virtual int  remove(int index) ;
    virtual bool removeAll(int data) ;
    virtual int  size() ;
    virtual void trimToSize() ;




};
#endif
