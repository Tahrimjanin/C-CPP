/* 
Sorting
time limit per test1 second
memory limit per test64 megabytes
Given a number N and an array A of N numbers. Print the numbers after sorting them.
Second line contains N numbers ( - 100 ≤ Ai ≤ 100).

Output
Print the numbers after sorting them.

Examples
InputCopy
3
3 1 2
OutputCopy
1 2 3 
InputCopy
4
5 2 7 3
OutputCopy
2 3 5 7 

*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
   
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
   
