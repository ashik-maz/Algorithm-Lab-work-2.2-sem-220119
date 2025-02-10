#include<bits/stdc++.h>
using namespace std;

void findMaxMin(int arr[],int n){
    int max=arr[0];
    int min=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }
    cout<<"Max="<<max<<endl<<"Min="<<min<<endl;
}
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    findMaxMin(arr,n);
}