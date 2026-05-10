#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[100], n, value, pos = -1;
    cin >> n;
   
    for (int i = 0; i < n; i++)cin >> arr[i];
    cin >> value;
    
    // linear search algorithm
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            pos = i + 1;
            break;
        }
    } 
    
    if (pos == -1) cout << "Not found";
    else cout << value << " found at position " << pos;
    
    return 0;
}