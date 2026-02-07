// atcoder problem : https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_1_D


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;  // n = num of vectors
    cin >> n >> q;  // q = numof queries to process 
      
    vector<int> v[n];  
    
    for (int i = 0; i < q; i++) {  
        int tp;  // tp = type of query (0, 1, or 2) 
        cin >> tp;  

        if (tp == 0) {  // Type 0 → Add element to a specific vector
            int t, x;  
            cin >> t >> x;  
            // t = which vector index (0 to n-1)  
            // x = value to add
            v[t].push_back(x);  
            // Adds x to vector number t
        }
        else if (tp == 1) { //Print all elements of a specific vector
            // Type 1 → Print all elements of a specific vector
            int t;  
            cin >> t;  
            for (int j = 0; j < v[t].size(); j++) {  
                cout << v[t][j];  
                if (j != v[t].size() - 1) cout << " ";  
            }
            cout << '\n';  
        }
        else {  
            // Type 2 → Clear all elements from a specific vector
            int t;  
            cin >> t;  
            v[t].clear();  
        }
    }
    return 0;    
}
/*
Takes n lists and q queries as input.
For each query:
tp == 0 → Add number x to list v[t].
tp == 1 → Print all numbers in list v[t].
tp == 2 → Clear list v[t]. 
*/






