/**
 * @file Queue.cpp
 * @author Conner Lusk
 * @brief Intro/Brief implementation of a Queue
 * @version 0.1
 * @date 2022-07-31
 * @copyright Copyright (c) 2022
 * @note Queue Data Structure
 * A Queue is a useful data structure in which the first item that enters the Queue is the first to exit the Queue
 * - Follows the FIFO principal
 * Basic Operations
 * - Enqueue
 *   - Adds an element to the end of the Queue
 * - Dequeue
 *   - Removes an element from the start of the Queue
 * - IsEmpty
 *   - Checks to see if the Queue is empty
 * - IsFull
 *   - Checks to see if the Queue is full
 * - Peek
 *   - Gets the value of the front of the Queue without removing it
 * Working of a Queue
 * - There are two pointers front and rear
 *   - Front tracks the first element of the Queue
 *   - Rear tracks the last element of the Queue
 *   - Initially set the pointers of Front and Rear to -1
 * - Enqueue operation
 *   - Check if the Queue is full
 *   - For the first element, set the value of Front to 0
 *   - Increase the rear index by 1
 *   - Add the new element in the position pointed to by Rear
 * - Dequeue operation
 *   - Check if the Queue is empty
 *   - Return the value pointed by Front
 *   - Increase the Front index by 1
 *   - If it is the last element, reset the values of Front and Rear to -1
 * Complexity Analysis
 * - The complexity of enqueue and dequeue when using an array is O(1)
 * Applications
 * - CPU/Disk schduling
 * - I/O buffers, pipes, files
 */

#include <iostream>
#define SIZE 5

class Queue {
    private: 
        int data[SIZE], front, rear;
    public:
        // Initializes a queue with the front and rear pointers to -1.
        Queue() {
            front = -1;
            rear = -1;
        }
        // Checks to see if the queue is full.
        bool isFull() {
            return front == 0 && rear == SIZE - 1;
        }
        // Checks to see if the queue is empty.
        bool isEmpty() {
            return front == -1;
        }
        /**
         * @brief This adds an element to the queue if the queue is not yet full.
         * 
         * @param element is the element that is added.
         * @return returns the position the element is added to or -1 if failed
         */
        int enqueue(int element) {
            if (isFull()) {
                std::cout << "Queue is full\n";
                return (-1);
            }
            if (isEmpty()) front = 0;
            rear++;
            data[rear] = element;
            return rear;
        }
        /**
         * @brief This removes and returns the first element
         * 
         * @return int is the element removes or -1 if queue is empty
         */
        int dequeue() {
            int element;
            if (isEmpty()) {
                std::cout << "Queue is empty.\n";
                return (-1);
            }
            element = data[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            }
            else {
                front ++;
            }
            return element;
        }
        int peek() {
            if (isEmpty()) {
                std::cout << "Queue is empty.\n";
                return (-1);
            }
            return data[front];
        }
        void printQueue() {
            if (isEmpty()) {
                std::cout << "Queue is empty\n";
                return;
            }
            std::cout <<" Queue:\n";
            for (int i = front; i <= rear; i++) {
                std::cout << data[i] << " ";
            }
            std::cout << "\n";
        }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.printQueue();
    q.dequeue();
    q.printQueue();
    q.dequeue();
}