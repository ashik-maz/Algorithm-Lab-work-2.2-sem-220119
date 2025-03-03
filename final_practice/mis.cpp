#include<bits/stdc++.h>
using namespace std;
const int N=1005;
vector<pair<int,int>> adj_list[N];
vector<int>dis(N,INT_MAX);

void dijkstra(int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({src,0});
    dis[src]=0;
    while(!q.empty())
    {
        pair<int,int> par=q.top();
        q.pop();
        int par_node=par.first;
        int par_dis=par.second;
        for(auto child:adj_list[par_node])
        {
            int child_node=child.first;
            int child_dis=child.second;
            if(par_dis+child_dis < dis[child_node])
            {
                dis[child_node] = par_dis+child_dis;
                q.push({child_node,dis[child_node]});
            }
        }
    }
}

int main()
{
 int n,e;
 cin>>n>>e;
 for(int i=0;i<n;i++)
 {
    int u,v,w;
    cin>>u>>v>>w;
    adj_list[u].push_back({v,w});
    adj_list[v].push_back({u,w});
 }
 int src;
 cin>>src;
 cout<<src<<endl;
 dijkstra(src);
 for(int i=0;i<e;i++)
 {
    cout << "Distance from " << src << " to " << i << " is " << dis[i] << endl;
 }

    return 0;
}
