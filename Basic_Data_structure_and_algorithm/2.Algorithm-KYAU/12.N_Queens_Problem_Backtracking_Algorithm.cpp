#include<bits/stdc++.h>
using namespace std;

int n; // Board size (n x n)
int board[10][10]; // Chess board - 1 means Queen placed, 0 means empty

// Print the current board state
void printBoard() {
  
    for (int i = 0; i < n; i++) {// 
        for (int j = 0; j < n; j++) { //colums
            cout << (board[i][j] ? "Q " : ". ");//board[i][j] is 1, print "Q" (Queen), else print "-" (empty)
        }
        cout << endl;
    }   
}
/// Check if placing a queen at (row, col) is safe
bool isSafe(int row, int col) {
    // Check if any queen exists in the same column above current row
    for (int i = 0; i < row; i++) {
        if (board[i][col]) return false; // Queen found, not safe
    }
    
    // Check left diagonal (upper-left direction)
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false; // Queen found on left diagonal
    }                                   
    // Check right diagonal (upper-right direction)
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j]) return false; // Queen found on right diagonal
    }
    return true; 
}
//// main backtracking function(Recursive function to solve N-Queens problem)
bool solve(int row) {
    // Base case: if we've placed queens in all rows, solution found
    if (row >= n) return true;
    
    // Try placing queen in each column of current row
    for (int col = 0; col < n; col++) {
        // Check if current position is safe
        if (isSafe(row, col)) 
          board[row][col] = 1; // Place queen at (row, col)
            
        if (solve(row + 1)) return true; 
         board[row][col] = 0;
        
    }
    return false; 
}   
int main() {
    cout << "Enter N: "; // Ask user for board size
    cin >> n; // Read board size

    memset(board, 0, sizeof(board)); // Initialize entire board with 0 (empty)
    
    if (solve(0)) {
        cout << "\nSolution found:\n";
        printBoard(); 
    } else {
        cout << "\nNo solution exists!\n";
    }
    return 0; 
}