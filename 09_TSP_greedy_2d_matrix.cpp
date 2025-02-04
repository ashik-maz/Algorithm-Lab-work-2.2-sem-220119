#include <bits/stdc++.h>
using namespace std;

void minRoute(vector<vector<int>> tsp) {
    int n = tsp.size(), sum = 0, counter = 0, i = 0, j = 0, minDist;
    vector<bool> vis(n, false);
    vector<int> route(n, -1);
    vis[0] = true;
    route[0] = 0;

    for (counter = 1; counter < n; counter++) {
        minDist = INT_MAX;
        int nextCity = -1;
        for (j = 0; j < n; j++) {
            if (i != j && !vis[j] && tsp[i][j] != -1 && tsp[i][j] < minDist) {
                minDist = tsp[i][j];
                nextCity = j;
            }
        }
        if (nextCity == -1) return;
        vis[nextCity] = true;
        route[counter] = nextCity;
        sum += minDist;
        i = nextCity;
    }
    sum += tsp[i][0];
    cout << "Minimum Cost is: " << sum << endl;
    cout << "Route: ";
    for (int k = 0; k < n; k++) cout << route[k] + 1 << " -> ";
    cout << "1" << endl;
}

int main() {
    vector<vector<int>> tsp = {
        {-1, 10, 15, 20}, 
        {10, -1, 35, 25}, 
        {15, 35, -1, 30}, 
        {20, 25, 30, -1}
    };
    minRoute(tsp);
}
