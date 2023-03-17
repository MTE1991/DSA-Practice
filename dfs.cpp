#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Recursive DFS function
void DFS(vector<vector<int>>& graph, vector<bool>& visited, int node) {
    // Mark the current node as visited
    visited[node] = true;

    // Traverse all adjacent nodes
    for (int i = 0; i < graph[node].size(); i++) {
        int nextNode = graph[node][i];
        if (!visited[nextNode]) {
            DFS(graph, visited, nextNode);
        }
    }
}

void DFS(vector<vector<int>>& graph, int startNode) {
    vector<bool> visited(graph.size(), false);
    vector<int> parent(graph.size(), -1);
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

            for (int i = 0; i < graph[node].size(); i++) {
                if (graph[node][i] && !visited[i]) {
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

int main() {
    // Create a sample graph
    vector<vector<int>> graph = {{1, 2}, {0, 2}, {0, 1, 3}, {2}};

    // Traverse the graph using DFS starting from node 0
    DFS(graph, 0);

    return 0;
}
