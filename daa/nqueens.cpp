#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string>& board){
    int oldrow=row, oldcol=col;

    // left
    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }
    
    row=oldrow;
    col=oldcol;

    //up
    while(row>=0){
        if(board[row][col]=='Q') return false;
        row--;
    }

    row=oldrow;
    col=oldcol;

    //left upper diagonal
    while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }

    row=oldrow;
    col=oldcol;

    //left lower diagonal
    while(row<board.size() && col>=0){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }

    return true;
}

void nqueens(int col, vector<string>& board,vector<vector<string>>& ans, int n){
    if(col>=n){
        ans.push_back(board);
        return;
    }
    
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board)){
            board[row][col]='Q';
            nqueens(col+1,board,ans,n);
            board[row][col]='.';
        }
        
    }
}

int main(){
    vector<vector<string>>ans;
    int n;
    cout<<"Enter board size: "<<endl;
    cin>>n;
    string s(n,'.');
    vector<string>board(n,s);

    nqueens(0,board,ans,n);

    for(auto i: ans){
        for(auto j: i){
            cout<<j<<endl;
        }
        cout<<"-----------"<<endl;
    }
}