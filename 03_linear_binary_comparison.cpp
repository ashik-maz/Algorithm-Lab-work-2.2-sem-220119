#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int linearSearch(vector<int>& arr, int t) {
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == t) return i;
    return -1;
}

int binarySearch(vector<int>& arr, int t) {
    int l = 0, h = arr.size() - 1;
    while (l <= h) {
        int m = (l + h) / 2;
        if (arr[m] == t) return m;
        (arr[m] > t) ? h = m - 1 : l = m + 1;
    }
    return -1;
}

int main() {
    int n, t;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    cin >> t;

    auto s1 = high_resolution_clock::now();
    cout << "Linear: " << linearSearch(arr, t) << '\n';
    auto e1 = high_resolution_clock::now();
    
    sort(arr.begin(), arr.end());
    
    auto s2 = high_resolution_clock::now();
    cout << "Binary: " << binarySearch(arr, t) << '\n';
    auto e2 = high_resolution_clock::now();

    cout << "L Time: " << duration<double, micro>(e1 - s1).count() << " µs\n";
    cout << "B Time: " << duration<double, micro>(e2 - s2).count() << " µs\n";
}
