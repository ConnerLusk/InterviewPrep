/**
 * @file CircularQueue.cpp
 * @author Conner Lusk
 * @brief Intro/Brief implementation of a Circular Queue
 * @version 0.1
 * @date 2022-07-31
 * @copyright Copyright (c) 2022
 */

/**
 * @note Circular Queue Data Structure
 * A Circular Queue is the extended version of a regular Queue, where the last element is connected to the first element
 * - The Circular Queue solves the major limitation of the normal Queue, where after a bit of insertion and deletion,
 *    there will be non-usable empty space
 * Working of a Circular Queue
 * - A Circular Queue works by the process of circular increment
 *   - When you increment the pointer and reach the end of the Queue, start at the beginning of the Queue
 * Working of a Circular Queue
 * - There are two pointers Front and Rear
 *   - Front tracks the first element of the Queue
 *   - Rear tracks the last element of the Queue
 *   - Initially set the pointers of Front and Rear to -1
 * - Enqueue operation
 *   - Check if the Queue is full
 *   - For the first element, set the value of Front to 0
 *   - Circularly increase the Rear index by 1
 *     - If the Rear reaches the end, then it would become the start of the Queue
 *   - Add the new element in the position pointed to by Rear
 * - Dequeue operation
 *   - Check if the Queue is empty
 *   - Return the value pointed by Front
 *   - Circularly increase the Front index by 1
 *   - If it is the last element, reset the values of Front and Rear to -1
 * Special Cases
 * - Front == 0 && Rear == SIZE - 1
 * - Front == Rear + 1
 *   - Happens when Rear starts from 0 due to circular increment and when its value is just 1 less than front, the queue is full
 * Complexity
 * - The complexity of enqueue and dequeue operations are O(1)
 * Applications
 * - CPU Scheduling
 * - Memory Management
 * - Traffic Management
 */
#include <iostream>
#define SIZE 5

class CircularQueue {
    private:
        int data[SIZE], front, rear;
    public:
        CircularQueue() {
            front = -1;
            rear = -1;
        }
        /**
         * @brief Checks to see if the Queue is full
         */
        bool isFull() {
            return front == 0 && rear == SIZE - 1 || front == rear + 1;
        }
        /**
         * @brief Checks to see if the Queue is empty
         */
        bool isEmpty() {
            return front == -1;
        }
        /**
         * @brief This adds an element to the Queue
         * 
         * @param element is the element that being added
         */
        void enqueue(int element) {
            if (isFull()) {
                std::cout << "Queue is currently full.\n";
                return;
            }
            if (front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            data[rear] = element;
        }
        /**
         * @brief This removes the first element and returns it
         * 
         * @return int is the first element and return -1 on failure
         */
        int dequeue() {
            int element;
            if (isEmpty()) {
                std::cout << "Queue is currently empty.\n";
                return -1;
            }
            element = data[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            }
            else {
                front = (front + 1) % SIZE;
            }
            return element;
        }
        void printQueue() {
            if (isEmpty()) {
                std::cout << "Queue is empty.\n";
                return;
            }
            std::cout <<"Queue:\n";
            int i;
            for (i = front; i != rear; i = (i + 1) % SIZE) {
                std::cout << data[i] << " ";
            }
            std::cout << data[i] << "\n";
        }
};

int main() {
  CircularQueue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.printQueue();
  int elem = q.dequeue();
  q.printQueue();
  q.enqueue(7);
  q.printQueue();
  return 0;
}