#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;

void dijkstra(int V, vector<vector<pair<int,int>>>&graph, int src){
    vector<int>dist(V,INF);
    dist[src]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,src});
    while(!pq.empty()){
        int dis=pq.top().first;
        int v=pq.top().second;
        pq.pop();
        for(auto edge:graph[v]){
            int adjnode=edge.first;
            int weight=edge.second;

            if(dist[v]+weight < dist[adjnode]){
                dist[adjnode]=dist[v]+weight;
                pq.push({dist[adjnode],adjnode});
            }
        }
    }
    for(int i=0;i<V;i++){
        if(dist[i]==INF) cout<<"INF ";
        cout<<dist[i]<<" ";
    }
}

int main(){
    cout<<"Enter number of vertices and edge: ";
    int V,E;cin>>V>>E;
    vector<vector<pair<int,int>>>graph(V);
    cout<<"Enter the source, destination and weight: ";
    for(int i=0;i<E;i++){
        int u,v,w;cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    cout<<"Enter the starting vertex: ";
    int src;cin>>src;
    dijkstra(V,graph,src);
}
