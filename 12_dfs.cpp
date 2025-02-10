#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<int>graph[N];
bool vis[N];
void DFS(int vertex){
    vis[vertex]=true;
    cout<<vertex<<" ";
    for(int child:graph[vertex]){
        if(!vis[child]){
            DFS(child);
        }
    }
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
    cout<<"Enter the staring vertex for DFS: ";
    cin>>vertex;
    cout<<"DFS: ";
    DFS(vertex);
    cout<<'\n';
    return 0;
}