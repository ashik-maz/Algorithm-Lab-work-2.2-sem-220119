#include<bits/stdc++.h>
using namespace std;

double knapsack(vector<pair<int,int>> &items,int n,int w){
    sort(items.begin(),items.end(),[](pair<int,int>a,pair<int,int>b){
        return (double)a.second/a.first> (double)b.second/b.first;
    });
    double maxprofit=0.0;
    for(int i=0;i<n;i++){
        int weight=items[i].first;
        int value=items[i].second;
        if(w>=weight){
            maxprofit+=value;
            w-=weight;
        }
        else{
            maxprofit+=((double)value/weight)*w;
            break;
        }
    }
    return maxprofit;
}

int main(){
    cout<<"Enter the Number of items: ";
    int n;cin>>n;
    vector<pair<int,int>>items(n);
    cout<<"Enter every item weight and value: \n";
    for(int i=0;i<n;i++){
        cin>>items[i].first>>items[i].second;
    }
    cout<<"Enter maximum weight: ";
    int w;cin>>w;
    cout<<"Maximum value: "<<knapsack(items,n,w)<<endl;
    return 0;
}