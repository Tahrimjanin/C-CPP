#include <bits/stdc++.h>
using namespace std;
                                                                                                                                                                
int main() {
    int arr[100], n, temp;
    cout << "Enter number of elements: ";
    cin >> n;
    
    
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    // selection sort algo
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // swap the found minimum element with the first elememt 
        temp= arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}