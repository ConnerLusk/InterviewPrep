/**
 * @file DepthFirstSearch.cpp
 * @author Conner Lusk
 * @brief Intro/Brief implementation of Depth First Search
 * @version 0.1
 * @date 2022-08-04
 * @copyright Copyright (c) 2022
 * @note Depth First Search
 * Depth first Search or Depth first traversal is a recursive algorithm for searching all 
 *  the vertices of a graph or tree data structure
 * Process
 *  - A standard DFS implementation puts each vertex of the graph into one of two categories:
 *    1. Visited
 *    2. Not visited
 *  - The DFS algorithm works as follows:
 *    1. Start by putting any one of the graph's vertices on top of a stack
 *    2. Take the top item of the stack and add it to the visited list
 *    3. Create a list of that vertex's adjacent nodes
 *       a. Add the ones which aren't in the visited list to the top of the stack
 *    4. Keep repeating steps 2 and 3 until the stack is empty
 * Complexity
 *  - O(V + E), where V is the number of nodes and E is the number of edges
 *  - The space complexity of the algorithm is O(V)
 * Application of DFS Algorithm
 *  - For finding the path
 *  - To test if the graph is bipartite
 *  - For finding the strongly connected components of a graph
 *  - For detecting cycles in a graph
 */
#include <iostream>
#include <list>

class Graph {
    private:
        int numberVertices;
        std::list<int> *adjacencyLists;
        bool *visited;
    public:
        /**
         * @brief Construct a new Graph object
         * 
         * @param vertices number of verticies
         */
        Graph(int vertices) {
            numberVertices = vertices;
            adjacencyLists = new std::list<int>[vertices];
            visited = new bool[vertices];
        }

        /**
         * @brief This adds an edge
         * 
         * @param src is the starting node
         * @param dest is the ending node
         */
        void addEdge(int src, int dest) {
            adjacencyLists[src].push_front(dest);
        }
        
        void DFS(int startVertex) {
            visited[startVertex] = true;
            std::list<int> adjacencyList = adjacencyLists[startVertex];
            std::cout << startVertex << " ";
            std::list<int>::iterator it;
            for (it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
                if (!visited[*it]) {
                    DFS(*it);
                }
            }
        }
};

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.DFS(0);
  return 0;
}