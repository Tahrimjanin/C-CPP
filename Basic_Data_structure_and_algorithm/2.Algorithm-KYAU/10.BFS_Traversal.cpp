#include<iostream>
using namespace std;

int main() {
    // Variable declarations
    int n, start;                    // n = number of vertices, start = starting vertex
    int adj[10][10];                 // Adjacency matrix to store graph connections
    int visited[10] = {0};           // Track visited nodes (0 = not visited, 1 = visited)
    int queue[10];                   // Queue array for BFS
    int front = 0, rear = 0;         // front = queue start, rear = queue end
    
    // Input: number of vertices
    cout << "Enter number of vertices: ";
    cin >> n;
    
    // Input: adjacency matrix (graph connections)
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {           // Loop through rows
        for (int j = 0; j < n; j++) {       // Loop through columns
            cin >> adj[i][j];                // Read connection (1 = connected, 0 = not connected)
        }
    }
    
    // Input: starting vertex for BFS
    cout << "Enter starting vertex (0 to " << n - 1 << "): ";
    cin >> start;
    
    // Initialize BFS
    visited[start] = 1;              // Mark starting vertex as visited
    queue[rear++] = start;           // Add starting vertex to queue (rear++ means add and move rear)
    
    cout << "BFS Traversal: ";
    
    // Main BFS loop - continue until queue is empty
    while (front < rear) {           // front < rear means queue has elements
        int node = queue[front++];   // Remove node from front of queue (dequeue)
        cout << node << " ";         // Print current node
        
        // Check all neighbors of current node
        for (int i = 0; i < n; i++) {                        // Loop through all vertices
            if (adj[node][i] == 1 && visited[i] == 0) {      // If connected and not visited
                queue[rear++] = i;                           // Add neighbor to queue (enqueue)
                visited[i] = 1;                              // Mark neighbor as visited
            }
        }
    }
    
    cout << endl;                    // Print newline after traversal
    return 0;                        // Program ends successfully
}