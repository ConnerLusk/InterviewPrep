/**
 * @file BreadthFirstSearch.cpp
 * @author Conner Lusk
 * @brief Intro/Brief implementation of Breadth First Search
 * @version 0.1
 * @date 2022-08-04
 * @copyright Copyright (c) 2022
 * @note Breadth First Search
 * Breadth First Traversal or Breadth First Search is a recursive algorithm for searching all the 
 *   vertices of a graph or tree data structure
 * Process
 *  - A standard BFS implementation puts each vertex of the graph into one of two categories:
 *    1. Visited
 *    2. Not Visited
 * - The BFS algorithm works as follows:
 *    1. Start by putting any one of the graph's vertices at the back of a queue
 *    2. Take the front item of the queue and add it to the visited list
 *    3. Create a list of that vertex's adjacent nodes
 *       a. Add the ones which aren't in the visited list to the back of the queue
 *    4. Keep repeating steps 2 and 3 until the queue is empty
 * Complexity
 *  - O(V + E), where V is the number of nodes and E is the number of edges.
 *  - Space complexity of the algorithm is O(V)
 * Applications
 *  - Path finding algorithms
 *  - Ford-Fulkerson algorithm to find maximum flow in a network
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

         void BFS(int startVertex) {
            visited = new bool[numberVertices];
            for (int i = 0; i < numberVertices; i++)
                visited[i] = false;
            std::list<int> queue;
            visited[startVertex] = true;
            queue.push_back(startVertex);
            std::list<int>::iterator it;
            while (!queue.empty()) {
                int currVertex = queue.front();
                std::cout << currVertex << " ";
                queue.pop_front();
                for (it = adjacencyLists[currVertex].begin(); it != adjacencyLists[currVertex].end(); ++it) {
                    int adjVertex = *it;
                    if (!visited[adjVertex]) {
                        visited[adjVertex] = true;
                        queue.push_back(adjVertex);
                    }
                }
            }
         }
};

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  g.BFS(0);
}