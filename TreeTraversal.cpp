/**
 * @file TreeTraversal.cpp
 * @author Conner Lusk
 * @brief Intro/Brief implementation of Tree Traversing
 * @version 0.1
 * @date 2022-08-02
 * @copyright Copyright (c) 2022
 * @note Tree Traversing Basics
 * - Traversing a tree means visiting every node in the tree
 * Inorder traversal
 *  1. First, visit all the nodes in the left subtree
 *  2. Then the root node
 *  3. Visit all the nodes in the right subtree
 * Preorder traversal
 *  1. Visit root node
 *  2. Visit all the nodes in the left subtree
 *  3. Visit all the nodes in the right subtree
 * Postorder traversal
 *  1. Visit all the nodes in the left subtree
 *  2. Visit all the nodes in the right subtree
 *  3. Visit the root node
 */
#include <iostream>

/**
 * @brief This struct defines a node which has data and a left or right node
 */
struct Node {
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

/**
 * @brief This is a function that applies a preorder traversal
 * 
 * @param node is the node we want to traverse
 */
void preOrderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }
    std::cout << node->data << "-->";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

/**
 * @brief This is a function that applies a postorder traversal
 * 
 * @param node is the node we want to traverse
 */
void postOrderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    std::cout << node->data << "-->";
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

int main() {
  struct Node* root = new Node(1);
  root->left = new Node(12);
  root->right = new Node(9);
  root->left->left = new Node(5);
  root->left->right = new Node(6);
  std::cout << "Inorder traversal\n";
  inorderTraversal(root);
  std::cout << "\nPreorder traversal\n";
  preOrderTraversal(root);
  std::cout << "\nPostorder traversal\n";
  postOrderTraversal(root);
}


