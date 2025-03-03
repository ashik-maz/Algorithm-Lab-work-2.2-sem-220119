//tTower of Hanoi
#include <bits/stdc++.h>
using namespace std;

void TowerOfHanoi(int n, char src, char aux, char dest){
    if(n==0) return;

    TowerOfHanoi(n-1,src,dest,aux);
    cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<endl;
    TowerOfHanoi(n-1,aux,src,dest);
}


int main() {
    cout << "Enter the number of disks: ";
    int n;cin>>n;
    TowerOfHanoi(n, 'A', 'B', 'C');
}
