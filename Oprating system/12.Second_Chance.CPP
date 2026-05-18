#include <bits/stdc++.h>
using namespace std;

// Function to check if a page exists in frames
int is_exist(int frames[], int frame_count, int page) {
    for (int i = 0; i < frame_count; i++) {
        if (frames[i] == page)
            return i; // Return position if page found
    }
    return -1; // Page not found
}

int main() {
    int n, frame_count, pagefault = 0;
    int pointer = 0;

    cout << "Enter the total number of pages: ";
    cin >> n;

    cout << "Enter the number of frames: ";
    cin >> frame_count;

    int page[n], frames[frame_count], reference[frame_count];

    cout << "Enter the page numbers (separated by space): ";
    for (int i = 0; i < n; i++) {
        cin >> page[i];
    }

    // Initialize all frames and reference bits
    for (int i = 0; i < frame_count; i++) {
        frames[i] = -1;
        reference[i] = 0;
    }
cout << "\nSecond Chance Page Replacement Process:\n"; // Second Chance algorithm শুরু হচ্ছে প্রিন্ট করো

for (int i = 0; i < n; i++) { // প্রতিটি page একে একে চেক করো

    int pos = is_exist(frames, frame_count, page[i]); // এই page টি কি এখন frame এ আছে? থাকলে কোন position এ?

    if (pos != -1) { // page টি frame এ পাওয়া গেছে (Page Hit)

        reference[pos] = 1; // Second Chance দিলাম → reference bit = 1 করে দাও

    } else { // page টি frame এ নেই (Page Fault)

        while (reference[pointer] == 1) { // pointer যেখানে আছে সেখানে reference bit 1?
            reference[pointer] = 0;       // হ্যাঁ → Second Chance শেষ, bit 0 করে দাও
            pointer = (pointer + 1) % frame_count; // পরের frame এ যাও, শেষে গেলে আবার শুরুতে আসো
        }
        // এখন pointer এমন frame এ আছে যার reference bit = 0 → এটাকে replace করো

        frames[pointer] = page[i];   // পুরোনো page সরিয়ে নতুন page রাখো
        reference[pointer] = 0;      // নতুন page এর reference bit = 0 দিয়ে শুরু করো
        pointer = (pointer + 1) % frame_count; // pointer কে পরের frame এ নিয়ে যাও
        pagefault++;                 // Page Fault এর count বাড়াও
    }

        // Display frames
        cout << "After inserting page " << page[i] << ": ";
        for (int j = 0; j < frame_count; j++) {
            if (frames[j] == -1)
                cout << "[ ] ";
            else
                cout << "[" << frames[j] << "] ";
        }
        cout << "\n";
    }

    cout << "\nTotal Page Faults = " << pagefault << "\n";

    return 0;
}