// wdg  - syntaxCheck.cpp 
// for WordLadder assignment
#include <iostream>
using namespace std;

#include "stringQueue.h"
#include "radixSort.h"

int main( ) 
{
    string arr[ ] = { "bands", "candy", "dandy", "apple", "caned" }; 
    radixSort( arr, 5 );
    stringQueue Q;
    for(int i=0; i<5; i++) 
         Q.enqueue( arr[i] );
    for(int i=0; i<5; i++) 
         cout << Q.dequeue( ) << endl;
    cout << boolalpha << Q.isEmpty( ) << endl;
    return 0;
}