#include <bits/stdc++.h>  
using namespace std;       

// Function to merge two sorted subarrays into one sorted array
void merge(int arr[], int left, int mid, int right) {
    int i = left;          // Index for left subarray, starts at 'left'
    int j = mid + 1;       // Index for right subarray, starts at 'mid + 1'
    int k = 0;             // Index for temporary array
    int temp[1000];        // Temporary array to store merged result
    
    // Merge two sorted parts by comparing elements
    while (i <= mid && j <= right) {  // Continue while both subarrays have elements
        if (arr[i] <= arr[j]) {       // If left element is smaller or equal
            temp[k++] = arr[i++];     // Copy left element to temp and increment both indices
        } else {                       // If right element is smaller
            temp[k++] = arr[j++];     // Copy right element to temp and increment both indices
        }
    }
    
    
    // Copy remaining elements from left part 
    while (i <= mid) {          // While left subarray still has elements
        temp[k++] = arr[i++];   // Copy remaining left elements to temp
    }
    
    // Copy remaining elements from right part (if any)
    while (j <= right) {        // While right subarray still has elements
        temp[k++] = arr[j++];   // Copy remaining right elements to temp
    }
    
    // Copy the merged result from temp back to original array
    for (i = left, k = 0; i <= right; i++, k++) {  // Loop from left to right index
        arr[i] = temp[k];       // Copy each element from temp to original array
    }
}

// Recursive function to sort array using merge sort algorithm
void mergeSort(int arr[], int left, int right) {
    if (left < right) {                    // Base case: if subarray has more than 1 element
        int mid = (left + right) / 2;      // Calculate middle index to divide array
        mergeSort(arr, left, mid);         // Recursively sort left half
        mergeSort(arr, mid + 1, right);    // Recursively sort right half
        merge(arr, left, mid, right);      // Merge the two sorted halves
    }
}

// Main function - program execution starts here
int main() {
    int arr[100], n;       // Declare array of size 100 and variable n for element count
    
    cout << "Enter number of elements: ";  // Prompt user for array size
    cin >> n;                               // Read number of elements from user
    
    cout << "Enter elements: ";  // Prompt user to enter array elements
    for (int i = 0; i < n; i++) {  // Loop n times to read elements
        cin >> arr[i];             // Read each element into array
    }
    
    mergeSort(arr, 0, n - 1);  // Call mergeSort to sort entire array from index 0 to n-1
    
    cout << "Sorted array: ";      // Display message before showing sorted array
    for (int i = 0; i < n; i++) {  // Loop through all elements
        cout << arr[i] << " ";     // Print each sorted element followed by space
    }
    cout << endl;  // Print newline at the end for clean output
    
    return 0;  // Return 0 to indicate successful program execution
}