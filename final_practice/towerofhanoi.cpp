#include<bits/stdc++.h>
using namespace std;

void TOH(int n, char src, char aux, char dest){
    if(n==0) return;
    TOH(n-1,src,dest,aux);
    cout<<"Move disc"<<n<<" from "<<src<<" to "<<dest<<endl;
    TOH(n-1,aux,src,dest);
}
int main(){
    int n;cin>>n;
    TOH(n,'A','B','C');
}