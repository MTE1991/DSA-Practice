#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int V; // number of vertices
    vector<vector<int>> adj; // adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;

        // push the starting vertex to the stack
        s.push(start);

        while (!s.empty()) {
            // pop a vertex from the stack and print it
            int v = s.top();
            s.pop();

            // if the vertex is not visited yet, mark it as visited
            if (!visited[v]) {
                cout << v << " ";
                visited[v] = true;

                // push all the adjacent vertices of v to the stack
                for (int i = adj[v].size() - 1; i >= 0; i--) {
                    int u = adj[v][i];
                    if (!visited[u]) {
                        s.push(u);
                    }
                }
            }
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "DFS traversal starting from vertex 0: ";
    g.DFS(0);
    cout << endl;

    return 0;
}
