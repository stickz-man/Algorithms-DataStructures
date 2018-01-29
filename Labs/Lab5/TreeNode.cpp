//Brayden Fidler
#include "TreeNode.h"
#include <stack>


//Constructor
TreeNode::TreeNode(string str) : value(str), lchild (nullptr), rchild (nullptr)
{}


//Sets the left child of the tree
void TreeNode::setLeft(TreeNode* l)
{
  lchild = l;
}


//Sets the right child of the tree
void TreeNode::setRight(TreeNode* r)
{
  rchild = r;
}

//Prints out the tree in post order
void TreeNode::postorder() const
{
  //checks for nullptr first
  if (this == nullptr) {
  
    cout << "Empty tree!";
    return;
  }
  
  //calls postOrder down the left branch
  if(lchild != nullptr)
    lchild->postorder();
    
  //calls postOrder down the right branch  
  if(rchild != nullptr)
    rchild->postorder();
    
  //prints the node's value  
  cout << value;
}


//Prints out the tree in pre order
void TreeNode::preorder() const
{
  //checks for nullptr first
  if (this == nullptr) {
  
    cout << "Empty Tree";
    return;
  }
  
  //creating a stack to hold nodes
  stack <TreeNode*> myNodes;
  
  //creating cursor
  TreeNode * cursor; ;
  
  //pushing first node to the stack
  myNodes.push((TreeNode *)this);

  //looping until the stack is completely empty (the whole tree is traversed)
  while(!myNodes.empty()) {
    
    //cursor is set to the top of the stack, node is popped
    cursor = myNodes.top();
    myNodes.pop();
    
    //node is printed
    cout << cursor->value;
    
    //right child pushed first, so left can sit on top of it
    if(cursor->rchild != nullptr)
      myNodes.push(cursor->rchild);
    
    //left node pushed second, so it can be popped and traversed first
    if(cursor->lchild != nullptr)
      myNodes.push(cursor->lchild);
  }
}


//overloaded operator <<
ostream & operator<< (ostream & out, const TreeNode & t)
{
  //prints value of the node
  out << t.value;
  return out;
}

