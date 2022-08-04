/**
 * @file LinkedList.cpp
 * @author Conner Lusk
 * @brief Intro/Brief implementation of a Linked List
 * @version 0.1
 * @date 2022-07-31
 * @copyright Copyright (c) 2022
 * @note Linked List Structure
 * A linked list is a linear data structure that includes a series of connected nodes.
 *  -Each node stores the data and the address of the next node. 
 * Basic Structure
 * - Give the address of the first node a special name called HEAD. 
 * - The last node in the linked list can be identified because its next portion points to NULL
 * Complexity
 * - Search O(n)
 * - Insert O(1)
 * - Deletion O(1)
 * Applications
 * - Dynamic memory allocation
 * - Implemented in stack and queue
 * - Hash tables, Graphs
 */
#include <iostream>

/**
 * @brief This represents a Node
 */
class Node {
    public: 
        int value;
        Node* next;
};

int main() {
    // Inialize the example nodes
    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;
    // Allocate 3 nodes in the heap
    one = new Node();
    two = new Node();
    three = new Node();
    // Assign the values of each node
    one->value = 1;
    two->value = 2;
    three->value = 3;
    // Link the nodes with eachother
    one->next = two;
    two->next = three;
    // print the linked list value
    head = one;
    while (head != NULL) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << "\n";

}
