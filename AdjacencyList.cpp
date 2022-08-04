/**
 * @file AdjacencyList.cpp
 * @author Conner Lusk
 * @brief Intro/Brief implementation of a Adjacency Lists
 * @version 0.1
 * @date 2022-08-04
 * @copyright Copyright (c) 2022
 * @note Adjacency Lists
 * An adjacency list represents a graph as an array of linked lists
 *  - The index of the array represents a vertex and each element in its linked list represents
 *     the other vertices that form an edge with the vertex
 * Pros of Adjacency List
 *  - An adjacency list is efficient in terms of storage because we only need to store the values for the edges
 *     - For a sparse graph with millions of vertices and edges, this can mean a lot of saved space
 *  - It also helps to find all the vertices adjacent to a vertex easily
 * Cons of Adjacency List
 *  - Finding the adjacent list is not quicker than the adjacency matrix because all the connected nodes 
 *     must be first explored to find them
 */
#include <iostream>
#include <list>

class Graph {
  int numVertices;
  list<int> *adjLists;
  bool *visited;

  public:
  /**
   * @brief Construct a new Graph object
   * 
   * @param V is how many vertices
   */
     Graph(int V) {
        numVertices = vertices;
        adjLists = new list<int>[vertices];
        visited = new bool[vertices];
     }

    /**
     * @brief Construct a new add Edge object
     * 
     * @param src is the start of the edge
     * @param dest is the end of the edge
     */
    void addEdge(int src, int dest) {
        adjLists[src].push_front(dest);
    }
}