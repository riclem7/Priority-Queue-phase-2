

#include "UnorderedArrayList.h"
#include <stdexcept>

UnorderedArrayList::UnorderedArrayList() {
    capacity =0;
    currentPos=0; // Won't be used right now...
    currentSize=0;
    value =0;
    sep =0;
    newCapacity =0;
    array = new int[capacity];

}

UnorderedArrayList::UnorderedArrayList(int initialCapacity) {

    capacity = initialCapacity;
    currentPos=0; // Won't be used right now...
    currentSize=0;
    value =0;
    sep =0;
    newCapacity =0;
    array = new int[capacity];

}
void reSize(int newCapacity);

//Adds a value to the end of the array and it increases capacity
bool UnorderedArrayList::add(int data) {
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
    array[currentSize] = data;
    ++currentSize;

    return true;
}

bool UnorderedArrayList::add(int index, int data) {

    //If user wants to add a number at a spot where it doesn't exist on array then we return false.
    if(index > currentSize || index < 0)
    {
        return false;
    }

    if(capacity == currentSize)
    {
        if(capacity == 0)
        {
            capacity =1;
            reSize(capacity);
        }
        else reSize(capacity * 2);

    }


    //currentSize +1 for the end element
    for(int i =currentSize +1; i > index; i--)
    {
        array[i] = array[i - 1];
    }
    array[index] = data;
    currentSize++;

    return true;


}



void UnorderedArrayList::clear() {

    //curSize to set to currentSize in case user runs clear multiple times
    int curSize = currentSize;
    for(int i=0; i < curSize; i++)
    {
        --currentSize;
    }

}

//Function to find if an int is in the current array, if it is return true if not return false.
bool UnorderedArrayList::contains(int data) {
    for (int i = 0; i < currentSize; i++)
    {
        if(array[i] == data)
            return true;
    }
    return false;

}

//Gets value of index provided and returns it to user.
int UnorderedArrayList::get(int index) {


    //how do I throw out an invalid_argument...

        if ((index >= currentSize) || (index < 0)) {
            throw std::invalid_argument("Invalid index!");

        }
        return array[index];




}

int UnorderedArrayList::remove(int index) {



//value is used to set to current index value before it gets deleted, then at the end of function the original number
// is returned to the user.

        if ((index >= currentSize) || (index < 0)) {
            throw std::invalid_argument("Invalid index!");

        }
        //we need to do this as we will delete the array[index] so value will hold it for now.
        value = array[index];
        //shift objects to the left as we are removing a value
        // we start at current index we want to remove and work our way through with current size - 1 as we will lose 1 element
        for(int i=index; i < currentSize - 1; ++i)
        {
            //we start by replacing the element we want to "Delete" and we keep going until we reached our new size which is
            // currentSize - 1 (as we lost 1 element)
            array[i] = array[i + 1];
        }
        //we fix the size of both ints of the array accordingly
        --currentSize;
        --capacity;
        //our original value is returned to the user
        return value;




}
//Remove all of a certain number that is entered....
bool UnorderedArrayList::removeAll(int data) {

    //Need logic if number isn't in array at all to begin with...
    //Also need to return false if this function fails somehow...
    /*
    int i = 0;
    //Wil keep looping while i is smaller than array actual size...
    while (i < currentSize) {
        if (array[i] == data) {
            //Need to check for special case where element could be at end of array so we can just decrease size
            if (i < currentSize - 1)
                //Now it is setting each element in the array one unit to the right until currentSize - 1
                for (int j = i; j < (currentSize - 1); j++)
                    array[j] = array[j + 1];
            currentSize--;
            capacity--;
            //Increasing i only if a delete did not go through as there is a chance there is more of the same value
            // in the array
        } else i++;
    }
    return 1;
    */

    resultSize =0;
    sep=0;
    //Go through array once and find size of new array without a specific number user doesn't want
    for(int i=0; i < currentSize; i++)
    {
        if(array[i] != data)
            resultSize++;
    }
    //make new array with the new size we just got
    newArray = new int[resultSize];


    //go through old array again and write down any value that isnt the data number to new array
    for(int i=0; i < currentSize; i++)
    {
        if(array[i] != data)
        {
            newArray[sep] = array[i];
            sep++;

        }

    }
    //set old array to new array as we need old array to be our end product
    array = newArray;
    //set the array size accordingly
    capacity = resultSize;
    currentSize = resultSize;

    //Always returns 1 even if there was none of those values to begin with
    // as techincally the array doesn't have those values so it is true that those values arent there anymore...
    return 1;


}
int UnorderedArrayList::indexOf(int data) {
    for(int i=0; i < currentSize; i++)
    {
        if(array[i] == data)
        {
            return i;
        }
    }
    return -1;
}


//Checks if array is empty
bool UnorderedArrayList::isEmpty() {

    return currentSize == 0;
}



//Checks for size of given list then returns an int of its size
int UnorderedArrayList::size() {

    return currentSize;
}
//Checks size of array and sets it to capacity if capacity is bigger than actual array
void UnorderedArrayList::trimToSize() {

    capacity = currentSize;



}


//function I made to increase array size by making new array then setting old array equals to new array with its new size.
void UnorderedArrayList::reSize(int newCapacity)
{

    int* newArray = new int[newCapacity];

    for(int i=0; i < currentSize; ++i)
    {
        newArray[i] = array[i];
    }

    array = newArray;

    capacity = newCapacity;
}
