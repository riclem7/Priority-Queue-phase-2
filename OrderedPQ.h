
#ifndef ORD_PQ_H
#define ORD_PQ_H

#include "PriorityQueue.h"
#include "OrderedArrayList.h"

class OrderedPQ : public PriorityQueue
{
private:
    OrderedArrayList *pq;

    int findMinIndex() ;

public:

    OrderedPQ() ;
    OrderedPQ(int capacity) ;

    //  Inserts a new object into the priority queue.  Returns true if
    //  the insertion is successful.  List-based priority queues are
    //  never full.  Other implementations: If the PQ is full, the 
    //  insertion is aborted, and the method returns false.
    virtual bool insert(int object) ;

    //  Removes the object of highest priority that has been in the
    //  PQ the longest, and returns it.  
    //  Throws invalid_argument if the PQ is empty.
    //         exception error message: "Cannot remove from empty queue" 
    virtual int remove() ;

    //  Deletes all instances of the parameter obj from the PQ if found, and
    //  returns true.  Returns false if no match to the parameter obj is found.
    virtual bool deleteAll(int obj) ;

    //  Returns the object of highest priority that has been in the
    //  PQ the longest, but does NOT remove it. 
    //  Throws invalid_argument if the PQ is empty.
    //         exception error message: "Cannot peek from empty queue" 
    virtual int peek() ;

    //  Returns true if the priority queue contains the specified element
    //  false otherwise.
    virtual bool contains(int obj) ;

    //  Returns the number of objects currently in the PQ.
    virtual int size() ;

    //  Returns the PQ to an empty state.
    virtual void clear() ;

    //  Returns true if the PQ is empty, otherwise false
    virtual bool isEmpty() ;

    //  Returns true if the PQ is full, otherwise false.  List based
    //  implementations should always return false.
    virtual bool isFull() ;

};
#endif
