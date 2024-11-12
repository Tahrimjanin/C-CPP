#include<bits/stdc++.h>
using namespace std ;

int main(){
 int t;
 cin>>t;
  

     unsigned long long int arr[61];
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i=2 ;i<61;i++){
    arr[i]=arr[i-1] + arr[i-2];;

    }  
    
        for(int i=0;i<t;i++){
            int n;
            cin>>n;
            cout<<"Fib("<<n<<") = "<<arr[n] <<endl;
           
    
 
}
}
