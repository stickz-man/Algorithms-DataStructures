//Brayden Fidler
#include "Point.h"

//Constructor
Point::Point(int x, int y) : X(x), Y(y)
{}


//Copy Constuctor
Point::Point(const Point & other) : X(other.X), Y(other.Y)
{}


//Returns the X coordinate of the point
int Point::getX() const
{
  return X;
}


//Returns Y coordinate of the point
int Point::getY() const
{
  return Y;
}


//Checks whether or not two points have the same coordinates
bool Point::operator==(const Point & other) const
{
  return (X == other.X && Y == other.Y);
}


//Prints out the coordinates of a point
ostream & operator<<(ostream & out, const Point & P)
{
  out << "(" << P.X << "," << P.Y << ")";
  return out;
}  

