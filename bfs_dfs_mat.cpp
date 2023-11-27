#include <iostream>
#include <queue>
#include <stack>
#include <vector>

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

    void BFS(int startVertex) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[startVertex] = true;
        cout << "BFS starting from vertex " << startVertex << ": ";

        cout << startVertex << " ";
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();

            for (int i = 0; i < vertices; ++i) {
                if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                    cout << i << " ";
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        cout << endl;
    }

/*
    void DFS(int startVertex) {
        vector<bool> visited(vertices, false);
        stack<int> s;

        visited[startVertex] = true;
        cout << "DFS starting from vertex " << startVertex << ": ";

        cout << startVertex << " ";
        s.push(startVertex);

        while (!s.empty()) {
            int currentVertex = s.top();
            s.pop();

            for (int i = 0; i < vertices; ++i) {
                if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                    cout << i << " ";
                    visited[i] = true;
                    s.push(i);
                }
            }
        }

        cout << endl;
    }
*/

    void DFS(int startVertex) {
        vector<bool> visited(vertices, false);

        cout << "DFS starting from vertex " << startVertex << ": ";
        DFSRecursive(startVertex, visited);

        cout << endl;
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
};

int main() {
    // Example usage
    Graph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    
    cout << "Adjacency Matrix:" << endl;
    graph.printMatrix();
    cout << endl;

    graph.BFS(5);
    graph.DFS(5);

    return 0;
}
