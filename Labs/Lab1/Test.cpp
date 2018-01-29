/***********************
	Brayden Fidler
	bfidler
	Lab 1
	Lab Section ?
	TA?
***********************/

#include "NumberCount.h"
using namespace std;

int main(void){
  
  NumberCount N(1,6);
  
  N.addElement(2); 
  N.addElement(2); 
  N.addElement(2); 
  N.addElement(4);
  N.addElement(7);
  N.addElement(3); 
  N.removeElement(1); 
  N.removeElement(3);
  N.display();
	
  return 0;
}

