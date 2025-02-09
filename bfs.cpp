#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<int> graph[N];
bool vis[N];
void bfs(int vertex) {
fill(vis, vis + N, 0);
vis[vertex] = 1;
cout << "BFS traversal starting from node " << vertex << ": ";
queue<int> q;
q.push(vertex);
while (!q.empty()) {
int current = q.front();
q.pop();
cout << current << " ";
for (int x : graph[current]) {
if (!vis[x]) {
q.push(x);
vis[x] = 1;
}
}
}
cout << endl;
}
int main() {
int edgenumber;
cout << "Enter the number of edges: ";
cin >> edgenumber;
for (int i = 0; i < edgenumber; ++i) {
cout << "Enter source and destination vertex: ";
int v1, v2;
cin >> v1 >> v2;graph[v1].push_back(v2);
graph[v2].push_back(v1);
}
int vertex;
cout << "Enter the starting vertex for BFS: ";
cin >> vertex;
bfs(vertex);
return 0;
}