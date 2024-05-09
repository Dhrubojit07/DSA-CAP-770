#include <iostream>
#include <vector>

const int numVertices = 5; // Adjust the number of vertices as needed

// Adjacency list representation using a 2D vector
std::vector<std::vector<int>> adjList(numVertices);

int main() {
  // Sample graph (modify connections as needed)
  adjList[0] = {1, 2};  // Node 0 connects to nodes 1 and 2
  adjList[1] = {0, 3};  // Node 1 connects to nodes 0 and 3
  adjList[2] = {0, 4};  // Node 2 connects to nodes 0 and 4
  adjList[3] = {1};     // Node 3 connects to node 1
  adjList[4] = {2};     // Node 4 connects to node 2

  // Print the adjacency list representation
  for (int i = 0; i < numVertices; ++i) {
    std::cout << "Node " << i << " connects to: ";
    for (int neighbor : adjList[i]) {
      std::cout << neighbor << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
