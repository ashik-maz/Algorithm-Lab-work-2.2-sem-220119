#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) {
    parent[findParent(parent, x)] = findParent(parent, y);
}

void kruskalMST(vector<Edge> &edges, int V) {
    vector<Edge> mst;
    int parent[V];
    fill(parent, parent + V, -1);

    sort(edges.begin(), edges.end(), compare); // Sort edges by weight

    for (auto &edge : edges) {
        int x = findParent(parent, edge.src);
        int y = findParent(parent, edge.dest);

        if (x != y) {
            mst.push_back(edge);
            unionSets(parent, x, y);
        }
    }

    // Print MST
    for (auto &edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
}

int main() {
    int V = 5, E = 7;
    vector<Edge> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3},
        {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };

    kruskalMST(edges, V);
    return 0;
}
