/*
 Leetcode - 852. Peak Index in a Mountain Array
You are given an integer mountain 
array arr of length n where the values increase to a peak 
element and then decrease.Return the index of the peak 
element
Your task is to solve it in O(log(n)) time complexity.

Input: arr = [0,1,0]
Output: 1
*/

#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    vector<int> arr = {0, 1, 0};
    cout << peakIndexInMountainArray(arr) << endl;  // Output: 1
    return 0;
}

