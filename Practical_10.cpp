#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

int parent[100];

int findParent(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x]);
}

void unionSet(int u, int v) {
    u = findParent(u);
    v = findParent(v);

    if (u != v)
        parent[v] = u;
}

void kruskal(Edge edges[], int V, int E) {

    // Sort edges according to weight
    sort(edges, edges + E, [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    // Initially every vertex is its own parent
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int totalCost = 0;
    int edgeCount = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (int i = 0; i < E && edgeCount < V - 1; i++) {

        int u = edges[i].u;
        int v = edges[i].v;

        // Check whether adding edge creates a cycle
        if (findParent(u) != findParent(v)) {

            cout << u << " - " << v
                 << " : " << edges[i].weight << endl;

            totalCost += edges[i].weight;
            edgeCount++;

            unionSet(u, v);
        }
    }

    cout << "Total Minimum Cost = " << totalCost << endl;
}

int main() {

    int V = 5;
    int E = 7;

    Edge edges[] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 4},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    kruskal(edges, V, E);

    return 0;
}