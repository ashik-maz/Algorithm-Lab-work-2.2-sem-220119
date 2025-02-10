#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr,int size,int i){
    int root=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<size && arr[left]>arr[root])
        root=left;

    if(right<size && arr[right]>arr[root])
        root=right;

    if(root != i){
        swap(arr[i],arr[root]);
        heapify(arr,size,root);
    }
}

void heafsort(vector<int> &arr){
    int size=arr.size();
    for(int i=size/2-1;i>=0;i--){
        heapify(arr,size,i);
    }
    
    for(int i=size-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main(){
    vector<int>arr;
    cout<<"Enter Element(-1 for stop): ";
    while(true){
        int x;cin>>x;
        if(x==-1) break;
        arr.push_back(x);
    }
    heafsort(arr);
    cout<<"Sorted Array: ";
    for(auto x:arr){
        cout<<x<<" ";
    }
    cout<<endl;
}