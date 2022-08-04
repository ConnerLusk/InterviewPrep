/**
 * @file BinaryTree.cpp
 * @author Conner Lusk
 * @brief Intro/Brief implementation of a Binary Tree
 * @version 0.1
 * @date 2022-08-02
 * @copyright Copyright (c) 2022
 * @note Binary Tree Data Structure
 * A binary tree is a tree data structure in which each parent node can have at most two children
 * Each node of a binary tree consists of three items
 *  1. Data item
 *  2. Pointer to left item
 *  3. Pointer to right item
 * Types of Binary Trees
 *  1. Full binary tree
 *     - A full Binary tree is a special type of binary tree in which every parent node/internal node h
 *        as either two or no children
 *     - Full Binary Tree Theorems
 *       - Let, i = the number of internal nodes
 *              n = be the total number of nodes
                l = number of leaves
                λ = number of levels
         1. The number of leaves is i + 1
         2. The total number of nodes is 2i + 1
         3. The number of internal nodes is (n – 1) / 2
         4. The number of leaves is (n + 1) / 2
         5. The total number of nodes is 2l – 1
         6. The number of internal nodes is l – 1
         7. The number of leaves is at most 2λ - 1
 *  2. Perfect Binary Tree
       - Type of binary tree in which every internal node has exactly two child nodes and 
          all the leaf nodes are at the same level
       - Perfect Binary Tree Theorems
         1. All the internal nodes have a degree of 2
         2. If a single node has no children, it is a perfect binary tree of height h = 0
         3. If a node has h > 0, it is a perfect binary tree if both of its subtrees are of height
              h - 1 and are non-overlapping
         4. A perfect binary tree of height h has 2h + 1 – 1 node
         5. A perfect binary tree with n nodes has height log(n + 1) – 1 = Θ(ln(n))
         6. A perfect binary tree of height h has 2h leaf nodes
         7. The average depth of a node is Θ(ln(n))
    3. Complete Binary Tree
       - A complete binary tree is just like a full binary tree, but with two major differences
         1. Every level must be completely filled
         2. All the leaf elements must lean towards the left
         3. The last leaf element might not have a right sibling
            - Complete binary tree doesn't have to be a full binary tree
       - Creation
         1. Select the first element of the list to be the root node
         2. Put the second element as a left child of the root node and the third element as the right child
         3. Put the next two elements as children of the left node of the second level
            - Put the next two elements as children of the right node of the second level
         4. Keep repeating until you reach the last element
       - Relationship between array indexes and tree element
         - If the index of any element in the array is i, the element in the index 2i+1 will
            become the left child and element in 2i+2 index will become the right child
         - The parent of any element at index i is given by the lower bound of (i-1)/2
    4. Degenerate or Pathological Tree
       - A degenerate or pathological tree is the tree having a single child either left or right
    5. Skewed Binary Tree
       - A skewed binary tree is a pathological/degenerate tree in which the tree is either 
         dominated by the left nodes or the right nodes
       - There are two types of skewed binary tree: left-skewed binary tree and right-skewed binary tree
    6. Balanced Binary Tree
       - It is a type of binary tree in which the difference between the height of the left 
          and the right subtree for each node is either 0 or 1
 */
// Binary Tree in C++
#include <stdlib.h>
#include <iostream>

// A node with data and left and right nodes
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

// Dynamically create a new node
struct Node *newNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return (node);
}

/**
 * @brief This is a function that applies a inorder traversal
 * 
 * @param node is the node we want to traverse
 */
void inorderTraversal(struct Node* node) {
  if (node == NULL)
    return;
  inorderTraversal(node->left);
  std::cout << node->data << "-->";
  inorderTraversal(node->right);
}

/**
 * @brief Finds whether a binary tree is full or not
 * 
 * @param root is the root of the tree
 * @return true if full
 * @return false if not full
 */
bool isFullBinaryTree(struct Node* root) {
    if (root == NULL || root->left == NULL && root->right == NULL) {
        return true;
    }
    if ((root->left) && (root->right))
        return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
    return false;
}

/**
 * @brief Finds the depth of a node
 * 
 * @param node is the node we want to find the depth of
 * @return int is the depth of the node
 */
int findDepth(Node *node) {
  int depth = 0;
  while (node != NULL) {
    depth++;
    node = node->left;
  }
  return depth;
}

