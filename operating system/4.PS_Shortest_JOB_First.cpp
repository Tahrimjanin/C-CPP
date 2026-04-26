#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n; 

    int process[n], arrival[n], burst[n], completion[n], turnaround[n], waiting[n];
    int i, j, temp, pos, current_time = 0;

    // Input process details 
    for (i = 0; i < n; i++) {
        process[i] = i + 1;
        cout << "Enter arrival time of process " << process[i] << ": ";
        cin >> arrival[i];
        cout << "Enter burst time of process " << process[i] << ": ";
        cin >> burst[i];
        completion[i] = -1; 
    }

    // Sorting processes based on arrival time (initial order)
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (arrival[j] < arrival[pos]) {
                pos = j;
            }
        }

        // Swap arrival time
        temp = arrival[i];
        arrival[i] = arrival[pos];
        arrival[pos] = temp;
         // Swap burst time
        temp = burst[i];
        burst[i] = burst[pos];
        burst[pos] = temp;
      // Swap process IDs 
        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;
    }

    // Apply Shortest Job First (Non-Preemptive)
    int completed = 0, is_completed[n];
    for (i = 0; i < n; i++) is_completed[i] = 0; 

    while (completed != n) {
        int min_burst = 9999, index = -1; 
        for (i = 0; i < n; i++) {
            if (arrival[i] <= current_time && is_completed[i] == 0) {
                if (burst[i] < min_burst) {
                    min_burst = burst[i];
                    index = i;
                }
                // If burst times are equal, pick the one that arrived first
                else if (burst[i] == min_burst && arrival[i] < arrival[index]) {
                    index = i;
                }
            }
        }

        if (index != -1) {
            completion[index] = current_time + burst[index];
            turnaround[index] = completion[index] - arrival[index];
            waiting[index] = turnaround[index] - burst[index];
            current_time = completion[index];
            is_completed[index] = 1;
            completed++;
        } else {
            current_time++;
        }
    }

    // Printing the final process table
    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (i = 0; i < n; i++) {
        cout << process[i] << "\t" << arrival[i] << "\t\t" << burst[i] << "\t\t"
             << completion[i] << "\t\t" << turnaround[i] << "\t\t" << waiting[i] << "\n";
    }

    return 0;
}


