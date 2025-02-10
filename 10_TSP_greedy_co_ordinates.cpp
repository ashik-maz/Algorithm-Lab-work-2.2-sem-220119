#include <bits/stdc++.h>
using namespace std;

double dist(pair<int,int>&a,pair<int,int>&b){
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));

}
double TSP(vector<pair<int,int>>& cities){
    int n=cities.size();
    vector<bool>visited(n,false);
    double totalDist=0;
    visited[0]=true;
    int currentCity=0;
    for(int i=0;i<n;i++){
        double minDist=DBL_MAX;
        int nextCity=-1;
        for(int j=0;j<n;j++){
            if(!visited[j]){
                double d=dist(cities[currentCity],cities[j]);
                if(d<minDist) {
                    minDist=d;
                    nextCity=j;
                }
            }
        }
        if(nextCity == -1) break;//Prevents undefined behavior
        visited[nextCity]=true;
        totalDist+=minDist;
        currentCity=nextCity;
    }
    totalDist+=dist(cities[currentCity],cities[0]);
    return totalDist;
}
int main(){
    cout<<"Enter the Number of cites: ";
    int n;cin>>n;
    vector<pair<int,int>> cites(n);
    cout<<"Enter the Cordinates of the cites (x,y):\n";
    for(int i=0;i<n;i++){
        cin>>cites[i].first>>cites[i].second;
    }
    double totalDistance=TSP(cites);
    cout<<"Total Distance: "<<totalDistance<<endl;
}