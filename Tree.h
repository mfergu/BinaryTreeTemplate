// code from Dietel's C++ how to program 8th ed.
//Template Tree class definition
#ifndef Tree_h
#define Tree_h

#include <iostream>
#include "TreeNode.h"
using namespace std;

//Tree class-template definition
template< typename NODETYPE > class Tree
{
  public:
    Tree(); //constructor
    void insertNode( const NODETYPE &);
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;
  private:
    TreeNode< NODETYPE> *rootPtr;
  
    //utility functions
    void insertNodeHelper( TreeNode< NODETYPE > **, const NODETYPE &);
    void preOrderHelper( TreeNode< NODETYPE > *) const;
    void inOrderHelper( TreeNode< NODETYPE > *) const;
    void postOrderHelper( TreeNode< NODETYPE > *) const;
}; //end class Tree

//constructor
template< typename NODETYPE>
Tree< NODETYPE >::Tree()
{
  rootPtr = 0; //indicate tree is initially empty
} //end Tree constructor

// insert node in Tree
template< typename NODETYPE>
void Tree< NODETYPE>::insertNode( const NODETYPE &value)
{
  insertNodeHelper( &rootPtr, value);
} //end function insertNode

//utility function called by insertNode; recvs a ptr to a ptr
//so that the function can modify ptr's value
template< typename NODETYPE >
void Tree< NODETYPE>::insertNodeHelper(
  TreeNode< NODETYPE> **ptr, const NODETYPE &value)
{
  //subtree is empty; create a new TreeNode containing value
  if( *ptr == 0)
    *ptr = new TreeNode< NODETYPE>( value);
  else // subtree is not empty
  {
    //data to insert is less than data in current node
    if( value < ( *ptr )->data )
      insertNodeHelper( &( ( *ptr)->leftPtr ), value);
    else
    {
      //data to insert is greater than data in current node
      if( value > (*ptr)->data )
        insertNodeHelper( &( ( *ptr)->rightPtr), value);
      else //duplicate data value ignored
        cout << value << " dup" << endl;
    } //end else
  } //end else
} //end function insertNodeHelper

//begin preorder traversal of Tree
template< typename NODETYPE>
void Tree< NODETYPE>::preOrderTraversal() const
{
  preOrderHelper( rootPtr );
} //end function preOrderTraversal

//utility function to perform preorder traversal of tree
template< typename NODETYPE>
void Tree< NODETYPE>::preOrderHelper( TreeNode<NODETYPE> *ptr) const
{
  if( ptr != 0)
  {
    cout << ptr->data << ' '; //process node
    preOrderHelper( ptr->leftPtr); //traverse left subtree
    preOrderHelper( ptr->rightPtr); //traverse right subtree
  } //endif
} //end function preorder helper

//begin inorder traversal of Tree
template< typename NODETYPE>
void Tree< NODETYPE >::inOrderTraversal() const
{
  inOrderHelper(rootPtr);
} //end function inOrderTraversal

//utility function to perform inorder traversal of Tree
template< typename NODETYPE>
void Tree< NODETYPE>::inOrderHelper( TreeNode< NODETYPE> *ptr) const
{
  if( ptr != 0)
  {
    inOrderHelper( ptr->leftPtr); //traverse left subtree
    cout << ptr->data << ' '; //process node
    inOrderHelper( ptr->rightPtr); //traverse right subtree
  } // endif
} //end function inOrderHelper


//begin postorder traversal of Tree
template< typename NODETYPE>
void Tree< NODETYPE>::postOrderTraversal() const
{
  postOrderHelper(rootPtr);
} //end function postOrderTraversal

// utility function to perform postorder traversal of Tree
template< typename NODETYPE>
void Tree< NODETYPE>::postOrderHelper( TreeNode< NODETYPE> *ptr ) const
{
  if( ptr != 0 )
  {
    postOrderHelper( ptr->leftPtr); //traverse left subtree
    postOrderHelper( ptr->rightPtr); // traverse right subtree
    cout << ptr->data << ' '; //process node
  } //endif
} //end function postOrderHelper

#endif


