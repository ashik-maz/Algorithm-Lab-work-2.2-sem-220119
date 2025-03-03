//travelling salesman problem using dynamic programming
#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> dist;
vector<vector<int>> dp;

int tsp(int mask, int pos){
    if(mask==(1<<n)-1)
        return dist[pos][0];
    if(dp[mask][pos] != -1) 
        return dp[mask][pos];
    
    int ans=INT_MAX;
    for(int city=0;city<n;city++){
        if(!(mask & (1<< city))){
            ans=min(ans, dist[pos][city]+tsp(mask | (1<<city), city));
        }
    }
    return dp[mask][pos]=ans;
}

int main(){
    cout<<"Enter the number of cities: ";
    cin>>n;
    dist.assign(n,vector<int>(n));

    cout<<"Enter the distance matrix(Enter distance between cities): \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dist[i][j];
        }
    }
    dp.assign(1<<n, vector<int>(n,-1));
    cout<<"Minimum Distance Travelled: "<<tsp(1,0)<<endl;
    return 0;
}
