#include <bits/stdc++.h>   
using namespace std;

#define ll long long

int main() {
    int n, q; // n size of array, q number of queries         
    cin >> n >> q;         
    int x[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> x[i];       
    }

    ll pref_sum[n + 1];
    pref_sum[0] = 0;
 

    for (int i = 1; i <= n; i++) {
        pref_sum[i] = pref_sum[i - 1] + x[i]; // Create the prefix sum array
    }

    while (q--) {   
        int l, r;
        cin >> l >> r;  
        ll ans = pref_sum[r] - pref_sum[l - 1];
        cout << ans << '\n'; 
        
    }


}