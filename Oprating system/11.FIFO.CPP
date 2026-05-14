#include <bits/stdc++.h>
using namespace std;


// Function to check if a page exists in frames
int is_exist(int frames[], int frame_count, int page) {
    for (int i = 0; i < frame_count; i++) { 
        if (frames[i] == page)
            return 1; // Page found
    }
    return 0; //Page not found
}
            
int main() {
    int n, frame_count,page_faults = 0, pos = 0;

    cout << "Enter the total number of pages: ";
    cin >> n;

    cout << "Enter the number of frames: ";
    cin >> frame_count;

    int pages[n], frames[frame_count];

    cout << "Enter the page numbers (separated by space): ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i]; // input gulo page a  bosano hoise 
    }

    // Initialize all frames to -1 (empty)
    for (int i = 0; i < frame_count; i++) {
        frames[i] = -1;
    }

    cout << "\nPage Replacement Process:\n";
    for (int i = 0; i < n; i++) {
        if (!is_exist(frames, frame_count, pages[i])) {

            // If page is not in frames, replace using FIFO
            frames[pos] = pages[i];
            pos = (pos + 1) % frame_count;
            page_faults++;

            // Display current state of frames
            cout << "After inserting page " << pages[i] << ": ";
            for (int j = 0; j < frame_count; j++) {
                if (frames[j] == -1)
                    cout << "[ ] ";
                else
                    cout << "[" << frames[j] << "] ";
            }
            cout << "\n";
        }
    }

    cout << "\nTotal Page Faults = " << page_faults << "\n";

    return 0;
}
