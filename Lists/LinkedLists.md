## Linked Lists
A linked lists is a data structure used for storing collections of data. A linked list has the following properties:
- A linked list is a linear dynamic data structure
- The number of nodes in a list is not fixed and can grow and shrink on demand
- Each node of a linked list is made up of two items:
> 1. The data
> 2. A reference to the next node

- Does not waste memory, although it takes some extra memory for pointers
- Can be as long a required(unitl systems memory exhausts)

### Linked Lists ADT
Main linked list operations:
- Insert: Inserts an elemenmt into the list
- Delete: Removes and returns the specificed positon element from the list

Auxiliary linked lists operations
- Delete List: Removes all elements of the list
- Count: Returns the number of elements in the list
- Find the nth node from the end of the list

### Advantages of linked lists
- Linked lists can be expanded in constant time

### Disadvantages
- The access time for a linked list is relatively slow $O(n)$

### Singly Linked List
A singly linked list consists of a series of structures called nodes. The first part of a node is a field that stores the data, and the second part is a field that stores a pointer to the next node. </br>
[Code](/Lists/Code/SinglyLinkedList.cpp)

### Doubly Linked List
A doubly linked list is a list in which a node contains a pointer to the previous and next node in the sequence. The advantage of a doubly linked list over a singly linked list is that you are able to navigate forwards and backwards. The disadvantage is that each node requires and extra pointer(more space), and insertion and deletion take longer. </br>
[Code](/Lists/Code/DoublyLinkedList.cpp)