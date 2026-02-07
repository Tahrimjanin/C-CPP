#include<bits/stdc++.h>
using namespace std ;

int main(){
    int n, arr[100] , pos = -1 ,value ;
    cin>> n ;

 for (int i = 0 ;i< n ;i++) cin>> arr[i] ;
 cin>> value ;

 for(int i=0;i<n;i++){
    if(arr[i]== value){
        pos = i+1 ;
        break ;
    }
 }
     if (pos == -1) cout << "Not found";
    else cout << value << " found at position " << pos;

}