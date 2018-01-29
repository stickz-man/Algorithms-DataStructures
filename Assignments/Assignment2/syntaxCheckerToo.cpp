// goddard - 2017
#include <iostream>
using namespace std;
#include "PointStack.h"


int main ( ) 
{
   Point A(0,0);
   Point B(5,5);
   Point C(10,10);
   Point D(5,5);
   Point E(A);

   cout << "should be false:true" << endl;
   cout << boolalpha << (B==E) << ":" << boolalpha << (B==D) << endl;

   PointStack S; 
   S.push(A);
   S.push(B);
   S.push(C);
   S.push(E);
   
   cout << "should be (10,10):(0,0)" << endl;
   cout << S.peekUnder() << ":" << S.peek() << endl;

   cout << "should be (0,0)(10,10)(5,5)(0,0)" << endl;
   while( !S.isEmpty( ) ) 
     cout << S.pop( );
   cout << endl;
   
   cout << "Should be (0,0)" << endl << S.pop() << endl;
   cout << "Should be (0,0)" << endl << S.peek() << endl;
   
   S.push(D);
   cout << "Should be (5,5)" << endl << S.peek() << endl;
   cout << "Should be (0,0)" << endl << S.peekUnder() << endl;
   
   S.push(C);
   cout << "Should be (10,10)" << endl << S.peek() << endl;
   cout << "Should be (5,5)" << endl << S.peekUnder() << endl;
}