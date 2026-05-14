#include <bits/stdc++.h>   
using namespace std;

int main() {
    int n, tq;
    cout << "Enter the number of processes: ";
    cin >> n;

    int process[n], arrival[n], burst[n], remaining[n], completion[n];
    int waiting[n], turnaround[n];

    // --------- Input ---------
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        cout << "Enter arrival time of process " << process[i] << ": ";
        cin >> arrival[i];
        cout << "Enter burst time of process " << process[i] << ": ";
        cin >> burst[i];

        remaining[i] = burst[i];
        completion[i] = 0;
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    int time = 0, completed = 0;

    // --------- Hybrid SRTF + Quantum ---------
    while (completed < n) {
        int min_index = -1;
        int min_remaining = 9999;

        // find shortest remaining time process among arrived ones
        for (int i = 0; i < n; i++) {
            if (arrival[i] <= time && remaining[i] > 0 && remaining[i] < min_remaining) {
                min_remaining = remaining[i];
                min_index = i;
            }
        }

        // No process arrived → jump to next arrival time
        if (min_index == -1) {
            int next_arrival = 9999;
            for (int i = 0; i < n; i++) {
                if (arrival[i] > time && arrival[i] < next_arrival)
                    next_arrival = arrival[i];
            }
            time = next_arrival;
            continue;
        }

        // Execute process for min(quantum, remaining)
        int exec_time = (remaining[min_index] > tq) ? tq : remaining[min_index];
        remaining[min_index] -= exec_time;
        time += exec_time;

        // If process finished
        if (remaining[min_index] == 0) {
            completion[min_index] = time;
            completed++;
        }
    }

    // --------- Calculate Times ---------
    float total_wt = 0, total_tat = 0;

    cout << "\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];

        total_wt += waiting[i];
        total_tat += turnaround[i];

        cout << process[i] << "\t" << arrival[i] << "\t" << burst[i] << "\t"
             << completion[i] << "\t\t" << turnaround[i] << "\t\t" << waiting[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n << endl;

    return 0;
}