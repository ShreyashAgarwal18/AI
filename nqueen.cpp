#include<bits/stdc++.h>
using namespace std;

#define N 8

int board[N][N] = {0};

bool isSafe(int row, int col){

    for(int i = 0; i<col; i++){
        if(board[row][i] == 1){
            return false;
        }
    }

    for(int i = row, j = col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    for(int i = row, j = col; i<N && j>=0; i++, j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    return true;
}


bool nqueen(int col){
    if(col>=N) return true;

    for(int row = 0; row<N; row++){
        if(isSafe(row, col)){
            board[row][col] = 1;
            if(nqueen(col+1)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}


int main(){

    if(nqueen(0)){
        cout<<"Solution: \n";

        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(board[i][j] == 1){
                    cout<<"Q"<<" ";
                }
                else if(board[i][j] == 0){
                    cout<<"."<<" ";
                }
            }
            cout<<endl;
        }
    }
    return 0;


}