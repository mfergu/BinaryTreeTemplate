//code from dietel's C++ how to Program 8th ed.
//Template TreeNode class definition
#ifndef TreeNode_h
#define TreeNode_h

//forward declaration of class Tree
template< typename NODETYPE> class Tree;

//TreeNode class-template defn
template< typename NODETYPE>
class TreeNode
{
    friend class Tree< NODETYPE>;
  public:
    //constructor
    TreeNode( const NODETYPE &d)
      : leftPtr( 0), //pointer to left subtree
        data( d), //tree node data
        rightPtr( 0) //pointer to right subtree
      {
      //empty body
      }

    //return copy of node's data
    NODETYPE getData() const
    {
    return data;
    }
  private:
    TreeNode< NODETYPE> *leftPtr; // pointer to left subtree
    NODETYPE data;
    TreeNode< NODETYPE> *rightPtr; // pointer to right subtree
}; //end class TreeNode

#endif
  
