/**********************
	Brayden Fidler
	CPSC 2120 Lab
	Wayne Goddard
	Lab 2
***********************/

#ifndef PAIR_H
#define PAIR_H
using namespace std;

class Pair
{
	private:
	//member variables
	int coeff;
	int pow;

	public:
	//constructors
	Pair();
	Pair(int, int);

	//setters
	void setCoe(int);
	void setPow(int);
	
	//getters
	int getCoe();
	int getPow();

};
#endif
