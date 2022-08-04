/**
 * @file AdjacencyMatrix.cpp
 * @author Conner Lusk
 * @brief Intro/Brief implementation of a Adjacency Matrix
 * @version 0.1
 * @date 2022-08-04
 * @copyright Copyright (c) 2022
 * @note Adjacency Matrix
 * An adjacency matrix is a way of representing a graph as a matrix of booleans (0's and 1's)
 * A finite graph can be represented in the form of a square matrix on a computer, where the 
 *  boolean value of the matrix indicates if there is a direct path between two vertices
 *  - Each cell in the above table/matrix is represented as Aij, where i and j are vertices
 *  - If there is a path from i to j, then the value of Aij is 1 otherwise its 0
 * Pros of Adjacency Matrix
 *  - The basic operations like adding an edge, removing an edge, and checking whether there 
 *     is an edge from vertex i to vertex j are extremely time efficient, constant time operations
 *  - If the graph is dense and the number of edges is large, an adjacency matrix should be the first choice
 *    - By performing operations on the adjacent matrix, we can get important insights into the nature
 *       of the graph and the relationship between its vertices
 * Cons of Adjacency Matrix
 *  - The VxV space requirement of the adjacency matrix makes it a memory hog
 *  - Basic operations are easy, operations like inEdges and outEdges are expensive
 *     when using the adjacency matrix representation
 */
#include <iostream>

class Graph {
    private: 
        bool** adjacenyMatrix;
        int numVertices;
    public:
        Graph(int numVertices) {
            this->numVertices = numVertices;
            adjacenyMatrix = new bool*[numVertices];
            for (int i = 0; i < numVertices; i++) {
                adjacenyMatrix[i] = new bool[numVertices];
                for (int j = 0; j < numVertices; j++)
                    adjacenyMatrix[i][j] = false;
            }
        }

        /**
         * @brief Adds a edge to a graph
         * 
         * @param i node
         * @param j node
         */
        void addEdge(int i, int j) {
            adjacenyMatrix[i][j] = true;
            adjacenyMatrix[j][i] = true;
        }

        /**
         * @brief Removes a edge from a graph
         * 
         * @param i node
         * @param j node
         */
        void removeEdge(int i, int j) {
            adjacenyMatrix[i][j] = false;
            adjacenyMatrix[j][i] = false;
        }

        /**
         * @brief Prints an adjacency matrix
         */
        void print() {
            for (int i = 0; i < numVertices; i++) {
                for (int j = 0; j < numVertices; j++)
                    std::cout << adjacenyMatrix[i][j] << " ";
                std::cout << "\n";
            }
        }

        /**
         * @brief Destroy the Graph object
         */
        ~Graph() {
            for (int i = 0; i < numVertices; i++)
            delete[] adjacenyMatrix[i];
            delete[] adjacenyMatrix;
        }
};

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.print();
}