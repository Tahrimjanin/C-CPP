#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of memory blocks: ";
    cin >> n;

    int memory[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter size of block " << i + 1 << ": ";
        cin >> memory[i];
    }

    int lastIndex = 0; 

    while (1) {
        int size, allocated = 0;
        cout << "\nEnter size needed  ";
        cin >> size;

        if (size == 0) break;

      
        for (int count = 0; count < n; count++) {
            int i = (lastIndex + count) % n; // সর্বশেষ যে ব্লকে দিয়েছিলাম সেখান থেকে খোঁজা শুরু করো,
            // শেষে পৌঁছে গেলে আবার Block 1 থেকে শুরু করো
            if (memory[i] >= size) {
                memory[i] -= size;
                cout << "Allocated in block " << i + 1 << endl;
                lastIndex = i; 
                allocated = 1;
                break ;
            }
        }

        if (!allocated)
            cout << "No suitable block found" << endl;
    }

    return 0;
}