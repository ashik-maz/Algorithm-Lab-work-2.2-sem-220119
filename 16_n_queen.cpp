#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<string> &board, int row, int col, int n){
    //horizontal
    for(int j=0;j<n;j++){
        if(board[row][j] == 'Q')
        return false;
    }
    //vertical
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q')
        return false;
    }
   
    //left diagonal
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
       if(board[i][j]=='Q')
       return false;
    }
   
    //right diagonal
    for(int i=row,j=col; i>=0 && j<n; i--, j++){
        if(board[i][j]=='Q')
        return false;
    }
    return true;
}

void nQueen(vector<string> &board, int row, int n, vector<vector<string>> &ans){
    if(row == n){
        ans.push_back(board);
        return;
    }
    for(int j=0;j<n;j++){
        if(isSafe(board,row, j, n)){
            board[row][j]='Q';
            nQueen(board,row+1,n,ans);
            board[row][j]='.';
        }
    }
   
}
vector<vector<string>> solveQueens(int n){
    vector<string> board(n, string(n,'.'));
    vector<vector<string>>ans;
    nQueen(board,0,n,ans);
    return ans;
}

void display(vector<vector<string>> ans){
    cout<<"solutions\n";
    for(const auto &board:ans){
        for(const auto &row:board){
            for(const auto &c:row){
                cout<<c<<"  ";
            }
            cout<<'\n';
        }
        cout<<"---------------------------\n";
    }
}
int main(){
   cout<<"Enter the Queen number: ";
   int n;cin>>n;
   vector<vector<string>> ans=solveQueens(n);
   display(ans);
   return 0;
}
