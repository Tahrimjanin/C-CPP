/*  Find the Frequency
Given an array arr of positive integers and an integer x  Return the frequency of x in the array.
Input: arr = [1, 1, 1, 1, 1], x = 1
Output: 5
Explanation: Frequency of 1 is 5.

*/

#include <bits/stdc++.h>
using namespace std;

int findFrequency(vector<int> arr, int x) {
    map<int, int> m;
    for (int a : arr) {
        m[a]++; // count frequency
    }
    return m[x]; // return frequency of x
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 2, 4, 1};
    int x = 2;
    cout << "Frequency of " << x << " = " << findFrequency(arr, x) << "\n"; 
    return 0;
}
