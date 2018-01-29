// Goddard Stack.h 2015
#ifndef STACK_H
#define STACK_H

template <class E>
class Stack 
{
 private:
   E* arr;
   int count;
   static const int capacity = 100;

 public:
   Stack();
   ~Stack();

   E pop();
   void push(E item);
   E peek();

   bool isEmpty() const 
   {
     return (count==0);
   }
   int getCount() const 
   {
     return count;
   }

};

#include "Stack.cpp"

#endif