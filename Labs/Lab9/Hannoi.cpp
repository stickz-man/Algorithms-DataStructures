//Brayden Fidler
#include "Stack.h"
#include "Disc.h"
#include <iostream>
#include <cstdlib>
using namespace std;


int main(int argc, char *args[])
{
  //Exiting if too many/little arguments
  if (argc != 2) {
    cout << "Error, please give one argument." << endl;
    exit(0);
  }
  
  //Number of discs is only argument in command line
  int totalDiscs = stoi(args[1]);
  
  //Creating towers
  Stack <Disc*> towers[3];
  
  //Populating first tower
  for (int i = totalDiscs; i > 0; i--) {
    Disc * nextDisc = new Disc(i);
    towers[0].push(nextDisc);
  }
  
  while (towers[2].getCount() != totalDiscs) {
    
    //randomizing move
    int fromStk = rand() % 3;
    int toStk = rand() % 3;
    
    //Checking if towers are the same and the sending tower has discs
    if (fromStk != toStk && towers[fromStk].getCount() != 0) {
    
      //Checking if recipient tower is empty
      if (towers[toStk].getCount() == 0) {  
          //Message
          cout << "Moving disc of size " << towers[fromStk].peek()->getWidth();
          cout << " from tower " << fromStk + 1 << " to tower ";
          cout << toStk + 1 << "." << endl;
          //popping from sender and pushing to recipient       
          towers[toStk].push(towers[fromStk].pop());
      }
      else {
        //Checking if recipient tower can receive a disc from sender 
        if (towers[fromStk].peek()->compare(*towers[toStk].peek())) {  
          //Message
          cout << "Moving disc of size " << towers[fromStk].peek()->getWidth();
          cout << " from tower " << fromStk + 1 << " to tower ";
          cout << toStk + 1 << "." << endl;
          //popping from sender and pushing to recipient       
          towers[toStk].push(towers[fromStk].pop());
        }
      }
    }
  }
  
  return 0;
}
