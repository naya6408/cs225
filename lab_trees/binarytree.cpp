#include "binarytree.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include "random.h"

using namespace std;

/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    cout << endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
    mirrorHelper(root);  //your code here
}

template <typename T>
void BinaryTree<T>::mirrorHelper(Node* subRoot){
        if (subRoot != NULL){
            mirrorHelper(subRoot->left);
            mirrorHelper(subRoot->right);
            Node *temporary = subRoot->right; // temp holds the location of the left side
            Node *temporary2 = subRoot->left; // holding the location of the right side
            subRoot->right = subRoot->left; // we can still access left because we have temporary pointing to that area
            subRoot->left= temporary;
        }
        else {
            return;
        }
}


/**
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
  return isOrdered(root);
   // return isOrdered(root); //isOrdered(root);// your code here
}

template <typename T>
bool BinaryTree<T>::isOrdered(const Node* subRoot) const
{
    bool flag1 = false;
    bool flag2 = false;
    Node* lnode = subRoot->left;
    Node* rnode = subRoot->right;
    // Base case - null node
    if (subRoot == NULL) {
        return true;
    }


      if (lnode != NULL) {
        while (lnode->left != NULL) {
          lnode = lnode->left;
        }
      }

      if (rnode != NULL) {
        while (rnode->right != NULL) {
          rnode = rnode->right;
        }
      }

      if (lnode == NULL) {
        flag1 = true;
      }

      else if ((lnode->elem) <= (subRoot->elem)) {
        flag1 = isOrdered(subRoot->left);
      }

      if (rnode == NULL) {
        flag2 = true;
      }

      else if ((rnode->elem) >= (subRoot->elem)) {
        flag2 = isOrdered(subRoot->right);
      }
        return (flag1 && flag2);

}



/**
 * creates vectors of all the possible paths from the root of the tree to any leaf
 * node and adds it to another vector.
 * Path is, all sequences starting at the root node and continuing
 * downwards, ending at a leaf node. Paths ending in a left node should be
 * added before paths ending in a node further to the right.
 * @param paths vector of vectors that contains path of nodes
 */
template <typename T>
void BinaryTree<T>::printPaths(vector<vector<T> > &paths) const
{
      vector<T> bruce;
      printPathsh(root,paths, bruce);// your code here
}

template <typename T>
void BinaryTree<T>::printPathsh(const Node* subRoot, vector<vector<T> > &inputv, vector<T> temp) const
{
    if (subRoot == NULL) {
        return;
    }

    temp.push_back(subRoot->elem);

    if(subRoot->left == NULL && subRoot->right == NULL) {
        for (int i = 0; i < (int)temp.size(); i++) {
          cout << temp[i] << " ";
        }
        cout << endl;
        inputv.push_back(temp);
      }
    printPathsh(subRoot->left, inputv, temp);
    printPathsh(subRoot->right, inputv, temp);
}

/**
 * Each node in a tree has a depthance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the depthances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the tree.
 * @return The sum of the depthances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    return sumDistances(root, 0);
}
template <typename T>
int BinaryTree<T>::sumDistances(Node * subRoot, int dist) const{
	if (subRoot == NULL){
         return 0;
	}
      int distLeft = sumDistances(subRoot->left,dist+1);
      int distRight = sumDistances(subRoot->right,dist+1);
    	return dist + distLeft + distRight;
 }
