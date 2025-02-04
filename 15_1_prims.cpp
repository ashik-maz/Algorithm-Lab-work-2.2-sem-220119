#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<pair<int,int>>graph[N];
bool vis[N];
int prims(int start){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,start});
    int mstCost=0;
    while(!pq.empty()){
        auto [weight,vertex]=pq.top();
        pq.pop();
        if(vis[vertex]) continue;
        vis[vertex]=true;
        mstCost+=weight;

        for(auto[w,neighbor]:graph[vertex]){
            if(!vis[neighbor]){
                pq.push({w,neighbor});
            }
        }
    }
    return mstCost;
}
int main(){
    cout<<"Enter the number of nodes and edge\n";
    int n,m;cin>>n>>m;
    cout<<"Enter edge(source destination weight):\n";
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        graph[u].push_back({w,v});
        graph[v].push_back({w,u});
    }
    int start;
    cout<<"enter the satrting node: ";
    cin>>start;
    fill(vis,vis+N,0);
    int minCost=prims(start);
    cout<<"Minimum Cost of MST: "<<minCost<<endl;
    return 0;

}