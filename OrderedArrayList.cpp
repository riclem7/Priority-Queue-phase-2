

#include "OrderedArrayList.h"
#include <stdexcept>


OrderedArrayList::OrderedArrayList() {
    capacity =0;
    currentPos=0; // Won't be used right now...
    currentSize=0;
    value =0;
    sep =0;
    newCapacity=0;
    array = new int[capacity];

}
OrderedArrayList::OrderedArrayList(int initialCapacity) {
    capacity = initialCapacity;
    currentPos=0; // Won't be used right now...
    currentSize=0;
    value =0;
    sep =0;
    newCapacity=0;
    array = new int[capacity];
}
//My own private functions are declared before any header functions as my functions are used several times
int binarySearchInsertion(int data);

int binarySearch(int data);

void reSize(int newCapacity);

bool OrderedArrayList::add(int data) {
    //We do binary search here which returns with a temp of a certain index of where to add the number
    int temp=binarySearchInsertion(data);
    if(capacity == currentSize)
    {
        if(capacity == 0)
        {
            capacity =1;
            reSize(capacity);
        }
        else reSize(capacity * 2);
    }

    //could add ++capacity here instead of reSize

    for (int i = currentSize; i > temp; i--)
    {
        array[i] = array[i - 1];
    }

    array[temp] = data;
    currentSize++;
    return true;
}


bool OrderedArrayList::add(int index, int data) {
    //Don't allow as users can mess up the sorted list. User can simply use function add(int data)
    return false;
}

void OrderedArrayList::clear() {
    //curSize to set to currentSize in case user runs clear multiple times
    int curSize = currentSize;
    for(int i=0; i < curSize; i++)
    {
        --currentSize;
    }
}

bool OrderedArrayList::contains(int data) {
    // its -1 because binarySearch returns -1 if value is not found
    if(binarySearch(data) == -1)
    {
        //There will never be a -1 index so we are safe to say its fool proof function
        return false;
    }
    return true;
}

int OrderedArrayList::get(int index) {

    //checks to see if value is in index...
        if ((index >= currentSize) || (index < 0)) {
            throw std::invalid_argument("Invalid index!");

        }
        return array[index];




}

int OrderedArrayList::remove(int index) {


        //checks to see if its in index first
        if ((index >= currentSize) || (index < 0)) {
            throw std::invalid_argument("Invalid index!");

        }
        value = array[index];

        //int i starts at the index which we find by using a binary search
        //we shift elements over to delete the index value we just got
        for(int i=index; i < currentSize - 1; ++i)
        {

            array[i] = array[i + 1];
        }
        --currentSize;
        --capacity;
        return value;



}

bool OrderedArrayList::removeAll(int data) {
    int temp= binarySearch(data);
    int counter =0;
    //We to put temp in the first location of duplicate number
    while(array[temp - 1] == data)
    {
        temp--;
    }
    //we count how many times the number we want to remove is there
    while(array[temp] == data)
    {
        counter++;
        temp++;
    }
    //for loop with array[i - counter] to move values at previous locations of duplicate numbers
    for(int i=temp; i < currentSize; i++)
    {
        array[i - counter] = array[i];
    }
    //set to correct sizes
    currentSize = currentSize - counter;
    capacity = capacity - counter;
    //Will always return 1 as it is true that the number won't be in the array anymore...
    return 1;

}
//Searches to find which index is the data at
int OrderedArrayList::indexOf(int data) {

    int temp= binarySearch(data);

    if(binarySearch(data) != -1)
    {
        //We need logic to find the first index of the same value as the specs mentions it must be the first occurence
        while(array[temp - 1] == data)
        {
            temp--;
        }
        return temp;
    }
    return -1;


}

bool OrderedArrayList::isEmpty() {

    return currentSize ==0;


}

int OrderedArrayList::size() {
    return currentSize;
}

void OrderedArrayList::trimToSize() {
    capacity = currentSize;


}

//testers for myself
void OrderedArrayList::reSize(int newCapacity)
{

    int* newArray = new int[newCapacity];

    for(int i=0; i < currentSize; ++i)
    {
        newArray[i] = array[i];
    }

    array = newArray;

    capacity = newCapacity;
}

//Binary search
int OrderedArrayList::binarySearch(int data) {
    int low= 0;
    //Doing - 1 to not get out of bounds as arrays start at 0...
    int high = currentSize - 1;
    //keep doing these if statements until we find an index or its not in the array at all
    while(high >= low)
    {
        //We find our mid
        int mid = (high + low) / 2;
        //best case: our value is right at the middle
        if(data == array[mid])
        {
            return mid;
        }
            //if our data is bigger than mid we make low = mid + 1 (we look at right side of array)
        else if(data > array[mid])
        {
            low = mid + 1;
        }
        else
            //if all other cases fail then it must mean our value is at the left side of the array so we make high = mid - 1
        {
            high = mid - 1;
        }

    }
    //If nothing is found then return a -1
    return -1;
}

int OrderedArrayList::binarySearchInsertion(int data) {
    int low= 0;
    int mid1=0;
    int high = currentSize - 1;
    //keep doing these if statements until we find an index or its not in the array at all
    while(high >= low)
    {
        //We find our mid
        mid1 = (high + low) / 2;
        //best case: our value is right at the middle
        if(data == array[mid1])
        {

            return mid1;
        }
            //if our data is bigger than mid we make low = mid + 1 (we look at right side of array)
        else if(data > array[mid1])
        {
            low = mid1 + 1;
        }
        else
            //if all other cases fail then it must mean our value is at the left side of the array so we make high = mid - 1
        {
            high = mid1 - 1;
        }

    }

    if(low > mid1)
    {
        return low;
    }
    return mid1 ;
}
