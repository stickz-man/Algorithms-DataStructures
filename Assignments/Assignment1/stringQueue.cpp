#include "stringQueue.h"
#include <iostream>
using namespace std;


//Constructor 
stringQueue::stringQueue(int capacity) : list(new string[capacity]), 
  CAPACITY(capacity), front (1), back (0)
{}


//Destructor
stringQueue::~stringQueue()
{
  delete [] list;
}

//Returns true if the stringQueue is empty, false if its not
bool stringQueue::isEmpty()
{
  //back is updated depnding on the number of elements
  return(back == 0);
}


//Adds the string passed to the front of the queue
void stringQueue::enqueue(string elem)
{
  if (back != CAPACITY) {
    /*Starts at the end of the array shifting each element farther down the
      array. Ends once we reach the beginning.*/ 
    for (int i = back; i > 0; i--)
      list[i] = list[i - 1];
    
    //incrementing back and putting the new string at the beginning of the array  
    back++;
    list[0] = elem;
  }
  else {
    //capacity is full so we must git rid of an element
    cout << "Error, stringQueue is full." << endl;
  }
}


//Returns the last element in the array(the first one to be added)
string stringQueue::dequeue()
{
  if (back > 0) {
    //deincrementing back
    back--;
  
    //creating a return variable and clearing the last element
    string dequedStr = list[back];
    list[back] = "";
  
    //returning the back element
    return dequedStr;
  }
  else
    return "Queue is empty!";
}

