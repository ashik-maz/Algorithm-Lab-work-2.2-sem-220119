#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;

void dijkstra(int V, vector<vector<pair<int,int>>> &graph,int src){
    vector<int>dist(V,INF);
    vector<bool>vis(V,false);
    dist[src]=0;

/*
    The priority queue have 3 parameters.
    The template for priority_queue is:

    priority_queue<T, Container, Compare>

    T: The data type stored in the queue (pair<int, int> in this case).
    Container: The internal container (vector<pair<int, int>> by default).
    Compare: A comparison function (greater<pair<int, int>> to make it a min heap).
*/

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();

        if(!vis[u]){
            vis[u]=true;
            for(auto neighbor:graph[u]){
                int v=neighbor.first;
                int weight=neighbor.second;
    
                if(dist[u]+weight < dist[v]){
                    dist[v]=dist[u]+weight;
                    pq.push({dist[v],v});
                }
            }
        }
    }

    for(int i=0;i<V;i++){
        if(dist[i]==INF){
            cout<<"INF";
        }
        else{
            cout<<dist[i]<<" ";
        }
    }
    cout<<endl;
}

int main(){
    int V,E;
    cout<<"Enter Number of Vertices and Edge: ";
    cin>>V>>E;

    vector<vector<pair<int,int>>>graph(V);
    cout<<"Enter edges (u,v,weight): \n";
    for(int i=0;i<E;i++){
        int u,v,w; cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    cout<<"Enter Starting vertex: ";
    int src; cin>>src;
    cout<<"Shortest distance from vertex "<<src<<": ";
    dijkstra(V,graph,src);
    
    return 0;
}