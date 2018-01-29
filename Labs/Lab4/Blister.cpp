//Brayden Fidler

#include "Blister.h"
using namespace std;

//Constructor
Blister::Blister(string init)
{	
	//creating Bode with first letter of string for start
	start = new Bode(init[0]);
	//putting cursor at start
	Bode *cursor = start;
	
	//Starting loop at second letter of string
	for(int i = 1; i < (int)init.length(); i++) {
		
		//next pointer of cursor is created with next letter
		cursor->next = new Bode(init[i]);
		//cursor is now the next pointer in the list
		cursor = cursor->next;
    cursor->next = nullptr;
	}
}


ostream &operator<< (ostream &out, const Blister &other)
{
	//looping from start until cursor reaches null
	for (Bode* cursor = other.start; cursor != nullptr; cursor = cursor->next)
		//printing letter
		out << cursor->base;
		
	return out;
}


int Blister::length() const
{
	int length = 0;
  //setting cursor at start pointer
	Bode *cursor = start;

  //looping until the end of linked list	
	while (cursor != nullptr) {
		cursor = cursor->next;
		length++;
	}
  
  //returning length
	return length;
}

//Checks to see if a blister is a one letter substitution from the orignal
bool Blister::isSubstitutionOf(const Blister & other) const
{
  int mismatchCount = 0;
  
  //Ensures lengths of Blisters are the same
  if (this->length() == other.length()) {
    
    //points cursors to start of Blisters
    Bode *cursorA = start;
    Bode *cursorB = other.start;
    
    //loops to end of one blister (they're the same length)
    while(cursorA != nullptr){
      
      //checks if the letters are different, counts if so
      if(cursorA->base != cursorB->base)
        mismatchCount++;
    
      //moves cursors to next pointer
      cursorA = cursorA->next;
      cursorB = cursorB->next;
    }
    
    //returns true if just one letter is substituted
    return mismatchCount == 1;
  }
  //if lengths are unequal, its not a substitution
  else
    return false;
}


bool Blister::isInsertionOf(const Blister & other) const
{
  //length should be one greater for insertion to be possible
  if (this->length() == other.length() + 1) {
  
    //tracks whether or not the insertion is accounted for
    bool insertionMade = false;
    
    //points cursors to start of Blisters
    Bode *cursorA = start;
    Bode *cursorB = other.start;
    
    //loops to end of one blister other (its shorter)
    while(cursorB != nullptr){
      
      if(insertionMade) {
        
        /*if insertion has been made, then the rest of the bases should be 
          equal*/
        if(cursorA->base != cursorB->base)
          return false;
        
        //moves cursor to next pointer 
        cursorA = cursorA->next;
        cursorB = cursorB->next;
      }
      else {
  
        //if bases are the same, the cursor keeps moving      
        if(cursorA->base == cursorB->base) {
        
          cursorA = cursorA->next;
          cursorB = cursorB->next;
        }
        else {
          
          /*Bases are not the same so we assume this is the location of the 
            insertion. CursorA moves, but B remains the same since it is 
            pointed to the smaller word which is other. */
          cursorA = cursorA->next;
          insertionMade = true;
        }
      } 
    }
    
    /*returns true if insertion has been accounted for and all other bases
      are the same*/
    return insertionMade;
  }
  //if length is not one greater, than its not an insertion
  else
    return false;
}


//Destructor
Blister::~Blister()
{
	//creating Bode for deleting
	Bode *grab;
	
	//running until end of linklist
	while (start != nullptr) {
		
		//grab is start pointer
		grab = start;
		//start pointer becomes its next location
		start = start->next;
		//grab pointer is nullified
		grab->next = nullptr;
		//grab is deleted
		delete grab;
	}
}

