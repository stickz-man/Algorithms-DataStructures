//Brayden Fidler
#ifndef CHAR_RECORD_H
#define CHAR_RECORD_H

#include <string>
using namespace std;

class CharRecord {

  public:
    //constructors
    CharRecord();
    CharRecord(string cs, int c);
    
    //methods
    string getCharString() const;  
    int getCount() const;
    
    //comparison
    bool operator > (const CharRecord &);
    bool operator < (const CharRecord &);
  
  private:
    string charStr;
    int count;
};

//code works but different
//two comparison operators, necessary?
//do they want it to fix non uppercase?

#endif