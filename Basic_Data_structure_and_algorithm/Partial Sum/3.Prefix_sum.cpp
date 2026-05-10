#include <bits/stdc++.h>   
using namespace std;

#define ll long long

int main() {
    int n, q; 
    cin >> n >> q;

    ll x[n + 1];  

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    while (q--) {
        int a, b;
        cin >> a >> b; // query range

        ll current_sum = 0;
        ll max_sum = LLONG_MIN;

        // Kadane’s algorithm on subarray
        for (int i = a; i <= b; i++) {
            current_sum = max(x[i], current_sum + x[i]);
            max_sum = max(max_sum, current_sum);
        }

        cout << max_sum << "\n"; 
    }
}
