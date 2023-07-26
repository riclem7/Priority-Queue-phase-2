

#include "OrderedPQ.h"
#include "OrderedArrayList.h"
#include <stdexcept>


OrderedPQ::OrderedPQ() {

    pq = new OrderedArrayList(DEFAULT_MAX_CAPACITY);
}

OrderedPQ::OrderedPQ(int capacity) {

    pq = new OrderedArrayList(capacity);
}


int OrderedPQ::findMinIndex() {
//Always returns 0 as it will be the index of the longest priority number in the ordered list
    return 0;
}

bool OrderedPQ::insert(int object) {
//Just a if statement checking if its full, if not add the object to the list
    if(isFull())
    {
        return false;
    }

    pq->add(object);

    return true;


}

int OrderedPQ::remove() {
//A throw invalid argument will be shown if user trys to remove from a empty queue.
//It will remove from index 0 as its ordered...
    if(isEmpty())
    {
        throw std::invalid_argument("Cannot remove from empty queue");
    }
    //Need else just in case if  the throw statement is thrown
    else
    {
        return pq->remove(0);
    }



}

bool OrderedPQ::deleteAll(int obj) {
    //If it has the number we want to remove then it continues and removes all of that num
    if(pq->contains(obj))
    {
        pq->removeAll(obj);
        return true;
    }
    else
    {
        return false;
    }

}

int OrderedPQ::peek() {
    //If user tries to peek on empty queue then a error is thrown. If not we use our function findMinIndex to find highest
    // priority
    if(isEmpty())
    {
        throw std::invalid_argument("Cannot peek from empty queue");
    }
    else
    {
        return pq->get(findMinIndex());
    }

}

bool OrderedPQ::contains(int obj) {
    //Checks if pq has a certain object
    return pq->contains(obj);

}

int OrderedPQ::size() {

    return pq->size();

}

void OrderedPQ::clear() {

    pq->clear();
}

bool OrderedPQ::isEmpty() {
    return pq->isEmpty();

}

bool OrderedPQ::isFull() {
//List is never full so always return false
    return false;

}

