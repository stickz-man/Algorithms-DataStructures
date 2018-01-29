/**********************
	Brayden Fidler
	CPSC 2120 Lab
	Wayne Goddard
	Lab 2
***********************/

#include "Pair.h"

//Default Constructor
Pair::Pair() : coeff(0), pow (0)
{}

//Overloaded Constructor
Pair::Pair(int c, int p) : coeff(c), pow(p)
{}

//sets the value of the coefficient
void Pair::setCoe(int c)
{
	coeff = c;
}

//sets the value of the power
void Pair::setPow(int p)
{
	pow = p;
}

//returns the coefficent
int Pair::getCoe()
{
	return coeff;
}

//returns the power
int Pair::getPow()
{
	return pow;
}
 