/**
 * @brief Checks to see if the given root is perfect
 * 
 * @param root is the root that is being checked
 * @param depth is the depth
 * @param level is the level
 * @return true if perfect
 * @return false if not perfect
 */
bool isPerfectRoot(struct Node *root, int depth, int level = 0) {
  if (root == NULL)
    return true;
  if (root->left == NULL && root->right == NULL)
    return (depth == level + 1);
  if (root->left == NULL || root->right == NULL)
    return false;
  return isPerfectRoot(root->left, depth, level + 1) &&
         isPerfectRoot(root->right, depth, level + 1);
}

/**
 * @brief Checks to see a binary tree is perfect given the root
 * 
 * @param root 
 * @return true 
 * @return false 
 */
bool isBinaryTreePerfect(Node *root) {
  int depth = findDepth(root);
  return isPerfectRoot(root, depth);
}

/**
 * @brief Recursivley count the number of nodes
 * 
 * @param root is the root of the binary tree
 * @return int is the amount of nodes
 */
int countNumberNodes(struct Node *root) {
  if (root == NULL)
    return (0);
  return (1 + countNumberNodes(root->left) + countNumberNodes(root->right));
}

/**
 * @brief Checks to see if the binary tree is complete
 * 
 * @param root is the root of the binary tree
 * @param index is the index
 * @param numberNodes is the number of nodes
 * @return true if complete
 * @return false if not complete
 */
bool checkComplete(struct Node *root, int index, int numberNodes) {
  if (root == NULL)
    return true;
  if (index >= numberNodes)
    return false;
  return (checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2 * index + 2, numberNodes));
}

/**
 * @brief Checks to see if the heights of a binary tree are balences
 * 
 * @param root is the root of the binary tree
 * @param height is the height of the tree
 * @return true if balenced
 * @return false if not balenced
 */
bool checkHeightBalance(Node *root, int height) {
  int leftHeight, rightHeight = 0;
  int l, r = 0;
  if (root == NULL) {
    height = 0;
    return 1;
  }
  l = checkHeightBalance(root->left, leftHeight);
  r = checkHeightBalance(root->right, rightHeight);
  height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
  if (std::abs(leftHeight - rightHeight >= 2))
    return 0;
  else
    return l && r;
}


int main() {
  // inorder traversal
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  std::cout << "\nInorder traversal: ";
  inorderTraversal(root);
  // Full Tree
  struct Node *full = NULL;
  full = newNode(1);
  full->left = newNode(2);
  full->right = newNode(3);
  full->left->left = newNode(4);
  full->left->right = newNode(5);
  full->left->right->left = newNode(6);
  full->left->right->right = newNode(7);
  bool isFull = isFullBinaryTree(full);
  if (isFull) {
    std::cout << "\nBinary tree is full\n";
  }
  else {
    std::cout << "\nBinary tree is not full\n";
  }
  // Perfect tree
  struct Node *perfect = newNode(1);
  perfect->left = newNode(2);
  perfect->right = newNode(3);
  perfect->left->left = newNode(4);
  perfect->left->right = newNode(5);
  perfect->right->left = newNode(6);
  bool isPerfect = isBinaryTreePerfect(perfect);
  if (isPerfect) {
    std::cout << "Binary tree is perfect\n";
  }
  else {
    std::cout << "Binary tree is not perfect\n";
  }
  // Complete tree
  struct Node *complete = newNode(1);
  complete->left = newNode(2);
  complete->right = newNode(3);
  complete->left->left = newNode(4);
  complete->left->right = newNode(5);
  complete->right->left = newNode(6);
  int numberNodes = countNumberNodes(complete);
  int index = 0;
  bool isComplete = checkComplete(complete, index, numberNodes);
  if (isComplete) {
    std::cout << "Binary tree is complete\n";
  }
  else {
    std::cout << "Binary tree is not complete\n";
  }
  // Balenced
  int height = 0;
  Node *balenced = newNode(1);
  balenced->left = newNode(2);
  balenced->right = newNode(3);
  balenced->left->left = newNode(4);
  balenced->left->right = newNode(5);
  bool isBalenced = checkHeightBalance(balenced, height);
  if (isBalenced) {
    std::cout << "Binary tree is balenced\n";
  }
  else {
    std::cout << "Binary tree is not balenced\n";
  }
}