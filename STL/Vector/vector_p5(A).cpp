/*Tetrahedral Number 
You are given an integer N.Print all triples of non-negative integers 
(x,y,z) such that x+y+z≤N in ascending lexicographical order.
What is lexicographical order for non-negative integer triples?
Constraints
0≤N≤21
.
Input
The input is given from Standard Input in the following format:
N
3
Output

Print all triples of non-negative integers 
(x,y,z) such that 
x+y+z≤N in ascending lexicographical order, with 
x,y,z separated by spaces, one triple per line.

0 0 0
0 0 1
0 0 2
0 0 3
0 1 0
0 1 1
0 1 2
0 2 0
0 2 1
0 3 0
1 0 0
1 0 1
1 0 2
1 1 0
1 1 1
1 2 0
2 0 0
2 0 1
2 1 0
3 0 0*/


#include <bits/stdc++.h>  
using namespace std;

int main() {
    int n;
    cin >> n; 

    vector<array<int, 3>> triples;

    // Loop over possible values of x
    for (int x = 0; x <= n; ++x) {
        // Loop over possible values of y (limited so that x + y <= n)
        for (int y = 0; y <= n - x; ++y) {
            // Loop over possible values of z (limited so that x + y + z <= n)
            for (int z = 0; z <= n - x - y; ++z) {
                triples.push_back({x, y, z}); 
            }
        }
    }
    // Sort all triples in lexicographical order but kept for safety if generation order changes)
    sort(triples.begin(), triples.end());

    for (const auto& triple : triples) {
        cout << triple[0] << " " << triple[1] << " " << triple[2] << endl;
    }

    return 0;
}
  