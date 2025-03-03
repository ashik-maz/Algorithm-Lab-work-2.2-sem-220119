//hamiltonian cycle is a cycle that visits each vertex exactly once
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<int> graph[N];
bool vis[N];

bool isSafe(int vertex, vector<int>& path, int pos) {
    for (int i = 0; i < pos; i++) {
        if (path[i] == vertex)
            return false;
    }

    if (find(graph[path[pos - 1]].begin(), graph[path[pos - 1]].end(), vertex) == graph[path[pos - 1]].end()) {
        return false;
    }

    return true;
}

bool hamCycleUtil(vector<int>& path, int pos, int V) {
    if (pos == V) {
        if (find(graph[path[pos - 1]].begin(), graph[path[pos - 1]].end(), path[0]) != graph[path[pos - 1]].end()) {
            return true;
        }
        return false;
    }

    for (int v = 1; v <= V; v++) {
        if (isSafe(v, path, pos)) {
            path[pos] = v;

            if (hamCycleUtil(path, pos + 1, V)) {
                return true;
            }

            path[pos] = -1;
        }
    }

    return false;
}

void hamiltonianCycle(int V) {
    vector<int> path(V, -1);
    
    path[0] = 0;

    if (!hamCycleUtil(path, 1, V)) {
        cout << "No Hamiltonian Cycle exists" << endl;
    } else {
        cout << "Hamiltonian Cycle: ";
        for (int i = 0; i < V; i++) {
            cout << path[i] << " ";
        }
        cout << path[0] << endl; // To complete the cycle
    }
}

int main() {
    cout << "Enter the number of vertices: ";
    int V;
    cin >> V;

    cout << "Enter the number of edges: ";
    int edgenumber;
    cin >> edgenumber;

    for (int i = 0; i < edgenumber; i++) {
        cout << "Enter source and destination: ";
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    hamiltonianCycle(V);

    return 0;
}
