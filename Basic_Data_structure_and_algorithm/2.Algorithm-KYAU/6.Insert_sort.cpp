#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[100], n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    //input array elements 
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];
    

    // insertion sort algorithm
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    
     // output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
