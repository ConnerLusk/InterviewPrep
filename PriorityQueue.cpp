/**
 * @file PriorityQueue.cpp
 * @author Conner Lusk
 * @brief Intro/Brief implementation of a Priority Queue
 * @version 0.1
 * @date 2022-07-31
 * @copyright Copyright (c) 2022
 * @note Priority Queue Data Structure
 * A Priority Queue is a special type of Queue in which each element is associated with a prioriety value and elements are 
 *  served on the basis of priority.
 *  - The higher priority elements are seved first
 *  - If elements with the same priority occur, they are served according to their order in the Queue.
 * Assigning priority value
 * - Generally, the value of the element itself is considered for assigning the priority
 * Difference between Priority Queue and Normal Queue
 * - A Queue follows Fifo whereas in a Priority Queue the values are removed on the basis of priority
 *   - The element with the highest priority is removed first
 * Implementation
 * - A Priority Heap can be implemented using an array, linked list, heap, or binary search tree. 
 *   - Heap provides an efficient implementation of Priority Queues
 * Operations
 * - Insertion
 *   - Inserting an element into a max-heap is done by the following steps:
 *     1. Insert the element to the end of the tree
 *     2. Heapify the tree
 * - Deletion
 *   - Deleting an element from a max-heap is done by the following steps:
 *     1. Select the element to be deleted
 *     2. Swap it with the last element
 *     3. Remove the last element
 *     4. Heapify the tree
 * - Peeking
 *   - Peek operation returns the maximum element from Max Heap or minimum element from Min Heap without deleting the node.
 *   - Return the root node
 * - Extract-Max/Min from the Priority Queue
 *   - Extract-Max returns the node with maximum value after removing it from a Max Heap 
 *   - Extract-Min returns the node with minimum value after removing it from Min Heap
 * Complexity
 * - Peaking is O(1)
 * - Insertion is O(log n)
 * - Deletion is O(log n)
 * Applications
 * - Dijkstra's algorithm
 * - Implementing a Stack
 * - Load balancing and interrupt handling in an operating system
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
