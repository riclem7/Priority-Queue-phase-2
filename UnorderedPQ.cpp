// Ricardo Lemus
// class account number: cssc0329
// Student ID: 821687094

#include "UnorderedPQ.h"
#include "UnorderedArrayList.h"
#include <stdexcept>

int UnorderedPQ::findMinIndex() {
    //Need to set min to first index of list because if its set to 0 our list could never have a 0 to begin with and
    //our min value will always be wrong!
    int min = pq->get(0);
    for(int i=0; i < pq->size(); i++)
    {
        if(min > pq->get(i))
        {
            min = pq->get(i);
        }
    }
    return pq->indexOf(min);

}

UnorderedPQ::UnorderedPQ() {

    pq = new UnorderedArrayList(DEFAULT_MAX_CAPACITY);

}

UnorderedPQ::UnorderedPQ(int capacity) {

    pq = new UnorderedArrayList(capacity);

}

bool UnorderedPQ::insert(int object) {
    if(isFull())
    {
        return false;
    }
    //If not full then we add the object to the unordered list
    pq->add(object);

    return true;

}

int UnorderedPQ::remove() {

    if(isEmpty())
    {
        throw std::invalid_argument("Cannot remove from empty queue");
    }
        //Need else just in case if  the throw statement is thrown
    else
    {
    //We use peek function to find our highest prio as it will be removed
    //we set it equal to temp then we use findMinIndex and remove the same number
    //we then return temp which is the number we just removed
    int temp = peek();
    pq->remove(findMinIndex());

    return temp;
    }

}

bool UnorderedPQ::deleteAll(int obj) {

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

int UnorderedPQ::peek() {

    if(isEmpty())
    {
        throw std::invalid_argument("Cannot peek from empty queue");
    }
    else
    {
        return pq->get(findMinIndex());
    }

}

bool UnorderedPQ::contains(int obj) {

    return pq->contains(obj);
}

int UnorderedPQ::size() {

    return pq->size();

}

void UnorderedPQ::clear() {

    pq->clear();


}

bool UnorderedPQ::isEmpty() {

    return pq->isEmpty();

}
bool UnorderedPQ::isFull() {

    return false;

}

