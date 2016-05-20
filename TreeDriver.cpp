#include <iostream>
#include <iomanip>
#include "Tree.h"
using namespace std;

int main()
{
  Tree< int> intTree; //create a tree of int values
  int intValue;
  cout << "Enter 10 ints: \n";

  //insert 10 ints to intTree
  for( int i = 0; i < 10; ++i)
  {
    cin >> intValue;
    intTree.insertNode( intValue);
  }
  
  cout << "\nPreorder Traversal\n";
  intTree.preOrderTraversal();
  
  cout << "\nInorder Traversal\n";
  intTree.inOrderTraversal();

  cout << "\nPostorder Traversal\n";
  intTree.postOrderTraversal();
  
  Tree< double> doubleTree; //create Tree of double values
  double doubleValue;
  
  cout << fixed << setprecision( 1)
    << "\n\nEnter 10 double values:\n";
  
  //insert 10 doubles to doubleTree
  for( int j = 0; j < 10; ++j)
  {
    cin >> doubleValue; 
    doubleTree.insertNode( doubleValue);
  } //end for

  cout << "\nPreorder Traversal\n";
  doubleTree.preOrderTraversal();
  
  cout << "\nInorder Traversal\n";
  doubleTree.inOrderTraversal();

  cout << "\nPostorder Traversal\n";
  doubleTree.postOrderTraversal();
  cout << endl;
} //end main
