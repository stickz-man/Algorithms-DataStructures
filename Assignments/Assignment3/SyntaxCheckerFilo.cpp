// SyntaxCheckerFilo.cpp
// goddard - 2017
#include <iostream>
using namespace std;
#include "FiloTree.h"

int main( ) 
{
  string test[] = {"Art", "Business", "Chemistry", "Dentistry"};
  FiloTree F( test, 2);
  F.dump( );
  cout << endl;
  FiloTree G("ABCD.txt");
  G.dump( );
  cout << boolalpha << FiloTree::compare(F,G) << endl;
  cout << endl;
  FiloTree H("ABCDtoo.txt");
  H.dump( );
  cout << boolalpha << FiloTree::compare(F,H) << endl;
  FiloTree I("first.txt");
  I.dump();
  cout << endl;
  FiloTree J("second.txt");
  J.dump();
  cout << endl;
  cout << boolalpha << FiloTree::compare(I,J) << endl;
  return 0;
}

/************* OUTPUT SHOULD BE LIKE 
X
...X
......Art
......Business
...X
......Chemistry
......Dentistry

3
...1
......Chemistry
......Dentistry
...2
......Art
......Business
true

3
...Art
...2
......Business
......1
.........Chemistry
.........Dentistry
false
**********************************/
