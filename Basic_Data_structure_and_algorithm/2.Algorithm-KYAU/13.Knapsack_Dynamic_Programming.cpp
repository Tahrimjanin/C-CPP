#include<bits/stdc++.h>
using namespace std;


int knapsack(vector<int>& W, vector<int>& C, int n, int capacity) {
    // Create 2D DP table: dp[i][w] = max value using first i items with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1));
    
    // Loop through all items (i = 0 means no items)
    for (int i = 0; i <= n; i++) {
        // Loop through all possible capacities from 0 to max capacity
        for (int w = 0; w <= capacity; w++) {
            // Base case: if no items or no capacity, value is 0
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            // If current item's weight fits in remaining capacity
            else if (W[i - 1] <= w) {
                // Take maximum of two choices:
                // 1. Include current item: add its cost + best solution for remaining capacity
                // 2. Exclude current item: take best solution without this item
                dp[i][w] = max(C[i - 1] + dp[i - 1][w - W[i - 1]], 
                               dp[i - 1][w]);
            }
            // If current item's weight doesn't fit
            else {
                // Can't include this item, so take best solution without it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    // Return the maximum value for all n items with full capacity
    return dp[n][capacity];
}

int main() {
    // n = number of items, capacity = knapsack capacity
    int n, capacity;
    cout << "Items : ";
    cin >> n;  
    cout << "Capacity: ";
    cin >> capacity;  
    
    // W = weights array, C = costs/values array
    vector<int> W(n), C(n);
    
    for (int i = 0; i < n; i++) {
        cin >> W[i] >> C[i];  // W[i] = weight, C[i] = value of item i
    }
    // Call knapsack function and store result
    int maxCost = knapsack(W, C, n, capacity);
    
    cout << maxCost << endl;
    return 0;  
}