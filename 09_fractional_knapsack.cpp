#include <bits/stdc++.h> 
using namespace std;

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(),items.end(),[](pair<int,int>a,pair<int,int>b){
        return (double)a.second/a.first>(double)b.second/b.first;
    });
    double maxValue=0.0;
    for(int i=0;i<n;i++){
        int weight=items[i].first;
        int value=items[i].second;
        if(w>=weight){
            maxValue+=value;
            w-=weight;
        }else{
            maxValue+=((double)value/weight)*w;
            break;
        }
    }
    return maxValue;
}

int main(){
    cout<<"Enter Number of Items: ";
    int n;cin>>n;
    vector<pair<int,int>>items(n);
    cout<<"Enter every item weight and value : ";
    for(int i=0;i<n;i++){
        cin>>items[i].first>>items[i].second;
    }
    cout<<"Enter Weight: ";
    int w;cin>>w;
    cout<<"Maximum Value="<<maximumValue(items,n,w)<<'\n';
}


