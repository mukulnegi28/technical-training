#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

struct Edge {
    int from, to, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int kruskals(int g_nodes, vector<int>& g_from, vector<int>& g_to, vector<int>& g_weight) {
    int totalWeight = 0;
    vector<Edge> edges(g_from.size());
    for (int i = 0; i < g_from.size(); ++i) {
        edges[i].from = g_from[i];
        edges[i].to = g_to[i];
        edges[i].weight = g_weight[i];
    }
    sort(edges.begin(), edges.end(), compareEdges);

    DisjointSet ds(g_nodes);
    for (const Edge& edge : edges) {
        int fromRoot = ds.find(edge.from - 1);
        int toRoot = ds.find(edge.to - 1);
        if (fromRoot != toRoot) {
            ds.unionSets(fromRoot, toRoot);
            totalWeight += edge.weight;
        }
    }
    return totalWeight;
}

int main() {
    int g_nodes, g_edges;
    cin >> g_nodes >> g_edges;

    vector<int> g_from(g_edges), g_to(g_edges), g_weight(g_edges);
    for (int i = 0; i < g_edges; ++i) {
        cin >> g_from[i] >> g_to[i] >> g_weight[i];
    }

    int result = kruskals(g_nodes, g_from, g_to, g_weight);
    cout << result << endl;

    return 0;
}