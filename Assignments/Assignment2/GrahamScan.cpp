//Brayden Fidler
// partial implementation of GrahamScan
#include <vector>
#include <cmath>
using namespace std;
#include "GrahamScan.h"

// returns bearing of line from Point A to Point B
double angle(Point &A, Point &B) 
{
  /*Returning the angle from the y axis below point x. For example: A = (0, 0)
    If Y = (0, - 5) = 0.0. Y = (5,0) = 90.0. Y = (0,5) = 180.0.*/ 
  if (B.getY() >= A.getY()) {
    //Must add 1.5708 radians if B is above A on Y axis 
    return 1.5708 + atan((double)(B.getY() - A.getY()) / (B.getX() - A.getX()));
  }
  else {   
    return atan((double)(B.getX() - A.getX()) / (A.getY() - B.getY()));
  } 
}

// sorts points by angle counterclockwise from list[0] using insertion sort - given
void sortByAngleFromFirst(vector<Point> &list)
{
  for(unsigned int round = 1; round <list.size(); round++) {
      
    int i = round; 
    Point newPoint = list[round];
    double newAngle = angle(list[0], newPoint);
      
    while( i>1 && ( newAngle < angle(list[0], list[i-1]) ) ) {
	       
      list[i]=list[i-1];
      i--;
    }
      
    list[i] = newPoint;
  }
} 

// finds leftmost point in list and moves it into position 0
void moveLeftmostFirst( vector<Point> &list ) 
{
  //iterating through the list
  for (int i = 1; i < (int)list.size(); i++) {
    
    //Swaps points if a Point is further left than position 0
    if (list.at(i).getX() < list.at(0).getX()) {
      Point temp(list.at(i).getX(), list.at(i).getY());
      list.at(i) = list.at(0);
      list.at(0) = temp;
    }
  }
}

// returns true if going A to B to C is a left turn - given
bool isLeftTurn( Point &A, Point &B, Point &C ) 
{
  return (B.getY() - A.getY()) * (C.getX()-B.getX()) <
    (C.getY() - B.getY()) * (B.getX() - A.getX());
}

// prints out contents of list
void debugDump( vector<Point> &list)
{
  //Incrementing through list printing point coordinates
  for (int i = 0; i < (int)list.size(); i++)
    cout << "(" << list.at(i).getX() << "," <<list.at(i).getY() << ") ";
}

// determines convex hull of list using Graham scan
vector<Point> convexHull( vector<Point> &list)
{
  //creating both a vector and stack for the hull
  PointStack hullStack;
  vector<Point> hull;
  int i = 2;
  
  //Pushing first two points
  hullStack.push(list.at(0));
  hullStack.push(list.at(1));
  
  //loops through the entire list
  while (i < (int)list.size()) {
    
    //pushes if left turn, pops if right turn
    if (isLeftTurn(hullStack.peekUnder(), hullStack.peek(), list.at(i)))
      hullStack.push(list.at(i++));
    else
      hullStack.pop();
  }
  
  //Hull points being transferred from stack to vector
  while (!hullStack.isEmpty())
    hull.push_back(hullStack.pop());
    
  return hull;
}

// determines convex shells of list by repeated use of convexHull
void shellIt( vector<Point> &list ) 
{
  //Main hull found printed
  vector <Point> mainHull = convexHull(list);
  cout << "Hull is ";
  debugDump(mainHull);
  cout << endl;
  
  //Main hull removed from list
  removePts(mainHull, list);
  
  cout << endl << "Shells are:" << endl;
  
  //Printing shells until list is empty
  while (!list.empty()) {
    
    //Prints remaining points if not enough for a hull
    if (list.size() < 2) {
      debugDump(list); 
      list.clear();
    }
    else {
      /*Moves another point first and sorts, then finds a convex hull.
        Hull is printed and the points are removed from the list */
      moveLeftmostFirst(list);
      sortByAngleFromFirst(list);
      vector <Point> newShell = convexHull(list);
      debugDump(newShell);
      cout << endl;
      removePts(newShell, list);
    }
  }
}

//function removes points in out from list
void removePts(vector<Point> &out, vector<Point> &list)
{
  //iterating through each element of out
  for (int i = 0; i < (int)out.size(); i++) {
    
    bool removed = false;
    int j = 0;
  
    //iterating through list or until a point is removed
    while (j < (int)list.size() && !removed) {
      
      //once the point is found its swapped and popped
      if (out.at(i) == list.at(j)) {
        list.at(j) = list.at((int)list.size() - 1);
        list.pop_back();
        removed = true;
      }
      
      j++;
    }
  }
}
