/**
 * @file Deque.cpp
 * @author Conner Lusk
 * @brief Intro/Brief implementation of a Deque
 * @version 0.1
 * @date 2022-07-31
 * @copyright Copyright (c) 2022
 * @note Deque Data Structure
 * Deque or Double Ended Queue is a type of queue in which insertion 
 *  and removal of elements can either be performed from the front or the rear
 *  - Does not follow FIFO rule 
 * Types of Deques
 * - Input Restricted Deque
 *   - Input is restricted at a single end but allows deletion at both the ends
 * - Output Restricted Deque
 *   - Output is restricted at a single end but allows insertion at both the ends
 * Operations on a Deque
 * - Initializing:
 *   1. Take an array (deque) of size n
 *   2. Set two pointers at the first position and set Front = -1 and Rear = 0
 * - Insertion to the front
 *   1. Check the position of Front
 *   2. If Front < 1, reinitialize Front = n-1, if not decrease Front by 1
 *   3. Add new value into array[Front]
 * - Insertion to the back
 *   1. Check if the array is full
 *   2. If the deque is full, reinitialize Rear = 0, if not increase Rear by 1
 *   3. Add new value into array[Rear]
 * - Deletion from front
 *   1. Check if the deque is empty
 *   2. If the deque is empty deletion cannot be performed, if deque has only one element set Front = -1 and Rear = -1,
 *       if Front is at the end set Front = 0, if anything else Front = Front + 1
 * - Deletion from rear
 *   1. Check if the deque is empty
 *   2. If the deque is empty deletion cannot be performed, if deque has only one element set Front = -1 and Rear = -1,
 *       if Rear is at the front set Rear = n - 1, if anything else Rear = Rear -1
 * - Check empty
 *   - Check to see if Deque is empty by seeing if Front is -1
 * - Check full
 *   - Checks to see if the Deque is full by seeing if Front is 0 and Rear is n - 1 or if Front  = Rear + 1
 * Complexity
 * - The time complexity of all the above operations is O(1).
 * Applications
 * - Undo operations
 * - Store history in browsers
 */
#include <iostream>
#define MAX_SIZE 10

class Deque {
    private:
        int data[MAX_SIZE];
        int front;
        int rear;
        int size;
    public:
        /**
         * @brief Construct a new Deque object
         * 
         * @param size is the size of the Deque
         */
        Deque(int size) {
            front = -1;
            rear = 0;
            this->size = size;
        }
        /**
         * @brief This method returns whether a Deque full or not
         */
        bool isFull() {
            return ((front == 0 && rear == size - 1) || front == rear + 1);
        }
        /**
         * @brief This method return whether a Deque is emtpy or not
         */
        bool isEmpty() {
            return (front == -1);
        }
        /**
         * @brief This method inserts an element to the front of the Deque
         * 
         * @param element is the element that is being inserted
         */
        void frontInsertion(int element) {
            if (isFull()) {
                std::cout << "Deque is full\n";
                return;
            }
            if (front == -1) {
                front = 0;
                rear = 0;
            }
            else if (front == 0) {
                front = size - 1;
            }
            else front--;
            data[front] = element;
        }
        /**
         * @brief This method inserts an element to the rear of the Deque
         * 
         * @param element is the element being insterted
         */
        void rearInsertion(int element) {
            if (isFull()) {
                std::cout << "Deque is full\n";
                return;
            }
            if (front == -1) {
                front = 0;
                rear = 0;
            }
            else if (rear == size - 1) {
                rear = 0;
            }
            else rear ++;
            data[rear] = element;
        }
        /**
         * @brief This method deletes from the front of the Deque
         */
        void frontDeletion() {
            if (isEmpty()) {
                std::cout << "Dequeu is empty\n";
                return;
            }
            if (front == rear) {
                front = -1;
                rear = -1;
            }
            else if (front == size - 1) {
                front = 0;
            }
            else front ++;
        }
        /**
         * @brief This method deletes from the rear of the Deque
         */
        void rearDeletion() {
            if (isEmpty()) {
                std::cout << "Dequeu is empty\n";
                return;
            }
            if (front == rear) {
                front = -1;
                rear = -1;
            }
            else if (rear == 0) {
                rear = size - 1;
            }
            else rear --;
        }
        /**
         * @brief Get the Front of the Deque
         * 
         * @return int is the value at the front and -1 if invalid
         */
        int getFront() {
            if (isEmpty()) {
                std::cout << "Dequeu is empty\n";
                return -1;
            }
            return data[front];
        }
        /**
         * @brief Get the Rear of the Deque
         * 
         * @return int is the value at the rear and -1 if invalid
         */
        int getRear() {
            if (isEmpty()) {
                std::cout << "Dequeu is empty\n";
                return -1;
            }
            return data[rear];
        }
};

int main() {
  Deque dq(4);
  dq.rearInsertion(5);
  dq.rearInsertion(11);
  std::cout << "rear element: " << dq.getRear() << "\n";
  dq.frontInsertion(8);
  std::cout << "front element: " << dq.getFront() << "\n";
  dq.frontDeletion();
  std::cout << "front element: " << dq.getFront() << "\n";
}
