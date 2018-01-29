//Brayden
#include "Disc.h"


//Defualt Constructor
Disc::Disc() : width(0)
{}


//Constructor
Disc::Disc(int w) : width(w)
{}


//Returns the width of the Disc
int Disc::getWidth()
{
  return width;
}


//Returns true if disc width is smaller than the width of the disc passed
bool Disc::compare(const Disc & d)
{
  return (width < d.width);
}