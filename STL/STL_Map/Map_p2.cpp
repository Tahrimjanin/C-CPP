/* Twice Counter

Given a list of N words. Count the number of words that appear exactly twice in the list.
Input:
N = 3
list = {Geeks, For, Geeks}
Output: 1

*/

#include <bits/stdc++.h>
using namespace std;

int countWords(string list[], int n) {
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        m[list[i]]++;
    }
    int ans = 0;
    for (auto &a : m) {
        if (a.second == 2) ans++;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    string list[n];
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    cout << countWords(list, n) << "\n";

    return 0;
}
