#include <iostream>
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
        int size, bestIndex = -1;
        cout << "\nEnter size needed (0 to exit): ";
        cin >> size;

        if (size == 0) break;

        // Find the best fitting block (smallest sufficient)
        for (int i = 0; i < n; i++) {
            if (memory[i] >= size) {
                if (bestIndex == -1 || memory[i] < memory[bestIndex]) {
                    bestIndex = i;
                }
            }
        }

        if (bestIndex != -1) {
            memory[bestIndex] -= size;
            cout << "Allocated in block " << bestIndex + 1 << endl;
        } else {
            cout << "No suitable block found" << endl;
        }
    }

    return 0;
}