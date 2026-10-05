//Prism Algorithm 
#include <iostream>
#include <climits>
using namespace std;
#define V 5

void prim(int graph[V][V]) {

    int parent[V];
    int key[V];
    bool mstSet[V];

    // Initialize
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {

        int min = INT_MAX;
        int u;

        // Find minimum key vertex
        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        mstSet[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] &&
                graph[u][v] < key[v]) {

                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Edges of Minimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    int total = 0;

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << endl;

        total += graph[i][parent[i]];
    }

    cout << "Total Minimum Cost = " << total << endl;
}

int main() {

    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prim(graph);

    return 0;
}