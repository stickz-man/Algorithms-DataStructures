// goddard - TreeDriver.cpp - 2016
// a rather poor tester for TreeNode
//Brayden Fidler
#include <iostream>
using namespace std;
#include "TreeNode.h"

int main() 
{ 
      // Create tree by hand here.
     TreeNode * t1 = new TreeNode("A"); 
     TreeNode * t2 = new TreeNode("B"); 
     TreeNode * t3 = new TreeNode("C"); 
     TreeNode * t4 = new TreeNode("D"); 
     TreeNode * t5 = new TreeNode("E"); 
     TreeNode * t6 = new TreeNode("F"); 
     TreeNode * t7 = new TreeNode("G");
     //added nullptr to test methods
     TreeNode * tN = nullptr;
     
     //Full Left Nodes
     TreeNode * l1 = new TreeNode("A"); 
     TreeNode * l2 = new TreeNode("B"); 
     TreeNode * l3 = new TreeNode("C");
     
     //Full right Nodes
     TreeNode * r1 = new TreeNode("D"); 
     TreeNode * r2 = new TreeNode("E"); 
     TreeNode * r3 = new TreeNode("F");
     
     
     //ZigZag Nodes
     TreeNode * z1 = new TreeNode("G"); 
     TreeNode * z2 = new TreeNode("H"); 
     TreeNode * z3 = new TreeNode("I");
     
     
     cout << "Should return A B C D E F G:" << endl;
     cout << *t1 << " " << *t2 << " " << *t3 << " " << *t4 << " " << *t5 << " " << *t6 << " " << *t7 << endl;
     
     t1->setLeft(t2); 
     t1->setRight(t3);
     t2->setLeft(t4);
     t2->setRight(t5);
     t3->setLeft(t6); 
     t3->setRight(t7);
     
     
     //setting left nodes
     l1->setLeft(l2);
     l2->setLeft(l3);
     
     //setting right nodes
     r1->setRight(r2);
     r2->setRight(r3);
     
     //setting zigzag
     z1->setLeft(z2);
     z2->setRight(z3);
    
     cout << "Postorder should be DEBFGCA" << endl;     
     t1->postorder( );
     //added new line
     cout << endl;
     
     //testing null
     cout << "Null postorder test:" << endl;
     tN->postorder();
     cout << endl;
     
     cout << "Preorder should be ABDECFG" << endl;     
     t1->preorder( );
     //added new line
     cout << endl;
     
     //testing null
     cout << "Null preorder test:" << endl;
     tN->preorder();
     cout << endl;
     
     //testing all lefts
     cout << "Preorder should be: ABC" << endl;
     l1->preorder();
     cout << endl << "Postorder should be: CBA" << endl;
     l1->postorder();
     cout << endl;
     
     //testing all rights
     cout << "Preorder should be: DEF" << endl;
     r1->preorder();
     cout << endl << "Postorder should be: FED" << endl;
     r1->postorder();
     cout << endl;
     
     //testing all zigzags
     cout << "Preorder should be: GHI" << endl;
     z1->preorder();
     cout << endl << "Postorder should be: IHG" << endl;
     z1->postorder();
     cout << endl;
     
     //testing random internal node
     cout << "Preorder test should be: CFG" << endl;
     t3->preorder();
     cout << endl << "Postorder test should be: FGC" << endl;
     t3->postorder();
     cout << endl;
    
     delete t1;
     delete t2;
     delete t3;
     delete t4;
     delete t5;
     delete t6;
     delete t7;
     delete tN;
     return 0;
} 
