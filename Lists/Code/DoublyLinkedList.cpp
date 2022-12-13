#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
  private:
    Node* head;
  public:
    DoublyLinkedList(){
      head = NULL;
    }

    /**
     * Time Complexity O(1)
     * Space Complexity O(1)
    */
    void pushFront(int newData) {
        Node* newNode = new Node();
        newNode->data = newData;
        newNode->prev = NULL;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    /**
     * Time Complexity O(1)
     * Space Complexity O(1)
    */
    void popFront() {
        if (head != NULL) {
            Node* temp = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            free(temp);
        }
    }

    /**
     * Time Complexity O(n)
     * Space Complexity O(1)
    */
    void pushAt(int n, int newData) {
        Node* newNode = new Node();
        newNode->data = newData;
        newNode->prev = NULL;
        newNode->next = NULL;
        if (n < 1) return;
        if (n == 1) {
            pushFront(newData);
        } else {
            Node *temp = head;
            for (int i = 1; i < n - 1; i++) {
                if (temp != NULL) {
                    temp = temp->next;
                }
            }
            if (temp != NULL) {
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next = newNode;
                if (newNode->next != NULL) {
                    newNode->next->prev = newNode;
                }
            }
        }
    }

    /**
     * Time Complexity O(n)
     * Space Complexity O(1)
    */
    void popAt(int n) {
        if (n < 1) return;
        if (n == 1 && head != NULL) {
            popEnd();
        } else {
            Node* temp = head;
            for (int i = 1; i < n - 1; i++) {
                if (temp != NULL) {
                    temp = temp->next;
                }
            }
            if (temp != NULL && temp->next != NULL) {
                Node* deleteNode = temp->next;
                temp->next = temp->next->next;
                if (temp->next->next != NULL) {
                    temp->next->next->prev = temp->next;
                }
                free(deleteNode);
            }
        }
    }
 
    /**
     * Time Complexity O(n)
     * Space Complexity O(1)
    */
    void pushBack(int newData) {
      Node* newNode = new Node();
      newNode->data = newData;
      newNode->prev = NULL;
      newNode->next = NULL; 
      if(head == NULL) {
        head = newNode;
      } else {
        Node* temp = head;
        while(temp->next != NULL)
          temp = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
      }    
    }

    /**
     * Time Complexity O(n)
     * Space Complexity O(1)
    */
    void popEnd() {
        if (head != NULL) {
            if (head->next == NULL) {
                head = NULL;
            } else {
                Node* temp = head;
                while (temp->next->next != NULL) {
                    temp = temp->next;
                }
                Node* lastNode = temp->next;
                temp->next = NULL;
                free(lastNode);
            }
        }
    }

    void deleteAllNode() {
        Node* temp = new Node();
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
    }

    void PrintLinkedList() {
      Node* temp = head;
      if(temp != NULL) {
        while(temp != NULL) {
          cout<<temp->data<<" ";
          temp = temp->next;
        }
        cout<<endl;
      }
    }    
};

// test the code  
int main() {
  DoublyLinkedList testList;

  //Add three elements at the end of the list.
  testList.pushBack(10);
  testList.pushBack(20);
  testList.pushBack(30);
  testList.pushFront(0);
  testList.pushFront(-10);
  testList.pushAt(2,4);
  testList.PrintLinkedList();
  testList.popFront();
  testList.PrintLinkedList();
  testList.popAt(2);
  testList.PrintLinkedList();
  return 0; 
}