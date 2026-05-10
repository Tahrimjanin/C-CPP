#include <bits/stdc++.h> 
using namespace std;    

int main() { 
    int arr[100], n, value, low = 0, high, mid; 
    cin >> n; 
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> value;

    high = n - 1;
    
    while (low <= high) {
        mid = (low + high) / 2;
        
        if (arr[mid] == value) {
            cout << "Found at index " << mid;
            return 0;
        }
        else if (arr[mid] < value) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    cout << "Not found";
}
