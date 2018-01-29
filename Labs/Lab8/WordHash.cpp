#include "WordHash.h"
#include <iostream>


//Constructor
WordHash::WordHash(int arrLen) : arrayLength(arrLen > 1 ? arrLen : 1),
  data(new WordCount* [arrayLength]), count(0) 
{
  for (int i = 0; i < arrayLength; i++)
    data[i] = nullptr;  
}
  

//Destructor
WordHash::~WordHash()
{
  //looping through data array and deleting pointer that are not null
  for (int i = 0; i < arrayLength; i++)  
        delete data[i];
      
  delete [] data;
}


//rehashes and resizes the hash table
void WordHash::rehash()
{
  //new double pointer for data
  WordCount** newData = new WordCount* [arrayLength * 2 + 1];
  
  //looping through entire data array
  for(int i = 0; i < arrayLength; i++) {
    
    //finding a location for all address that have a wordCount stored
    if (data[i] != nullptr) {
      
      int address, j = 0;
      
      //hashing then linear probing until an address is found
      do {
	//updated arrayLength used to calculate
        address = (WordHash::hashOf(data[i]->getWord()) + j) % (arrayLength * 2 + 1) ;
	
	//if address is open old data goes to this address
        if (newData[address] == nullptr){
          
          newData[address] = data[i];
          data[i] = nullptr;
        }
	//if not linear probe is incremented
        else {
    
          j++;
        }
      } while(data[i] != nullptr);
    }
  }

  delete [] data;
  
  data = newData;
  arrayLength = arrayLength * 2 + 1;
}


//adding a word to the hash table
void WordHash::addWord(const string & word)
{ 
  //rehashing if new load factor will reach LOAD_FACTOR
  if(((double)count + 1) / arrayLength > LOAD_FACTOR)
    this->rehash();

  int address, i = 0;
  
  //addWord to the hashtable
  do { 
    address = (WordHash::hashOf(word) + i) % arrayLength;
    
    //if address is empty, word goes here
    if (data[address] == nullptr){
      
      data[address] = new WordCount(word);
      count++;
    }
    //if not, two possible situations
    else {
      
      //word is already present and is incremented, or word needs
      //different address and j is incremented
      if(data[address]->getWord() == word)
        data[address]->incrementCount();
      else
        i++;
    }
  } while(word != data[address]->getWord());
}


//printing the most common word
void WordHash::printCommon() const
{
  WordCount* mostCommon = nullptr;
  
  //looping through the array
  for(int i = 0; i < arrayLength; i++) {
    
    //checks if data is present at the location
    if(data[i] != nullptr) {
      
      //if mostcommon hasn't been given a value, it starts here
      if(mostCommon == nullptr)
        mostCommon = data[i];
      
      //compares count of mostcommon to the current wordcount in the table
      if(mostCommon->getCount() < data[i]->getCount())
        mostCommon = data[i];
    }
  }
  
  cout << "Most common word is: " << mostCommon->getWord() << endl;
}


//setting load factor
const double WordHash::LOAD_FACTOR = 0.7;
