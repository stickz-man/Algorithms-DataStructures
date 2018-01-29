//Brayden Fidler
#include "FiloTree.h"


//Constructor taking an array and a depth
FiloTree::FiloTree(string leaves[], int depth)
{
  //setting count under the assumption of a complete tree
  count = pow(2, depth);
  //creating root node
  root = new FiloNode;
  
  //building the tree
  createTree(leaves, root, depth, 0);
}


//Constructor taking the string of a filename
FiloTree::FiloTree(string fileName)
{
  //creating/opening file
  ifstream inputFile;
  inputFile.open(fileName);
  
  //checking for file being properly opened
  if (!inputFile) {
    cout << "Unable to open file " << fileName << endl;
    exit(0);  
  }

  //setting root and count
  root = nullptr;
  inputFile >> count;
  
  //a vector for nodes and a vector for labels
  vector<FiloNode*> nodes;
  vector<double> colDist;
  vector<vector<double>> rowDist;
  int mergeCt = 0;
  
  //reading species from input file, creating nodes, and storing them
  for (int i = 0; i < count; i++) {
    string tempStr;
    inputFile >> tempStr;
    FiloNode *tempNode = new FiloNode(tempStr);
    nodes.push_back(tempNode);
  }
  
  //reading distances inputFile and storing them
  for (int i = 0; i < count; i++) {
    
    //populating the column vector
    for (int j = 0; j < count; j++) { 
      double temp; 
      inputFile >> temp;
      colDist.push_back(temp);
    }
    
    //pushing column vector into row vector and clearing column
    rowDist.push_back(colDist);
    colDist.clear();
  }
  
  //building the tree from nodes in the vector
  while ((int)nodes.size() > 0) {
    
    //if one node left, it becomes the root and vector is emptied
    if ((int)nodes.size() == 1) {
      
      root = nodes[0];
      nodes.clear();
    }
    else {
      
      //setting 2 random species to start
      int lowA = 0;
      int lowB = rowDist.size() - 1;
      
      //looping through distances between species - findin shortest distance
      for (int i = 0; i < (int)rowDist.size(); i++) {
        for (int j = 0; j < (int)rowDist[i].size(); j++) { 
          //checking for lowest distance between two species (if not the same)
          if(i != j && rowDist[i][j] < rowDist[lowA][lowB]) {
            lowA = i;
            lowB = j;
          } 
        }
      }
      
      //merging two nodes
      FiloNode *mergeNode = new FiloNode(to_string(++mergeCt), 
        nodes[lowA], nodes[lowB]);
      
      //adding merged node to vector and removing old nodes
      nodes[lowA] = mergeNode;
      nodes.erase(nodes.begin() + lowB);
      
      //vector to hold doubles in row B
      vector <double> hold(rowDist[lowB]);
      
      //calculating merged distances and placing them at row A and col A
      for (int i = 0; i < (int)rowDist[lowA].size(); i++)
        if (i != lowA) {
          rowDist[lowA][i] = (rowDist[lowA][i] + hold[i]) / 2;
          rowDist[i][lowA] = rowDist[lowA][i];
        }
          
      //deleting row for B
      rowDist.erase(rowDist.begin() + lowB);
                  
      //deleting column for B
      for (int i = 0; i < (int)rowDist.size(); i++)
        rowDist[i].erase(rowDist[i].begin() + lowB);
    }
  }

  inputFile.close();
}


//Destructor
FiloTree::~FiloTree()
{
  deleteTree(root);
}


//Dumping predorder style
void FiloTree::dump() const
{
  preOrder(root, 0);
}


//Comparing two trees
bool FiloTree::compare( const FiloTree &A, const FiloTree &B)
{
  //unequal leaf counts mean trees are different
  if (A.count != B.count)
    return false;
  else {
    
    //only check root if count is 1
    if (A.count == 1)
      return A.root->lable == B.root->lable;
    //2+ count means root shouldnt have nullptr for children
    else
      //must compare child nodes, regardless of order
      return ((compareNodes(A.root->left, B.root->left) && 
        compareNodes(A.root->right, B.root->right))
        || (compareNodes(A.root->left, B.root->right) && 
        compareNodes(A.root->right, B.root->left)));  
  }
}


//PreOrder function prints a parent node followed by its children
void FiloTree::preOrder(const FiloNode *parent, int depth) const
{
  if (parent != nullptr) {
  
    //printing parent
    indent(depth); 
    cout << parent->lable << endl;;
    
    //traversing left tree
    preOrder(parent->left, depth + 1);
  
    //traversing right tree
    preOrder(parent->right, depth + 1);
  }
}


//Indenting according to depth
void FiloTree::indent(int depth) const
{
  for (int i = 0; i < depth; i++)
    cout << "...";
}


//Creates a subtree given the array, height of current node, and an iterator
void FiloTree::createTree(string leaves[], FiloNode *parent, int height, int i)
{
  //checking if end of branch has been reached
  if (height == 0) {
    //setting the leaf
    parent->lable = leaves[i];
  }
  else {
    /*creating iterator for right branch - j corresponds to
     i + 2 ^ (height - 1) */
    int j = i + pow(2, height - 1);
    //creating left and right nodes
    parent->left = new FiloNode;
    parent->right = new FiloNode;
    
    //building trees on left and right branches - height reduced
    createTree(leaves, parent->left, height - 1, i);
    createTree(leaves, parent->right, height - 1, j);
  }
}


//Deletes a node and its children
void FiloTree::deleteTree(FiloNode *parent)
{
  if (parent == nullptr)
    return;

  //deleting left/right branches first
  deleteTree(parent->left);
  deleteTree(parent->right);
  delete parent;
}


//Compares two nodes
bool FiloTree::compareNodes(const FiloNode *a, const FiloNode *b)
{
  //*making the assumption that a node has 2 or no children*
  cout <<"*";
  //if no children on both compare labels bc nodes are leaves
  if (a->left == nullptr && b->left == nullptr)
    return a->lable == b->lable;
  //two cases - both are internal nodes or just one is an internal node 
  else {
    
    //if both are nodes - compare children in both orders
    if (a->left != nullptr && b->left != nullptr)
      return ((compareNodes(a->left, b->left) && 
        compareNodes(a->right, b->right)) 
        || (compareNodes(a->left, b->right) && 
        compareNodes(a->right, b->left))); 
    //one is an internal node, one is leaf
    else
      return false;
  }
}