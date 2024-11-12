#include<bits/stdc++.h>
using namespace std ;


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int frequency[26] = {0};

    for (int i = 0; i < n; i++) {
        frequency[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        while (frequency[i] > 0) {
            cout << char('a' + i);
            frequency[i]--;
        }
    }
    cout << endl;
}

