#include <bits/stdc++.h> 
using namespace std; 
int main()
{
    int n , arr[100] ,low= 0,high,value,mid ;

    cin>>n ;

    for (int i = 0; i<n ;i++) cin>>arr[i] ;
    cin>> value ;

    high = n - 1 ;

    while(low <=high){
        mid = low+ high / 2 ;

       if (arr[mid]== value ){
        cout<<"Found the number " <<endl;
       }
       else if (arr[mid] < value ) 
       low = mid + 1 ;
       else {
        high = mid - 1;
       }
    }
     cout << "Not found";





}