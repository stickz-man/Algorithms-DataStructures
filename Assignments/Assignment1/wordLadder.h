#ifndef WORD_LADDER_H
#define WORD_LADDER_H

#include "radixSort.h"
#include "stringQueue.h"
#include <iostream>
#include <fstream>
#include <stack>

//function prototype
bool isLadder(const string, const string, int, string [], int, 
  stack <string> &);

bool isOneLetter(string, string);

bool isPresent(const string, const string *, int);

#endif