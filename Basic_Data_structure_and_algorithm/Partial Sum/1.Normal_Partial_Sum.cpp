//In an arr to  sub arr sum (in 2 number)

#include <bits/stdc++.h>   
using namespace std;        
int main() {
    int n, q; // n size of array, q number of queries         
    cin >> n >> q;         

    int x[n + 1];  // Create an array of size n+1 (1-indexed)

    for (int i = 1; i <= n; i++) {
        cin >> x[i];       
    }

    while (q--) {   
        int a, b;   // a = starting index, b = ending index
        cin >> a >> b;  
        long long sum = 0; 

        for (int i = a; i <= b; i++) { 
            sum += x[i];   // Add up all elements from index a to b
        }

        cout << sum << '\n'; // Print the sum for this query in a new line
    }
}
