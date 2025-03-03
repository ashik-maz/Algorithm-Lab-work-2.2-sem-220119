//binary search
#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int>&arr, int target){
    int low=0,high=arr.size()-1;

    while (low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            high=mid+1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
int main(){
    int n,target;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int>arr(n);
    for(int &x:arr) cin>>x;

    sort(arr.begin(),arr.end());
    cout<<"Enter the target element: ";
    cin>>target;
    cout<<"The index of the target element is: "<<binarysearch(arr,target);
}