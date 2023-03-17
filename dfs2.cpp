#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Graph class to represent a graph
class Graph {
private:
    int numVertices; // Number of vertices in the graph
    vector<vector<int>> adjMatrix; // Adjacency matrix to store the graph

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int numVertices) {
        this->numVertices = numVertices;

        // Initialize the adjacency matrix with all zeros
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    // Function to add an edge between two vertices in the graph
    void addEdge(int v1, int v2) {
        // Set the adjacency matrix entry to 1 to indicate an edge between v1 and v2
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;
    }

    // Function to perform a depth-first search of the graph starting at a given vertex
    void DFS(int startNode) {
        vector<bool> visited(numVertices, false);
        vector<int> parent(numVertices, -1);
        stack<int> s;

        // Push the starting node onto the stack
        s.push(startNode);

        while (!s.empty()) {
            // Pop the top node from the stack
            int node = s.top();
            s.pop();

            // If the node has not been visited, mark it as visited and push all its unvisited neighbors onto the stack
            if (!visited[node]) {
                visited[node] = true;

                for (int i = 0; i < numVertices; i++) {
                    if (adjMatrix[node][i] && !visited[i]) {
                        s.push(i);
                        parent[i] = node;
                    }
                }
            }
        }

        // Output the path from the starting node to each visited node
        for (int i = 0; i < visited.size(); i++) {
            if (visited[i]) {
                cout << "Path from " << startNode << " to " << i << ": ";
                stack<int> path;
                int node = i;
                while (node != -1) {
                    path.push(node);
                    node = parent[node];
                }
                while (!path.empty()) {
                    cout << path.top() << " ";
                    path.pop();
                }
                cout << endl;
            }
        }
    }
};

int main() {
    // Create a graph with 6 vertices
    Graph g(6);

    // Add edges between vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    // Perform a depth-first search starting at vertex 0
    g.DFS(0);

    return 0;
}
