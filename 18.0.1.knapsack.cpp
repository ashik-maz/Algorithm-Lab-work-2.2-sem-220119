#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<pair<int,int>>&items, int n, int w){
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));

    //int dp[n+1][w+1];
    //memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++){
        int weight=items[i-1].first;
        int value=items[i-1].second;

        for(int j=0;j<=w;j++){
            if(weight>j){
                dp[i][j]=dp[i-1][j];//cannot take
            }
            else{
                dp[i][j]=max(dp[i-1][j],value+dp[i-1][j-weight]);//take the maximum
            }
        }
    }
    return dp[n][w];
}

int main() {
    cout<<"Enter Number of Items: ";
    int n;cin>>n;
    
    vector<pair<int,int>>items(n);
    cout<<"Enter every item weight and value: ";
    for (int i = 0; i < n; i++) {
        cin>>items[i].first>>items[i].second;
    }
    
    cout<< "Enter Weight: ";
    int w;cin>>w;
    
    cout<<"Maximum Value = "<<knapsack(items, n, w)<<'\n';
}
