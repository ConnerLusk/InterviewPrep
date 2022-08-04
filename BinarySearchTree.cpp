/**
 * @file BinarySearchTree.cpp
 * @author Conner Lusk
 * @brief Intro/Brief implementation of Binary Search Tree
 * @version 0.1
 * @date 2022-08-02
 * @copyright Copyright (c) 2022
 * @note Binary Search Tree Data Structure
 * Binary search tree is a data structure that quickly allows us to maintain a sorted list of numbers
 * - Called a binary tree because each tree node has a maximum of two children and because it 
 *    can be used to search for the presence of a number in O(log(n)) time
 * The properties that separate a binary search tree from a regular binary tree is
 * 1. All nodes of left subtree are less than the root node
 * 2. All nodes of right subtree are more than the root node
 * 3. Both subtrees of each node are also BSTs i.e. they have the above two properties
 */
#include <iostream>

struct Node {
    int value;
    struct Node *right, *left;
};

/**
 * @brief Creates a new node
 * 
 * @param newValue is the value of the node
 * @return struct Node* is the new node
 */
struct Node *newNode(int newValue) {
  struct Node *tempNode = (struct Node *)malloc(sizeof(struct Node));
  tempNode->value = newValue;
  tempNode->left = tempNode->right = NULL;
  return tempNode;
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
  std::cout << node->value << "-->";
  inorderTraversal(node->right);
}

/**
 * @brief Inserts a value into a given BST
 * 
 * @param node is the node of the root
 * @param value is the value that is being inserted
 * @return struct Node* is the node with the inserted value
 */
struct Node * insertNode(struct Node* node, int value) {
    if (node == NULL) return newNode(value);
    if (value < node->value) {
        node->left = insertNode(node->left, value);
    }
    else {
        node->right = insertNode(node->right, value);
    }
    return node;
}

/**
 * @brief This gets the node with the minimum value in the tree
 * 
 * @param node is the root of the binary search tree
 * @return struct Node* is the node
 */
struct Node * minimumValueNode(struct Node* root) {
    struct Node* currentNode = root;
    while (currentNode && currentNode->left != NULL) {
        currentNode = currentNode->left;
    }
    return currentNode;
}

/**
 * @brief This gets the node with the largest value
 * 
 * @param node is the root of the binary search tree
 * @return struct Node* is the node with max value
 */
struct Node * maximumValueNode(struct Node* root) {
    struct Node* currentNode = root;
    while (currentNode && currentNode->right != NULL) {
        currentNode = currentNode->right;
    }
    return currentNode;
}

/**
 * @brief This deletes a value from the binary search tree
 * 
 * @param root is the root of the binary search tree
 * @param value is the value that is wanted to be deleted
 * @return struct Node* is the binary search tree without the value
 */
struct Node *deleteNode(struct Node *root, int value) {
  if (root == NULL) return root;
  if (value < root->value)
    root->left = deleteNode(root->left, value);
  else if (value > root->value)
    root->right = deleteNode(root->right, value);
  else {
    if (root->left == NULL) {
      struct Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct Node *temp = root->left;
      free(root);
      return temp;
    }
    struct Node *temp = minimumValueNode(root->right);
    root->value = temp->value;
    root->right = deleteNode(root->right, temp->value);
  }
  return root;
}

int main() {
  struct Node *root = NULL;
  root = insertNode(root, 8);
  root = insertNode(root, 3);
  root = insertNode(root, 1);
  root = insertNode(root, 6);
  root = insertNode(root, 7);
  root = insertNode(root, 10);
  root = insertNode(root, 14);
  root = insertNode(root, 4);

  std::cout << "Inorder traversal: ";
  inorderTraversal(root);
  std::cout << "\nAfter deleting 10\n";
  root = deleteNode(root, 10);
  std::cout << "Inorder traversal: ";
  inorderTraversal(root);
}


