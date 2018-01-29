//Brayden Fidler
#include "BTree.h"

int main () {

  BTree myT1, myT2;
  
  for (int i = 1; i <= 7; i++) {
    cout << "Adding " << i << endl;  
    myT1.insert(i);
  }
  
  myT1.dump();
  
  for (int i = 7; i >= 1; i--) {
    cout << "Adding " << i << endl;  
    myT2.insert(i);
  }
  
  myT2.dump();
}