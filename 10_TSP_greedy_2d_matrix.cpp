//travelling salesman problem using greedy approach
#include <bits/stdc++.h>
using namespace std;

void minRoute(vector<vector<int>> cities) {
    int n = cities.size(), sum = 0, counter = 0, i = 0, j = 0, minDist;
    vector<bool> vis(n, false);
    vector<int> route(n, -1);
    vis[0] = true;
    route[0] = 0;

    for (counter = 1; counter < n; counter++) {
        minDist = INT_MAX;
        int nextCity = -1;
        for (j = 0; j < n; j++) {
            if (i != j && !vis[j] && cities[i][j] != -1 && cities[i][j] < minDist) {
                minDist = cities[i][j];
                nextCity = j;
            }
        }
        if (nextCity == -1) return;
        vis[nextCity] = true;
        route[counter] = nextCity;
        sum += minDist;
        i = nextCity;
    }
    sum += cities[i][0];
    cout << "Minimum Cost is: " << sum << endl;
    cout << "Route: ";
    for (int k = 0; k < n; k++) cout << route[k] + 1 << " -> ";
    cout << "1" << endl;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> cities(n, vector<int>(n));

    cout << "Enter the distance matrix (-1 for no direct path):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cities[i][j];
        }
    }

    minRoute(cities);
}
