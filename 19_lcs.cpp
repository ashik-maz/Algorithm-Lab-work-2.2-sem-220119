#include <bits/stdc++.h>
using namespace std;

string lcs(string &s1, string &s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (s1[i-1] == s2[j-1]) ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);
    
    string res = "";
    for (int i = m, j = n; i > 0 && j > 0;)
        (s1[i-1] == s2[j-1]) ? (res = s1[--i] + res, --j) : (dp[i-1][j] > dp[i][j-1] ? --i : --j);
    
    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string result = lcs(s1, s2);
    cout << result.size() << "\n" << result;
}
