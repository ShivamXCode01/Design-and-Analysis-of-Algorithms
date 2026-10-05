#include <iostream>
#include <algorithm>
using namespace std;

#define V 4
#define INF 99999

int tsp(int graph[V][V]) {

    int cities[V - 1];
    int index = 0;

    // Store all cities except starting city 0
    for (int i = 1; i < V; i++) {
        cities[index++] = i;
    }

    int minCost = INF;

    // Generate all possible routes
    do {
        int currentCost = 0;
        int currentCity = 0;

        // Visit cities in the current permutation
        for (int i = 0; i < V - 1; i++) {
            currentCost += graph[currentCity][cities[i]];
            currentCity = cities[i];
        }

        // Return to starting city
        currentCost += graph[currentCity][0];

        minCost = min(minCost, currentCost);

    } while (next_permutation(cities, cities + V - 1));

    return minCost;
}

int main() {

    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int result = tsp(graph);

    cout << "Minimum Cost of Travelling Salesman = "
         << result << endl;

    return 0;
}