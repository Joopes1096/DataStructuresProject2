//Header File Binary Search Tree
#ifndef H_BinaryTree
#define H_BinaryTree

//*************************************************************
// Author: D.S. Malik
//
// class binaryTreeType
// This class specifies the basic operations to implement a
// binary tree.
//*************************************************************

#include <iostream>

using namespace std;

     //Definition of the node
template <class elemType>
struct BinaryTreeNode
{
    elemType info;
    BinaryTreeNode<elemType> *llink;
    BinaryTreeNode<elemType> *rlink;
};

   //Definition of the class
template <class elemType>
class BinaryTreeType
{
public:
    const BinaryTreeType<elemType>& operator=
                 (const BinaryTreeType<elemType>&);
      //Overload the assignment operator.
    bool isEmpty() const;
      //Returns true if the binary tree is empty;
      //otherwise, returns false.
    void inorderTraversal() const;
      //Function to do an inorder traversal of the binary tree.
    void preorderTraversal() const;
      //Function to do a preorder traversal of the binary tree.
    void postorderTraversal() const;
      //Function to do a postorder traversal of the binary tree.

    int treeHeight() const;
      //Returns the height of the binary tree.

    int treeNodeCount() const;
      //Returns the number of nodes in the binary tree.

    int treeLeavesCount() const;
      //Returns the number of leaves in the binary tree.

    int singleParent() const;
      //Returns the number of nodes in the binary tree that
      //have only one child

    void destroyTree();
      //Deallocates the memory space occupied by the binary tree.
      //Postcondition: root = NULL;

    BinaryTreeType(const BinaryTreeType<elemType>& otherTree);
      //copy constructor

    BinaryTreeType();
      //default constructor

    ~BinaryTreeType();
      //destructor

protected:
    BinaryTreeNode<elemType>  *root;

private:
    void copyTree(BinaryTreeNode<elemType>* &copiedTreeRoot,
                  BinaryTreeNode<elemType>* otherTreeRoot);
      //Makes a copy of the binary tree to which 
      //otherTreeRoot points. The pointer copiedTreeRoot  
      //points to the root of the copied binary tree.

    void destroy(BinaryTreeNode<elemType>* &p);
      //Function to destroy the binary tree to which p points. 
      //Postcondition: p = NULL

    void inorder(BinaryTreeNode<elemType> *p) const;
      //Function to do an inorder traversal of the binary
      //tree to which p points.  
    void preorder(BinaryTreeNode<elemType> *p) const;
      //Function to do a preorder traversal of the binary
      //tree to which p points.  
    void postorder(BinaryTreeNode<elemType> *p) const;
      //Function to do a postorder traversal of the binary
      //tree to which p points.  

    int height(BinaryTreeNode<elemType> *p) const;
      //Function to return the height of the binary tree
      //to which p points. 
    int max(int x, int y) const;
      //Returns the larger of x and y.
    int nodeCount(BinaryTreeNode<elemType> *p) const;
      //Function to return the number of nodes in the binary 
      //tree to which p points 
    int leavesCount(BinaryTreeNode<elemType> *p) const;
      //Function to return the number of leaves in the binary 
      //tree to which p points 
    int singleParent(BinaryTreeNode<elemType> *p) const;
      //Returns the number of nodes that have only one child
      //in the binary tree to which p points
};

    //Definition of member functions

template <class elemType>
BinaryTreeType<elemType>::BinaryTreeType()
{
    root = NULL;
}

template <class elemType>
bool BinaryTreeType<elemType>::isEmpty() const
{
    return (root == NULL);
}

template <class elemType>
void BinaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

template <class elemType>
void BinaryTreeType<elemType>::preorderTraversal() const
{
    preorder(root);
}

template <class elemType>
void BinaryTreeType<elemType>::postorderTraversal() const
{
    postorder(root);
}

template <class elemType>
int BinaryTreeType<elemType>::treeHeight() const
{
    return height(root);
}

