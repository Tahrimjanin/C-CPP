#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int n, start;                           
    
    // Input: number of vertices
    cout << "Enter number of vertices: ";
    cin >> n; 
    
    int adj[10][10];                        // Adjacency matrix to store graph connections
    vector<bool> visited(n, false);         // Track visited nodes (false = not visited)
    
    // Input: adjacency matrix (graph connections)
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {           // Loop through rows
        for (int j = 0; j < n; j++) {       // Loop through columns
            cin >> adj[i][j];                // Read connection (1 = connected, 0 = not connected)
        }
    }  
    
    // Input: starting vertex for DFS
    cout << "Enter starting vertex (0 to " << n - 1 << "): ";
    cin >> start;
    
    // Initialize DFS with stack
    stack<int> st;                          // Create stack for DFS (LIFO - Last In First Out)
    st.push(start);                         // Push starting vertex to stack
    
    cout << "DFS Traversal: ";
    
    // Main DFS loop - continue until stack is empty
    while (!st.empty()) {                   // যতক্ষণ stack খালি না
        int node = st.top();                // Get top element from stack
        st.pop();                           // Remove top element from stack
        
        // Check if node is already visited
        if (!visited[node]) {               // যদি এখনো visit না করা হয়
            cout << node << " ";            // Print current node
            visited[node] = true;           // Mark node as visited
        }
        
        for (int i = n - 1; i >= 0; i--) {              
            if (adj[node][i] == 1 && !visited[i]) {    
                st.push(i);                              
            }
        }
    }
    
    cout << endl;                          
    return 0;                               
}