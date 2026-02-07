#include<bits/stdc++.h>
using namespace std ;

int n ;
int board[10][10] ;

void PrintBoard(){
    for(int i= 0 ; i< n ;i++){
        for(int j= 0 ; j< n ;j++){
            cout<<(board[i][j] ? " Q " : " . ") ;
        }
         cout << endl;
    }
}
bool isSafe(int row ,int col){
    for(int i=0 ;i<row ;i++){
        if(board[i][col]) return false ; 
    }
    for( int i = row ,j= col; i>=0 && j>=0 ;i--,j--){
         if(board[i][j]) return false ;
    }
    for(int i = row ,j= col; i>=0 && j<n ;i--,j++){
        if(board[i][j]) return false ;
    }

    return true ;
}

bool solve (int row){
    if (row>=n) return true ;

   for(int col=0; col<n ; col++){
    if(isSafe(row,col)) {
    board[row][col] = 1 ;

    if (solve(row+1)) return true ;
    board[row][col] = 0 ;
     }
    }
    return false ;
}



int main(){
    cout<<"Enter N" ;
    cin>>n ;
    memset(board ,0,sizeof(board));
    if (solve(0)) {
        cout << "\nSolution found:\n";
        PrintBoard(); 
    } else {
        cout << "\nNo solution exists!\n";
    }

}