template <class elemType>
int BinaryTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}

template <class elemType>
int BinaryTreeType<elemType>::treeLeavesCount() const
{
    return leavesCount(root);
}

template <class elemType>

int BinaryTreeType<elemType>::singleParent() const
{
    return singleParent(root);
}
template <class elemType>
void  BinaryTreeType<elemType>::copyTree
                      (BinaryTreeNode<elemType>* &copiedTreeRoot,
		               BinaryTreeNode<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else
    {
        copiedTreeRoot = new BinaryTreeNode<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
        copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
} //end copyTree

template <class elemType>
void BinaryTreeType<elemType>::inorder(BinaryTreeNode<elemType> *p) const
{
    if (p != NULL)
    {
        inorder(p->llink);
        cout << p->info << " ";
        inorder(p->rlink);
    }
}

template <class elemType>
void BinaryTreeType<elemType>::preorder(BinaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		cout<<p->info<<" ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template <class elemType>
void BinaryTreeType<elemType>::postorder(BinaryTreeNode<elemType> *p) const
{
    if (p != NULL)
    {
        postorder(p->llink);
        postorder(p->rlink);
        cout << p->info << " ";
    }		
}

     //Overload the assignment operator
template <class elemType>
const BinaryTreeType<elemType>& BinaryTreeType<elemType>::
           operator=(const BinaryTreeType<elemType>& otherTree)
{  
    if (this != &otherTree) //avoid self-copy
    {
        if (root != NULL)  //if the binary tree is not empty, 
                           //destroy the binary tree
            destroy(root);

        if (otherTree.root == NULL) //otherTree is empty
            root = NULL;
        else
            copyTree(root, otherTree.root);
    }//end else

    return *this; 
}

template <class elemType>
void  BinaryTreeType<elemType>::destroy(BinaryTreeNode<elemType>* &p)
{
    if (p != NULL)
    {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = NULL;
    }
}

template <class elemType>
void  BinaryTreeType<elemType>::destroyTree()
{
    destroy(root);
}

	//copy constructor
template <class elemType>
BinaryTreeType<elemType>::BinaryTreeType
              (const BinaryTreeType<elemType>& otherTree)
{
    if (otherTree.root == NULL) //otherTree is empty
        root = NULL;
    else
        copyTree(root, otherTree.root);
}

template <class elemType>
BinaryTreeType<elemType>::~BinaryTreeType()
{
    destroy(root);
}

template <class elemType>
int BinaryTreeType<elemType>::height(BinaryTreeNode<elemType> *p) const
{
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->llink), height(p->rlink));
}

template <class elemType>
int BinaryTreeType<elemType>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}

//ToDo
template <class elemType>
int BinaryTreeType<elemType>::nodeCount(BinaryTreeNode<elemType> *p) const
{
    int c = 1;
 
    if (p == NULL)
        return 0;
    else
    {
        c += nodeCount(p->llink);
        c += nodeCount(p->rlink);
        return c;
     }

    return 0;
}

//ToDo
template <class elemType>
int BinaryTreeType<elemType>::leavesCount(BinaryTreeNode<elemType> *p) const
{
    
  if(p == NULL)       
    return 0;
  if(p->llink == NULL && p->rlink==NULL)      
    return 1;            
  else
    return leavesCount(p->llink) + leavesCount(p->rlink);      


}

//ToDo
template <class elemType>
int BinaryTreeType<elemType>::singleParent(BinaryTreeNode<elemType> *p) const
{
   if ( p == NULL )
           return 0;  // The tree is empty.  It contains no nodes.
        else {
           int count = 1;   // Start by counting the root.
           count += singleParent(p->llink);  // Add the number of nodes
                                            //     in the left subtree.
           count += singleParent(p->rlink); // Add the number of nodes
                                            //    in the right subtree.
           return count;  // Return the total.
        }
}
#endif
