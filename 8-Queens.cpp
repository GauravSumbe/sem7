
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, int x, int y, int n){

    // Check column
    for(int row=0; row<x; row++){
        if(arr[row][y] == 1)
            return false;
    }

    // Check left diagonal
    int row=x, col=y;
    while(row>=0 && col>=0){
        if(arr[row][col] == 1)
            return false;
        row--;
        col--;
    }

    // Check right diagonal
    row=x;
    col=y;
    while(row>=0 && col<n){
        if(arr[row][col] == 1)
            return false;
        row--;
        col++;
    }

    return true;
}

bool nQueen(int **arr, int x, int n){

    if(x == n){
        return true;
    }

    for(int col=0; col<n; col++){

        if(isSafe(arr,x,col,n)){
            arr[x][col] = 1;

            if(nQueen(arr,x+1,n))
                return true;

            arr[x][col] = 0;
        }
    }

    return false;
}

void printBoard(int **arr, int n){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1)
                cout << "[Q]";
            else
                cout << "[]";
        }
        cout << endl;
    }
}

int main(){

    int n=8;

    int **arr = new int*[n];

    for(int i=0; i<n; i++){
        arr[i] = new int[n]();
    }

    int r,c;

    cout << "Enter first queen position (row and column): ";
    cin >> r >> c;

    // Convert to 0-based indexing
    r--;
    c--;

    if(r<0 || r>=n || c<0 || c>=n){
        cout << "Invalid position";
        return 0;
    }

    arr[r][c] = 1;

    if(nQueen(arr,r+1,n)){
        cout << "\nSolution found:\n";
        printBoard(arr,n);
    }
    else{
        cout << "No solution exists!";
    }

    return 0;
}

// Explanation to write in exam
// 1. The 8-Queens problem is solved using the Backtracking technique.
// 2. The objective is to place 8 queens on an 8×8 chessboard so that no two queens attack each other.
// 3. First, the position of the first queen is accepted from the user.
// 4. The isSafe() function checks whether a queen can be placed safely by checking the column and both diagonals.
// 5. The nQueen() function places the remaining queens row by row.
// 6. If a position is unsafe, the algorithm backtracks and tries another position.
// 7. When all 8 queens are placed successfully, the solution is printed.
// Complexity Analysis
// Complexity	Value
// Time Complexity	O(N!) (upper-bound convention)
// Space Complexity	O(N²) for the board

// Important viva point: Why do we start with nQueen(arr, r+1, n)?

// Because the first queen is already placed at row r, so we start placing the remaining queens from the next row.
