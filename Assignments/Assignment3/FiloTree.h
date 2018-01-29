//Brayden Fidler
#ifndef FILO_TREE_H
#define FILO_TREE_H

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;


struct FiloNode 
{
  string lable;
  FiloNode *left, *right;

  FiloNode(string lab="X", FiloNode *L=nullptr, FiloNode *R=nullptr) 
     : lable(lab), left(L), right(R)
  {}
};


class FiloTree 
{
  private:
    //fields
    FiloNode *root;
    int count;
    //helper methods
    void preOrder(const FiloNode *parent, int depth) const;
    void indent(int depth) const;
    void createTree(string leaves[], FiloNode *parent, int height, int i);
    void deleteTree(FiloNode *parent);
    static bool compareNodes(const FiloNode *a, const FiloNode *b);
  
  public:
    //Constructors/Destructor
    FiloTree(string leaves[], int depth);
    FiloTree(string fileName);
    ~FiloTree( );
    //Methods
    void dump( ) const;
    static bool compare( const FiloTree &A, const FiloTree &B);

};


#endif