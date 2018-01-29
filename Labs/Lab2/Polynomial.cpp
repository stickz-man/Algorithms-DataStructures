/**********************
	Brayden Fidler
	CPSC 2120 Lab
	Wayne Goddard
	Lab 2
***********************/

#include "Polynomial.h"
using namespace std;


//Default Constructor
Polynomial::Polynomial() : powerCount(0), arrPr (new Pair[100])
{}


//increments the polynomial by the a varaible of coefficient, c, and power, p
void Polynomial::incrementBy(int c, int p)
{
  int i = 0;
  
  //increments array until power passed is either equal or greater than
  //curent power
  while (p < arrPr[i].getPow()) {
    i++;
  }
  
  //if passed power is already present, coefficient is added to current one
  if (p == arrPr[i].getPow()) {
    arrPr[i].setCoe(arrPr[i].getCoe() + c);
  }
  else {
    //updating power count
    powerCount++;
    
    //shifting array down a spot, so that its sorted
    for (int j = powerCount; i < j; j--) {
      arrPr[j].setCoe(arrPr[j - 1].getCoe());
      arrPr[j].setPow(arrPr[j - 1].getPow());
    }
    
    //filling empty gap with new term
    arrPr[i].setCoe(c);
    arrPr[i].setPow(p);
  }
}


//destructor
Polynomial::~Polynomial()
{
	delete [] arrPr;
}


//checks to see if polynomials are equal
bool Polynomial::operator==(const Polynomial & myPoly) const
{
  bool isEqual = true;
  int i = 0;
  
  if(powerCount != myPoly.powerCount)
    isEqual = false;
  
  //loops while the Polynomials are still potentially true and while
  //each term is checked to confirm this (breaks if they are different)  
  while(isEqual && i < powerCount) {
    
    //if the power or coefficient of a term isn't the same for both, then
    //the terms are not equal
    if(arrPr[i].getCoe() != myPoly.arrPr[i].getCoe() ||
      arrPr[i].getPow() != myPoly.arrPr[i].getPow())
        isEqual = false;
    
    i++;
  }
  
  return isEqual;
}


//prints the entire polynomial
ostream &operator<<(ostream &out, const Polynomial& myPoly)
{
  //loops through each term of polynomial
  for (int i = 0; i < myPoly.powerCount; i++) {
    
    //prints out the term
    out << myPoly.arrPr[i].getCoe() << "x^" << myPoly.arrPr[i].getPow();
    //adds a "+" if more terms to follow
    if (i + 1 < myPoly.powerCount)
      out << " + ";
  }
  
	return out;
}
