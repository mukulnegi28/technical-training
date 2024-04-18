#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int calculateCost(vector<vector<int>>& graph, vector<int>& tour) {
    int cost = 0;
    int n = graph.size();

    for (int i = 0; i < n - 1; i++) {
        cost += graph[tour[i]][tour[i + 1]];
    }
    
    cost += graph[tour[n - 1]][tour[0]];

    return cost;
}

int travelingSalesmanNaive(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> tour(n);
    for (int i = 0; i < n; i++) {
        tour[i] = i;
    }

    int minCost = INT_MAX;

    do {
       
        if (tour[0] == start) {
            int currentCost = calculateCost(graph, tour);
            minCost = min(minCost, currentCost);
        }
    } while (next_permutation(tour.begin(), tour.end()));

    return minCost;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int startCity = 0; 
    int minCost = travelingSalesmanNaive(graph, startCity);

    cout << "Minimum cost of the tour: " << minCost << endl;

    return 0;
}
