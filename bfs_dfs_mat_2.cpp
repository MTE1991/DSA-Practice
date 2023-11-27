#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjacencyMatrix;

public:
    Graph(int v) : vertices(v), adjacencyMatrix(v, vector<int>(v, 0)) {}

    void addEdge(int from, int to) {
        adjacencyMatrix[from][to] = 1;
        adjacencyMatrix[to][from] = 1; // Assuming an undirected graph
    }

    void printMatrix() {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int startVertex) {
        vector<bool> visited(vertices, false);

        cout << "DFS starting from vertex " << startVertex << ": ";
        DFSRecursive(startVertex, visited);

        cout << endl;
    }

    void printReachableNodes(int startVertex) {
        vector<bool> visited(vertices, false);
        cout << "Nodes reachable from vertex " << startVertex << ": ";
        DFSRecursivePrintReachable(startVertex, visited);
        cout << endl;
    }

    bool isConnected() {
        vector<bool> visited(vertices, false);
        DFSRecursive(0, visited);

        for (bool visit : visited) {
            if (!visit) {
                return false;
            }
        }

        return true;
    }

    void DFSRecursive(int currentVertex, vector<bool>& visited) {
        cout << currentVertex << " ";
        visited[currentVertex] = true;

        for (int i = 0; i < vertices; ++i) {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                DFSRecursive(i, visited);
            }
        }
    }

    void DFSRecursivePrintReachable(int currentVertex, vector<bool>& visited) {
        cout << currentVertex << " ";
        visited[currentVertex] = true;

        for (int i = 0; i < vertices; ++i) {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                DFSRecursivePrintReachable(i, visited);
            }
        }
    }
};

int main() {
    // Example usage
    Graph graph(6);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    cout << "Adjacency Matrix:" << endl;
    graph.printMatrix();
    cout << endl;

    graph.printReachableNodes(0);

    if (graph.isConnected()) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph
