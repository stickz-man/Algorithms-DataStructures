#include "wordLadder.h"
using namespace std;


//Global Variables
int sizeDictionary = 0;
string *dictionary;

int main (int argc, char *argv[]) {

  int i = 0;
  string emptyStorage;
  stack <string> ladder;  
  ifstream inputFile;   

  
  //Error checking for incorrect command line arguments
  if(argc != 5) {
    cout << "Error, please enter the input file, start word, goal word, and"
      << " number of steps in command line arguments." << endl;
    exit(0);
  }
  
  
  //Opening input file given in the command line
  inputFile.open(argv[1]);
    //If input file name give does not open, an error message is printed
  if(!inputFile.is_open()) {
    cout << "Error, file did not open properly." << endl;
    exit(0);
  }
  
  
  //stoi convert string from argv to an int for steps 
  int steps = stoi(argv[4]);
  //setting the start and goal words using arguments
  string startWord = argv[2];
  string goalWord = argv[3];
  
  
  /*Counting the number of words in the file to determine the size of the
    array for the dictionary*/
  while(inputFile >> emptyStorage)
    sizeDictionary++;
  
  
  /*Clearing the file and set it to the beginning, so the strings can then
    be read*/
  inputFile.clear();
  inputFile.seekg(0, inputFile.beg);
  
  
  //Creating dictionary according to the size we got from counting lines
  dictionary = new string[sizeDictionary];
  
  
  //Loading strings into the dictionary
  while (inputFile >> dictionary[i++]);
  
  //Sorting the dictionary alphabetically
  radixSort(dictionary, sizeDictionary);
  //creating used words for isLadder
  string usedWords[sizeDictionary]; 
  
  
  //printing out the dictionary one by one
  for(int i = 0; i < sizeDictionary; i++)
    cout << dictionary[i] << endl;
  
  
  //Printing a Word Ladder
  cout << endl << "Word Ladder for " << startWord << " to " << goalWord << ":";
  cout << endl;
  
  //Checking if ladder exists and fills ladder stack if so
  if(isLadder(startWord, goalWord, steps, usedWords, 0, ladder)){
    
    //printing all but last word of ladder stack    
    while (ladder.size() != 1) {
      cout << ladder.top() << "---> " << endl;
      ladder.pop();
    }
    
    //last word of ladder    
    cout << ladder.top() << endl;
  }
  //no ladder found  
  else
    cout << "Ladder not found." << endl;
  
  
  //freeing memory before ending program
  delete [] dictionary; 
  return 0; 
}

/*This function checks to see if a word ladder is present given a start and 
  goal word, the number of steps, and an array of used words. It also fills
  a ladder stack if a ladder can be found.*/
bool isLadder(const string start,const string goal, int steps, string used[],
  int sizeUsed, stack <string> & ladder) {
  
  //Returns true and pushes the word because a ladder has been found  
  if (start == goal) {
    
    ladder.push(goal);
    return true;
  }
  
  //Returning false, out of steps
  if (steps == 0)
    return false;
  
  //Searching through dictionary for a word to continue the ladder  
  for (int i = 0; i < sizeDictionary; i++) {
    
    //if a word has not been used and is one letter from start it is considered
    if (isOneLetter(start, dictionary[i]) && 
      !isPresent(dictionary[i], used, sizeUsed)) {
      
      //updating the used words array
      used[sizeUsed++] = dictionary[i];
      
      /*Checks to see if a ladder can be found, pushes the start word if so and
        returns true*/
      if (isLadder(dictionary[i], goal, steps - 1, used, sizeUsed, ladder)) {
      
        if (steps > 1)
          ladder.push(start);
        
        return true;
      }
    }
  }
  
  /*returning false because dictionary has been search and 
    a ladder couldnt be found*/
  return false;
}

/*This function checks to see if two words are one letter appart from each
  other*/
bool isOneLetter(const string wordA, const string wordB) {

  int misMatch = 0;
  
  //searches each char for chars that arent the same
  for (int i = 0; i < (int)wordA.length(); i++){
    
    if (wordA[i] != wordB[i])
      misMatch++;
  }
  
  //returns whether or not only one char was different
  return (misMatch == 1);
}

/*This function checks to see if a word is present in an array*/
bool isPresent(const string word, const string *dict, int size) {
  
  //loops through the enter array
  for (int i = 0; i < size; i++) {
    
    //true if the word is found
    if (word == dict[i])
      return true;
  }
  
  return false;
}




