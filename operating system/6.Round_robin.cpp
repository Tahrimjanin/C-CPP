#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i, tq;

    cout << "Enter the number of processes: ";
    cin >> n;

    int process[n], arrival[n], burst[n], remaining[n], completion[n];
    int waiting[n], turnaround[n];

    // ----- Input process details -----
    for (i = 0; i < n; i++) {
        process[i] = i + 1;
        cout << "Enter arrival time of process " << process[i] << ": ";
        cin >> arrival[i];
        cout << "Enter burst time of process " << process[i] << ": ";
        cin >> burst[i];

        remaining[i] = burst[i];   // remaining time initially burst time
        completion[i] = 0;         // will calculate later
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    // ----- Initialization -----
    int time = 0, completed = 0;
    int queue[100], front = 0, rear = 0;

    int visited[n];
    for (i = 0; i < n; i++)
        visited[i] = 0;

    // Add processes that arrive at time = 0
    for (i = 0; i < n; i++) {
        if (arrival[i] == 0) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    // ----- Round Robin Execution -----
    while (completed < n) {

        // If queue is empty → jump to next arrival
        if (front == rear) {
            int next_arrival = 9999;

            for (i = 0; i < n; i++) {
                if (remaining[i] > 0 && arrival[i] > time && arrival[i] < next_arrival) {
                    next_arrival = arrival[i];
                }
            }

            time = next_arrival;

            // Add processes that have arrived now
            for (i = 0; i < n; i++) {
                if (arrival[i] <= time && remaining[i] > 0 && !visited[i]) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
        }

        int idx = queue[front++];

        // Process execution
        if (remaining[idx] > tq) {
            time += tq;
            remaining[idx] -= tq;
        } else {
            time += remaining[idx];
            remaining[idx] = 0;
            completion[idx] = time;
            completed++;
        }

        // Add processes that have arrived during execution
        for (i = 0; i < n; i++) {
            if (arrival[i] <= time && remaining[i] > 0 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        // If current process is not finished → push back to queue
        if (remaining[idx] > 0) {
            queue[rear++] = idx;
        }
    }

    // ----- Calculate Waiting & Turnaround Time -----
    float total_wt = 0, total_tat = 0;

    cout << "\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];

        total_wt += waiting[i];
        total_tat += turnaround[i];

        cout << process[i] << "\t" << arrival[i] << "\t" << burst[i] << "\t"
             << completion[i] << "\t\t" << turnaround[i] << "\t\t" << waiting[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n << "\n";

    return 0;
}