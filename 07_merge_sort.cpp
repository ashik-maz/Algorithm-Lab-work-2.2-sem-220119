//Merge Sort
#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int left, int mid, int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[left+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=arr[mid+1+i];
    }

    int i=0,j=0,k=left;

    while(i<n1 and j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int left, int right){
    if(left>=right){
        return;
    }
    int mid=(left+right)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right); 
    merge(arr,left,mid,right);
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";  
    cin>>n;
    int arr[n];     
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}