#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
int N;

// Check whether queen can be placed safely
bool isSafe(int row, int col){

    // Check left side of current row
    for(int i = 0; i < col; i++){
        if(board[row][i] == 1){
            return false;
        }
    }

    // Check upper-left diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    // Check lower-left diagonal
    for(int i = row, j = col; i < N && j >= 0; i++, j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    return true;
}

// Backtracking function
bool nqueen(int col){

    // All queens placed
    if(col >= N){
        return true;
    }

    for(int row = 0; row < N; row++){

        if(isSafe(row, col)){

            board[row][col] = 1;

            // Recur for next column
            if(nqueen(col + 1)){
                return true;
            }

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main(){

    cout << "Enter value of N: ";
    cin >> N;

    board.resize(N, vector<int>(N, 0));

    if(nqueen(0)){

        cout << "\nSolution:\n\n";

        for(int i = 0; i < N; i++){

            for(int j = 0; j < N; j++){

                if(board[i][j] == 1){
                    cout << "Q ";
                }
                else{
                    cout << ". ";
                }
            }

            cout << endl;
        }
    }
    else{
        cout << "No solution exists!" << endl;
    }

    return 0;
}


/*
Enter value of N: 4
*/