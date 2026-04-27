#include <iostream>     
using namespace std; 

int main() {
    int n, tq;   // n = number of processes, tq = time quantum

    cout << "Enter the number of processes: ";
    cin >> n;    // take number of processes input

    // Declare arrays to store process data
    int process[n], arrival[n], burst[n], remaining[n], completion[n];
    int waiting[n], turnaround[n];

    // --------- Input Section ---------
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;   // assign process ID (P1, P2, P3...)

        cout << "Enter arrival time of process " << process[i] << ": ";
        cin >> arrival[i];    // input arrival time

        cout << "Enter burst time of process " << process[i] << ": ";
        cin >> burst[i];      // input burst time

        remaining[i] = burst[i];   // initially remaining time = burst time
        completion[i] = 0;         // completion time initially 0
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;   // input time quantum

    int time = 0;       // current time in CPU
    int completed = 0;  // number of completed processes

    // --------- Hybrid SRTF + Time Quantum Scheduling ---------
    while (completed < n) {   // loop until all processes finish
        int min_index = -1;       // store index of selected process
        int min_remaining = 9999; // large value to find minimum

        // Find process with shortest remaining time among arrived ones
        for (int i = 0; i < n; i++) {
            // condition:
            // 1. process has arrived
            // 2. still has remaining time
            // 3. has smaller remaining time than current minimum
            if (arrival[i] <= time && remaining[i] > 0 && remaining[i] < min_remaining) {
                min_remaining = remaining[i]; // update shortest time
                min_index = i;                // store its index
            }
        }

        // If no process has arrived yet
        if (min_index == -1) {
            int next_arrival = 9999;

            // find next process arrival time
            for (int i = 0; i < n; i++) {
                if (arrival[i] > time && arrival[i] < next_arrival)
                    next_arrival = arrival[i];
            }

            time = next_arrival;  // jump time forward
            continue;             // restart loop
        }

        // Decide execution time:
        // either full quantum or remaining time (whichever is smaller)
        int exec_time = (remaining[min_index] > tq) ? tq : remaining[min_index];

        remaining[min_index] -= exec_time; // reduce remaining time
        time += exec_time;                 // increase current time

        // If process finishes execution
        if (remaining[min_index] == 0) {
            completion[min_index] = time; // store completion time
            completed++;                 // increase completed count
        }
    }

    // --------- Calculate Waiting & Turnaround Time ---------
    float total_wt = 0, total_tat = 0;

    cout << "\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";

    for (int i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arrival[i]; // TAT = CT - AT
        waiting[i] = turnaround[i] - burst[i];      // WT = TAT - BT

        total_wt += waiting[i];     // sum of waiting time
        total_tat += turnaround[i]; // sum of turnaround time

        // print each process details
        cout << process[i] << "\t" << arrival[i] << "\t" << burst[i] << "\t"
             << completion[i] << "\t\t" << turnaround[i] << "\t\t" << waiting[i] << endl;
    }

    // Print average times
    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n << endl;

    return 0; // end of program
}