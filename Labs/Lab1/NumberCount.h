/***********************
	Brayden Fidler
	bfidler
	Lab 1
	Lab Section ?
	TA?
***********************/

#ifndef NUMBERCOUNT_H
#define NUMBERCOUNT_H

using namespace std;
#include <iostream>

class NumberCount
{
  private:
    //member variables
    int *numbers;
    int max;
    int min;
    
  public:
    //overloaded constructor
    NumberCount(int, int);
    //Destructor
    ~NumberCount();
    
    //setters
    void addElement(int);
    bool removeElement(int);
    
    //getters
    void display();
    int getCount();
    
};

#endif