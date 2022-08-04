/**
 * @file BellmanFord.cpp
 * @author Conner Lusk
 * @brief Intro/Brief implementation of Bellman Ford
 * @version 0.1
 * @date 2022-08-04
 * @copyright Copyright (c) 2022
 * @note Bellman Ford Algorithm
 * Bellman Ford algorithm helps us find the shortest path from a vertex to all other vertices of a weighted graph
 * Process
 *  1. Overestimating the length of the path from the starting vertex to all other vertices
 *  2. Relaxes those estimates by finding new paths that are shorter than the previously overestimated paths
 */
#include <iostream>

/**
 * @brief Struct for the edges of a graph
 */
struct Edge {
  int u; 
  int v;  
  int w; 
};

/**
 * @brief Struct of a graph with number of verticies and edges, and edges
 * 
 */
struct Graph {
  int V;        
  int E;       
  struct Edge* edge;
};

/**
 * @brief Create a Graph object
 * 
 * @param V total number of vertices
 * @param E total number of edges
 * @return struct Graph* 
 */
struct Graph* createGraph(int V, int E) {
  struct Graph* graph = new Graph;
  graph->V = V;
  graph->E = E;
  graph->edge = new Edge[E];
  return graph;
}

/**
 * @brief Prints a graph
 * 
 * @param arr an array
 * @param size size 
 */
void print(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    std::cout << arr[i];
  }
  std::cout << "\n";
}

void BellmanFord(struct Graph* graph, int u) {
  int V = graph->V;
  int E = graph->E;
  int dist[V];

  // Step 1: fill the distance array and predecessor array
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX;

  // Mark the source vertex
  dist[u] = 0;

  // Step 2: relax edges |V| - 1 times
  for (int i = 1; i <= V - 1; i++) {
    for (int j = 0; j < E; j++) {
      // Get the edge data
      int u = graph->edge[j].u;
      int v = graph->edge[j].v;
      int w = graph->edge[j].w;
      if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        dist[v] = dist[u] + w;
    }
  }

  // Step 3: detect negative cycle
  // if value changes then we have a negative cycle in the graph
  // and we cannot find the shortest distances
  for (int i = 0; i < E; i++) {
    int u = graph->edge[i].u;
    int v = graph->edge[i].v;
    int w = graph->edge[i].w;
    if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
      std::cout << "Graph contains negative w cycle\n";
      return;
    }
  }

  // No negative weight cycle found!
  // Print the distance and predecessor array
  print(dist, V);
  return;
}

int main() {
  // Create a graph
  int V = 5;
  int E = 8;
  struct Graph* graph = createGraph(V, E);
  //edge 0 --> 1
  graph->edge[0].u = 0;
  graph->edge[0].v = 1;
  graph->edge[0].w = 5;
  //edge 0 --> 2
  graph->edge[1].u = 0;
  graph->edge[1].v = 2;
  graph->edge[1].w = 4;
  //edge 1 --> 3
  graph->edge[2].u = 1;
  graph->edge[2].v = 3;
  graph->edge[2].w = 3;
  //edge 2 --> 1
  graph->edge[3].u = 2;
  graph->edge[3].v = 1;
  graph->edge[3].w = 6;
  //edge 3 --> 2
  graph->edge[4].u = 3;
  graph->edge[4].v = 2;
  graph->edge[4].w = 2;
  BellmanFord(graph, 0); 
  return 0;
}