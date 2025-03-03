//devide and conquere
#include<bits/stdc++.h>
using namespace std;    

void findMinMax(int arr[],int low, int high, int &minval, int &maxval){
    // Base case: Single element
    if(low==high){
        minval=maxval=arr[low];
        return;
    }
    // Base case: Two elements
    if(high==low+1){
        if(arr[low]<arr[high]){
            minval=arr[low];
            maxval=arr[high];
        }
        else{
            minval=arr[high];
            maxval=arr[low];
        }
        return;
    }
    // Divide
    int mid=(low+high)/2;
    int minleft,maxleft,minright,maxright;

    findMinMax(arr,low,mid,minleft,maxleft);
    findMinMax(arr,mid+1,high,minright,maxright);

    // Conquer
    minval=min(minleft,minright);
    maxval=max(maxleft,maxright);
}

int main(){
    cout<<"Enter the number of elements: ";
    int n;cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int minval,maxval;
    findMinMax(arr,0,n-1,minval,maxval);
    cout<<"Minimum: "<<minval<<endl;
    cout<<"Maximum: "<<maxval<<endl;
    return 0;
}
