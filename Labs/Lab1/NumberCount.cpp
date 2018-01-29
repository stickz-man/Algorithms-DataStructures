/***********************
	Brayden Fidler
	bfidler
	Lab 1
	Lab Section ?
	TA?
***********************/

#include "NumberCount.h"
using namespace std;

//overloaded constructor
NumberCount::NumberCount(int mn, int mx)
{
  //max and min elements set
  max = mx;
  min = mn;
  
  //creating an array of elements
  numbers = new int[max - min + 1];
  
}


//destructor
NumberCount::~NumberCount()
{
  //deleting memory allocated to the array
  delete [] numbers;
}

//takes in a number and increments that element
void NumberCount::addElement(int value)
{
  //checking to see if the element exists
  if((value <= max) & (value >= min))
  {
    //increments element
    numbers[value - min] += 1;
  }
  else
  {
    cout << value << " Out of range;" << endl;
  }
}


//takes in a number and decrements that element
bool NumberCount::removeElement(int value)
{
  //checking to see if the element exists
  if((value <= max) & (value >= min))
  {
    //checks to see if there's anything in the element
    if(numbers[value - min] > 0)
    {
      //decrements element
      numbers[value - min] -= 1;
      return 1;
    }
    else
    {
      cout << value << " not present;" << endl;
      return 0;
    }
  }
  else
  {
    cout << value << " Out of range;" << endl;
    return 0;
  }
}


//creates a histrogram display
void NumberCount::display()
{
  //loops from beginning to end of numbers
  for(int i = min; i <= max; i++)
  {
    cout << i << ": ";
    //loops through the number of elements for each number
    for(int j = 0; j < numbers[i - min]; j++)
    {
      cout << "*";
    }
    
    cout << endl;
  }
}


//returns total count of numbers
int NumberCount::getCount()
{
  int count = 0;
  
  //loops from beginning to end of numbers
  for(int i = min; i <= max; i++)
  {
    //loops through the number of elements for each number
    for(int j = 0; j < numbers[i - min]; j++)
    {
      count += 1;
    }
  }
  
  return count;
}
