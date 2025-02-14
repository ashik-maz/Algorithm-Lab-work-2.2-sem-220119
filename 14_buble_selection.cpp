#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}
int main(){
    cout<<"Enter array size: ";
    int n;cin>>n;
    int arr[n], arrcopy[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arrcopy[i]=arr[i];
    }
    bubbleSort(arr,n);
    for(auto x:arr){
        cout<<x<<" ";
    }
    cout<<'\n';
    selectionSort(arr,n);
    for(auto x:arr){
        cout<<x<<" ";
    }
}