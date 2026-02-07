#include<bits/stdc++.h>
using namespace std ;

int knapsack(vector<int>& w,vector<int>& c ,int n ,int capacity) {
    vector<vector<int>> dp(n+1 ,vector <int>(capacity+1) ) ;
    for(int i=0 ;i<n;i++){
        for(int w=0 ;w<capacity;w++){
            if(i==0 || w==0){
                dp[i][w] = 0;
            }
            else if(w[i-1]<= w){
                dp[i][w] =max(c[i-1]+dp[i-1][w-W[i-1]],dp[i-1][w]) ; 
            }
            else {
                dp[i][w] = dp[i-1][w] ;

            }

            
        }
        return dp[n][capacity] ;
    }
}
