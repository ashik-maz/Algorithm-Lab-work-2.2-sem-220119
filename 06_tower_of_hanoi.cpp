#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination){
    if(n==1){
        cout<<"Move disk 1 from "<<source<<" to"<<destination<<endl;
        return;
    }
    // Move n-1 disks from source to auxiliary using destination as buffer
    towerOfHanoi(n-1,source,destination, auxiliary);

    // Move nth disk from source to destination
    cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;

    // Move n-1 disks from auxiliary to destination using source as buffer
    towerOfHanoi(n-1, auxiliary,source, destination);
}

int main(){
    int n;
    cout<<"Enter the number of disks: ";
    cin>>n;

    // A, B, C are the rods
    towerOfHanoi(n,'A','B','C');

    return 0;
}