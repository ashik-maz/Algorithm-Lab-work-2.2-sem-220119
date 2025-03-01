#include<bits/stdc++.h>
using namespace std;

int lcs(string &s1, string &s2, int m, int n){
    if(m==0 or n==0)
        return 0;
    
    if(s1[m-1]==s2[n-1])
        return 1+lcs(s1,s2,m-1,n-1);
    else
        return max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n));
}

int main(){
    string s1,s2;cin>>s1>>s2;
    int m=s1.size(),n=s2.size();
    cout<<"LCS: "<<lcs(s1,s2,m,n);
}