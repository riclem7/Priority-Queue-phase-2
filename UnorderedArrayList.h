// Ricardo Lemus
// class account number: cssc0329
// Student ID: 821687094
#ifndef UNORD_ARRLIST_H
#define UNORD_ARRLIST_H

#include "AbstractList.h"

class UnorderedArrayList : public AbstractList {

private:
    int* array;
    int* newArray;
    int capacity;
    int currentPos;
    int value;
    int resultSize;
    int sep;
    int newCapacity;
    void reSize(int newCapacity);

public:
    UnorderedArrayList();
    UnorderedArrayList(int initialCapacity) ;

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