#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
  private:
    Node* head;
  public:
    SinglyLinkedList(){
      head = NULL;
    }

    /**
     * Time Complexity O(1)
     * Space Complexity O(1)
    */
    void pushFront(int newData) {
        Node* newNode = new Node();
        newNode->data = newData;
        if (head == NULL) {
            head = newNode;
        } else {
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
        Node* pred = head;
        if (n <= 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        while (--n && pred != NULL) {
            pred = pred->next;
        }
        if (pred == NULL) {
            return;
        }
        newNode->next = pred->next;
        pred->next = newNode;
    }

    /**
     * Time Complexity O(n)
     * Space Complexity O(1)
    */
    void popAt(int n) {
        if (n < 1) return;
        if (n == 1 && head != NULL) {
            Node* deleteNode = head;
            head = head->next;
            free(deleteNode);
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
      newNode->next = NULL; 
      if(head == NULL) {
        head = newNode;
      } else {
        Node* temp = head;
        while(temp->next != NULL)
          temp = temp->next;
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
                while (temp->next != NULL) {
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
  SinglyLinkedList testList;

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