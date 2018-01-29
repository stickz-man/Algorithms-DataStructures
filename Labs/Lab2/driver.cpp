/**********************
	Brayden Fidler
	CPSC 2120 Lab
	Wayne Goddard
	Lab 2
***********************/

#include <iostream>
using namespace std;
#include "Polynomial.h"

int main( ) 
{	
	Polynomial A, B;
	int cof, pow;
	cout << "Enter first " << endl;
	do {
		cout << "Enter pair (0,0 to finish) ";
		cin >> cof >> pow;
		A.incrementBy( cof, pow );
	} while ( !(cof==0 && pow==0) );

	cout << "Enter second " << endl;
	do {
		cout << "Enter pair (0,0 to finish) ";
		cin >> cof >> pow;
		B.incrementBy( cof, pow );
	} while ( !(cof==0 && pow==0) );

	cout << endl;
	cout << "A is " << A << endl;
	cout << "B is " << B << endl;
	cout << (A==B ? "Equal" : "Not equal" ) << endl;
	
	return 0;
	
}
