//Brayden Fidler
#include "PointStack.h"


//Constuctor
PointStack::PointStack() : stackTop(nullptr)
{}


//Destructor
PointStack::~PointStack()
{
  //pointer to hold next Node to be delete
  Node *grab;  
  
  //Looping through list untill the top point is null
  while (stackTop != nullptr) {
  
    /*Top of stack is grabbed, and stack top becomes the next point in the
      list. Grab is set to point to null then deleted.*/
    grab = stackTop;
    stackTop = grab->next;
    grab->next = nullptr;
    delete grab;
  }
}


//Pushes a point to the top of the stack
void PointStack::push(const Point & item)
{
  /*Holds top of the stack, creates a new Node for the point. New node becomes
    stackTop and is pointed to the old stackTop*/  
  Node *c = stackTop;
  stackTop = new Node(item);
  stackTop->next = c;
}


//Returns the point on top of the stack and removes the node holding it
Point PointStack::pop()
{
  //Returns nothing point if stack is empty
  if (stackTop == nullptr)
    return NOTHING;
  
  /*Creates a node to hold the stackTop. StackTop is moved to the the next
    node in the list. A Point is created with the original stackTop's data
    and then the original is deleted.*/  
  Node *c = stackTop;
  stackTop = c->next;
  Point P(c->data);
  c->next = nullptr;
  delete c;
  
  return P;
}

//Returns the point on top of the stack
Point & PointStack::peek() const
{
  //If stack is empty Nothing is returned
  if (stackTop == nullptr)
    return NOTHING;
  
  return stackTop->data;
}


//Returns the point below the top of the stack
Point & PointStack::peekUnder() const
{
  /*If the stack only has 1 point or has 0 points, Nothing is returned.*/
  if (stackTop == nullptr)
    return NOTHING;
    
  if (stackTop->next == nullptr)
    return NOTHING;
  
  return stackTop->next->data;
}

//Returns true if stack is empty
bool PointStack::isEmpty() const
{
  return (stackTop == nullptr);
}

//Point for underflow
Point PointStack::NOTHING(0,0);

