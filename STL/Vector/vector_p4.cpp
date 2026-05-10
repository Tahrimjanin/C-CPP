/* HackerRank -Distinct Count
Algorithms, Approved, Binary search tree, Easy, Open, Sets, Sorting, Trees
Given an array A of N integers, classify it as being Good Bad or Average. It is called Good, if it contains exactly
 X distinct integers, Bad if it contains less than X distinct integers and Average if it contains more than X 
 distinct integers.

Input format:
First line consists of a single integer T denoting the number of test cases.
First line of each test case consists of two space separated integers denoting N and X.
Second line of each test case consists of N space separated integers denoting the array elements.
4
4 1
1 4 2 5
4 2
4 2 1 5
4 3
5 2 4 1
4 4
1 2 4 5

Output format:
Print the required answer for each test case on a new line.
Average
Average
Average
Good

*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int distinctCount = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1]) {
                distinctCount++;
            }
        }
        if (distinctCount < x) {
            cout << "Bad" << endl;
        }
        else if (distinctCount == x) {
            cout << "Good" << endl;
        }
        else {
            cout << "Average" << endl;
        }
    }
    return 0;


}