/**********************
	Brayden Fidler
	CPSC 2120 Lab
	Wayne Goddard
	Lab 2
***********************/

#include "Recursion.h"

int main (int argc, char *argv[])
{
  ifstream inputFile;
  
  //making sure that a file name was entered in command line
  if (argc == 2){
    //opening file from command line 
    inputFile.open(argv[1]);
  }
  else {
    cout << "Error Opening File" << endl;
    exit(0);
  }
  
  //Error Messsage if file isn't open  
  if(!inputFile.is_open()) {
    cout << "Error Opening File" << endl;
    exit(0);
  }

  //making a grid based of the input file then printing its groups
  Recursion gridA(inputFile);
  gridA.print();
  
  return 0;
}

//Constructor
Recursion::Recursion(ifstream & input)
{
  //Double loops through 10x10 array
  for (int i = 0; i < 10; i++) {
  
    for (int j = 0; j < 10; j++) {
      //creating a char and reading the next one from the file to it
      char nextChar;
      input.get(nextChar);
      
      //skips endlines
      if (nextChar == '\n')
        input.get(nextChar);
                
      //if the next char is X grid is given a 1
      if(nextChar == 'X')
        grid[i][j] = 1;
      //if its a . grid is given a 0
      else
        grid[i][j] = 0;
    }
  }
}

//Prints out the groups of the 2d array
void Recursion::print()
{
  int gridCopy[10][10];

  //Copying grid to grid copy
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      gridCopy[i][j] = grid[i][j];
  
  int groupCount = 0;
  
  //printing groups
  for (int i = 0; i < 10; i++) {
    
    for (int j = 0; j < 10; j++) {
      /*For every new group found, print group is found nd groupCount
      is updated. */
      if(grid[i][j] == 1) {
        cout << "Group " << groupCount << ": ";
        printGroupWith(i, j);
        cout << endl;
        groupCount++;
      }
    }
  }

  //Recopying gridcopy back to grid, since it has been altered
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      grid[i][j] = gridCopy[i][j];
}

void Recursion::printGroupWith(int row, int col) 
{ 
  //Nothing happens if the functions is called on an empty coordinate 
  if(grid[row][col] == 1) {
    //Coordinates are printed
    cout << "(" << row << "," << col << ") ";
    //The location is cleared to prevent infinite recursion
    grid[row][col] = 0;
    
    //Calls recursive function on location below it
    if(row < 9)
      printGroupWith(row + 1, col);
    
    //Calls recursive function on location above it
    if(row > 0)
      printGroupWith(row - 1, col);
     
    //Calls recursive function on location to the right 
    if(col < 9)
      printGroupWith(row, col + 1);
    
    //Calls recursive function on location to the left
    if(col > 0)
      printGroupWith(row, col - 1);
  
  }

}