#include "radixSort.h"
#include "stringQueue.h"
using namespace std;
static const int LETTERS = 26;


//Sorts the array passed using a radixSort method that uses queues as bins
void radixSort (string list[], int listLength)
{
  //creating bins for a bucket sort - one per letter
  stringQueue bins[LETTERS];
  
  //Iterating from the last character to the first for a radix sort
  for(int i = list[0].length() - 1; i > -1; i--) {
    
    //First sorting each string into a bin based off the character selected
    for (int j = 0; j < listLength; j++) {
    
      //bin is chosen based on character minus 97 (asci for a; a = 0, z = 25)
      bins[list[j].at(i) - 97].enqueue(list[j]);
    }
    
    int k = 0;
    
    for(int j = 0; j < listLength; j++){
      
      while(bins[k].isEmpty())
        k++;
        
      list[j] = bins[k].dequeue();
    }
  }
}