#include <bits/stdc++.h>   
using namespace std;       

int n, arr[100005], temp[100005]; 

/* for comparison cnt= 0 ;

void merge(int l, int r) {
    int mid = (l + r) / 2;   
    int i1 = l, i2 = mid + 1, j = l; 
    cnt++ ;
    while (i1 <= mid && i2 <= r)  {  

        if (arr[i1] < arr[i2])  {    
            temp[j++] = arr[i1++];
            i1++;  } 

        else {                     
            temp[j++] = arr[i2++];  
            i2++;}
        j++ ;
        }

     while (i1 <= mid) {
     cnt++;
    temp[j++] = arr[i1++];  
    }
    while (i2 <= r) {
    cnt++;
    temp[j++] = arr[i2++];  
    }

    for (int k = l; k <= r; k++) {
        arr[k] = temp[k];       
    }
}

NB: change just before  mergesort

*/

void merge(int l, int r) {
    int mid = (l + r) / 2;   // Find middle index
    int i1 = l, i2 = mid + 1, j = l; // i1 = start of left half, i2 = start of right half, j = index for temp

    // Merge the two halves into temp
    while (i1 <= mid && i2 <= r)  {   // While both halves have elements
       
        if (arr[i1] < arr[i2]) // If element in left half is smaller
        {    
            temp[j++] = arr[i1++];
            i1++;  
        } 
        else {                     // If element in right half is smaller or equal
            temp[j++] = arr[i2++];  
            i2++;
        }
        j++;
    }
    // Copy remaining elements of left half (if any)
    while (i1 <= mid) {
        temp[j++] = arr[i1++];  
    }

    // Copy remaining elements of right half (if any)
    while (i2 <= r) {
        temp[j++] = arr[i2++];  
    }

    // Copy the merged elements back to the original array
    for (int k = l; k <= r; k++) {
        arr[k] = temp[k];       
    }
}

// Recursive function to implement merge sort on arr
void mergesort(int l, int r) {
    if (l >= r) return;  // Base case: if array has 0 or 1 element, it’s already sorted
    int mid = (l + r) / 2;  // Find middle index for dividing the array

    mergesort(l, mid);// sort left half
    mergesort(mid + 1, r); // sort right half

    merge(l, r); // Merge the two sorted halves
}

int main() {

    /* if dont have any input number
    n = 0 ;
    long long =a ;
    while (cin >> a) {
        arr[n] = a ;
        n++ ;
    }

    */
    cin >> n;                  
    for (int i = 0; i < n; i++) {
        cin >> arr[i];        
    }
    mergesort(0, n - 1);       
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl;              
}


/*summary
1.arr divided into two halves recursively until each half contains a single element.
2.merge function merges two sorted halves into a single sorted array.
3.temp array is used to store the merged result temporarily.
4.finally, the sorted elements from temp are copied back to the original arr.
*/