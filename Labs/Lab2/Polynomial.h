/**********************
	Brayden Fidler
	CPSC 2120 Lab
	Wayne Goddard
	Lab 2
***********************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
using namespace std;
#include "Pair.h"
#include <iostream>

class Polynomial
{
	private:
	//members variables
	int powerCount;
	Pair * arrPr;

	public:
	//constructor
	Polynomial();
	
	//destructor
	~Polynomial();

	//other methods
	void incrementBy(int, int);
	//operator methods
	bool operator==(const Polynomial &) const;
  friend ostream &operator<<(ostream &, const Polynomial &);	
 
};
#endif
