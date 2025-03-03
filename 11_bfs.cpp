//BFS traversal of a graph
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<int>graph[N];
bool vis[N];
void BFS(int vertex){
    fill(vis,vis+N,false);
    vis[vertex]=true;
    cout<<"BFS traversalal starting from node "<<vertex<<":";
    queue<int>q;
    q.push(vertex);
    while(!q.empty()){
        int current=q.front();
        q.pop();
        cout<<current<<" ";
        for(auto x:graph[current]){
            if(!vis[x]){
                q.push(x);
                vis[x]=true;
            }
        }
    }
    cout<<'\n';
}
int main(){
    cout<<"Enter the number of edge: ";
    int edgenumber;cin>>edgenumber;
    for(int i=0;i<edgenumber;i++){
        cout<<"Enter source and destination : ";
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int vertex;
    cout<<"Enter the staring vertex for BFS: ";
    cin>>vertex;
    BFS(vertex);
    return 0;
}