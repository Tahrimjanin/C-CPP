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

    while (1) {
        int size, allocated = 0;
        cout << "\nEnter size needed: ";
        cin >> size;
        if (size == 0) break;
        for (int i = 0; i < n; i++) {
            if (memory[i] >= size) { // If current block has enough space
                memory[i] -= size; // Subtract used size from the block
                cout << "Allocated in block " << i + 1 << endl;
                allocated = 1;
                break;
            }
        }
        if (!allocated)
            cout << "No suitable block found" << endl;
    }

    return 0;
}