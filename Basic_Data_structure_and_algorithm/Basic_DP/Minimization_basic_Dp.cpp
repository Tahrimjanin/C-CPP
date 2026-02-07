/* int  n. On each step,subtract one of the digits from the number.
How many steps are required to make the number equal to 0?

Input:27
Output:5
*/
#include <bits/stdc++.h>
using namespace std;

int n, vis[1000005], dp[1000005];

int solve(int m) {
    if (m == 0) return 0;  
    if (vis[m]) return dp[m];

    int temp = m;
    int res = INT_MAX;

    while (temp > 0) {  
        int digit = temp % 10;  
        if (digit != 0) {
            res = min(res, 1 + solve(m - digit));  
        }
        temp /= 10;  
    }
    vis[m] = 1;  
    return dp[m] = res;  
}

int main() {
    cin >> n;
    memset(dp, -1, sizeof(dp)); 
    int ans = solve(n);
    cout << ans << endl;
}


