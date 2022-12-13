#include <iostream>

struct Node {
    int data;
    Node *next;
    Node * prev;
};

class CircularLinkedList {
    private:
        Node* head;
    public: 
        CircularLinkedList() {
            head = NULL;
        }

        void pushFront(int newData) {
            Node *newNode = new Node();
            newNode->data = newData;
            newNode->next = NULL;
            newNode->prev = NULL;

            if (head == NULL) {
                head = newNode;
                head->next = head;
                head->prev = head;
            } else {
                Node *temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->prev = temp;
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        void popFront() {
            if (head != NULL) {
                // If the list only has one element
                if (head->next == head) {
                    head = NULL;
                } else {
                    Node *lastNode = head->prev;
                    Node *firstNode = head;
                    head = head->next;
                    head->prev = lastNode;
                    lastNode->next = head;
                    free(firstNode);
                }
            }
        }

        void pushBack(int newData) {
            Node *newNode = new Node();
            newNode->data = newData;
            newNode->next = NULL;
            newNode->prev = NULL;

            if (head == NULL) {
                head = newNode;
                head->next = head;
                head->prev = head;
            } else {
                Node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->prev = temp;
                newNode->next = head;
                head->prev = newNode;
            }
        }

        void popBack() {
            if (head != NULL) {
                if (head->next == head) {
                    head = NULL;
                } else {
                    Node *temp = head;
                    Node *lastNode = head->prev;
                    lastNode->prev->next = head;
                    head->prev = lastNode->prev;
                    free(lastNode);
                }
            }
        }

        void pushAt(int newData, int n) {
            Node *newNode = new Node();
            Node *temp = head;
            newNode->data = newData;
            newNode->next = NULL;
            newNode->prev = NULL;
            int numElements = 0;

            if (temp != NULL) {
                numElements ++;
                temp = temp->next;
            }

            while (temp != head) {
                numElements ++;
                temp = temp->next;
            }

            if (n >= 1 && n <= numElements + 1) {
                if (n == 1) {
                    pushFront(newData);
                } else {
                    temp = head;
                    for (int i = 1; i < n - 1 ; i++) {
                        temp = temp->next;
                    }
                    newNode->next = temp->next;
                    temp->next->prev = newNode;
                    temp->next = newNode;
                    newNode->prev = temp;
                }
            }
        }

        void popAt(int n) {
            Node *deleteNode = head;
            Node *temp = head;
            int numElements = 0;

            if (temp != NULL) {
                temp = temp->next;
                numElements ++;
            }

            while (temp != head) {
                temp = temp->next;
                numElements ++;
            }

            if (n >= 1 && n <= numElements) {
                if (n == 1) {
                    popFront();
                } else {
                    temp = head;
                    for (int i = 0; i < n - 1; i++) {
                        temp = temp->next;
                    }
                    deleteNode = temp;
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    free(deleteNode);
                }
            }

        }

        void PrintCircularList() {
            Node* temp = head;
            if(temp != NULL) {
                while(true) {
                std::cout<<temp->data<<" ";
                temp = temp->next;
                if(temp == head) 
                    break;
                }
                std::cout<<std::endl;
            }
        }     
};


int main() {
  CircularLinkedList circularListExample;
  circularListExample.pushBack(10);
  circularListExample.pushBack(20);
  circularListExample.pushBack(30);
  circularListExample.pushBack(40);  
  circularListExample.PrintCircularList();
  circularListExample.pushAt(15,2);
  circularListExample.PrintCircularList();
  return 0; 
}
