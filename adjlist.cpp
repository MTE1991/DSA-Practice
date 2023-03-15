// The following code was generated with the help of chatGPT

#include <bits/stdc++.h> 
using namespace std; 

class Graph 
{ 
    int V; // number of vertices 
    list<pair<int, int> > *adj; // adjacency list 

public: 
    Graph(int V) // constructor 
    { 
        this->V = V; 
        adj = new list<pair<int, int> >[V]; 
    } 

    void addEdge(int u, int v, int weight) // function to add an edge to the graph 
    { 
        adj[u].push_back(make_pair(v, weight)); 
        adj[v].push_back(make_pair(u, weight)); // undirected graph 
    } 

    void printGraph() // function to print the graph 
    { 
        for (int i = 0; i < V; ++i) 
        { 
            cout << "Vertex " << i << ":"; 
            list<pair<int, int> >::iterator it; 
            for (it = adj[i].begin(); it != adj[i].end(); ++it) 
                cout << " -> " << (*it).first << " (weight: " << (*it).second << ")"; 
            cout << endl; 
        } 
    } 
}; 

int main() 
{ 
    Graph g(4); // create graph with 4 vertices 

    g.addEdge(0, 1, 10); 
    g.addEdge(0, 2, 6); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 3, 15); 
    g.addEdge(2, 3, 9); 

    g.printGraph(); 

    return 0; 
} 
