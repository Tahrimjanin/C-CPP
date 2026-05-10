#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int process[n], arrival[n], execution[n], completion[n];
    int i, j, pos, temp;

    // Input process details
    for (i = 0; i < n; i++) {
        process[i] = i + 1;
        cout << "Enter arrival time of process " << process[i] << ": ";
        cin >> arrival[i];
        cout << "Enter execution time of process " << process[i] << ": ";
        cin >> execution[i];
        completion[i] = -1;
    }

    // selection Sorting processes based on arrival time (FCFS scheduling)
    for (i = 0; i < n; i++) // Loop to find the position of process with the smallest arrival time
    { 
        pos = i;
        for (j = i + 1; j < n; j++) { // Loop to find out the process with the minimum arrival time
            // i ar bame sorted but dane unsorted(tai dan a khujbe ) tai i+1
            if (arrival[pos] > arrival[j]) {
                pos = j;
            }
        }
        // Swap arrival time
        temp = arrival[i]; 
        arrival[i] = arrival[pos];
        arrival[pos] = temp;

        // Swap execution time
        temp = execution[i];
        execution[i] = execution[pos];
        execution[pos] = temp;

        // Swap process IDs
        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;
    }

    // Calculating Completion Time
    for (i = 0; i < n; i++) {
        if (i == 0) {
            completion[i] = arrival[i] + execution[i];
        } else {
            if (completion[i - 1] > arrival[i]) {
                completion[i] = completion[i - 1] + execution[i];
            } else {
                completion[i] = arrival[i] + execution[i];
            }
        }
    }

    // Printing final table after calculating completion times
    cout << "\nProcess\tArrival Time\tExecution Time\tCompletion Time\n";
    for (i = 0; i < n; i++) {
        cout << process[i] << "\t" << arrival[i] << "\t\t" << execution[i] << "\t\t" << completion[i] << "\n";
    }

    return 0;
}