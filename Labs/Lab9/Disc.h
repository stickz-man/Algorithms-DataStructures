//Brayden Fidler
#ifndef DISC_H
#define DISC_H


class Disc 
{
  private:
    int width; 

  public:
    Disc();
    Disc(int);
    int getWidth();
    bool compare(const Disc &);

};


#endif