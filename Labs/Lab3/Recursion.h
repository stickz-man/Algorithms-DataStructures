/**********************
	Brayden Fidler
	CPSC 2120 Lab
	Wayne Goddard
	Lab 2
***********************/

#ifndef RECURSION_H
#define RECURSION_H
using namespace std;
#include <iostream>
#include <fstream>

class Recursion 
{
  private:
  //member variables
  int grid[10][10];
  
  
  public:
  //Constructor
  Recursion(ifstream &);
  
  //Methods
  void print();
  void printGroupWith(int, int);
  
};

#endif