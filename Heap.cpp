/**
 * @file Heap.cpp
 * @author Conner Lusk
 * @brief Intro/Brief implementation of a Heap
 * @version 0.1
 * @date 2022-07-31
 * @copyright Copyright (c) 2022
 * @note Heap Data Structure
 * Heap data structure is a complete binary tree that satisfies the heap property, where any given node is:
 *  1. Always greater than its child node/s and the key of the root node is the largest among all other nodes
 *     - This property is also called max heap property
 *  2. Always smaller than the child node/s and the key of the root node is the smallest among all other nodes
 *     - This property is also called min heap property
 * Heap Operations
 * - Heapify is the process of creating a heap data structure from a binary tree
 *   - Used to create a Min-Heap or a Max-Heap
 *   - Steps to Heapify:
 *     1. Create a complete binary tree from the array
 *     2. Start from the first index of non-leaf node whose index is given by (n / 2) - 1
 *     3. Set current element i as the largest
 *     4. The index of left child is given by 2i + 1 and the right child is given by 2i + 2
 *        - If leftChild is greater than currentElement, set leftChildIndex as largest
 *        - If rightChild is greater than element in largest, set rightChildIndex as largest
 *     5. Swap largest with currentElement
 *     6. Repeat steps 3-6 until the subtrees are also heapified.
 * - Insertion
 *   1. Insert the new element at the end of the tree
 *   2. Heapify the tree
 * - Deletion
 *   1. Select the element to be deleted
 *   2. Swap it with the last element
 *   3. Remove the last element
 *   4. Heapify the tree
 * - Peek (Find max/min)
 *   1. return the rootNode
 * - Extract-Max/Min
 *   - Extract-Max returns the node with maximum value after removing it from a Max Heap 
 *   - Extract-Min returns the node with minimum after removing it from Min Heap
 */
#include <iostream>
#include <vector>

/**
 * @brief This function swaps the position of two elements
 * 
 * @param a is one of the elements 
 * @param b is the other element
 */
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

/**
 * @brief This function Heapifies the current heap tree
 * 
 * @param heapTree is the heap tree
 * @param root is the index of the root
 */
void heapify(std::vector<int> &heapTree, int root) {
    int size = heapTree.size();
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left < size && heapTree[left] > heapTree[largest]) {
        largest = left;
    }
    if (right < size && heapTree[right] > heapTree[largest]) {
        largest = right;
    }
    // If the root is not the largest, the swap and heapify the rest
    if (largest != root) {
        swap(&heapTree[root], &heapTree[largest]);
        heapify(heapTree, largest);
    }
}

/**
 * @brief This function inserts an element into a heap tree
 * 
 * @param heapTree is the heap tree
 * @param element is the element that is being inserted
 */
void insert(std::vector<int> &heapTree, int element) {
    int size = heapTree.size();
    if (size == 0) {
        heapTree.push_back(element);
    }
    else {
        heapTree.push_back(element);
        for (int i = (size / 2) - 1; i >= 0; i--) {
            heapify(heapTree, i);
        }
    }
}

/**
 * @brief This function deletes a given element from the heap tree
 * 
 * @param heapTree is the heap tree
 * @param element is the element being deleted
 */
void deleteNode(std::vector<int> &heapTree, int element) {
    int size = heapTree.size();
    int i;
    // Find the index of the element that is going to be removed
    for (i = 0; i < size; i ++) {
        if (heapTree[i] == element) {
            break;
        }
    }
    // Move the element to the end of the heap tree
    swap(&heapTree[i],&heapTree[size-1]);
    // Remove the element
    heapTree.pop_back();
    // Heapify the remaining elements
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(heapTree, i);
    }
}

/**
 * @brief This function prints the current heaptree
 * 
 * @param heapTree is the current heaptree
 */
void print(std::vector<int> &heapTree) {
    std::cout << "Priority Queue:\n";
    for (int i = 0; i < heapTree.size(); i++) {
        std::cout << heapTree[i] << " ";
    }
    std::cout << "\n";
}

int main() {
  std::vector<int> heapTree;
  insert(heapTree, 3);
  insert(heapTree, 4);
  insert(heapTree, 9);
  insert(heapTree, 5);
  insert(heapTree, 2);
  std::cout << "Max-Heap array: ";
  print(heapTree);
  deleteNode(heapTree, 4);
  print(heapTree);
}