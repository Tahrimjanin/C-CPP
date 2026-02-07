#include<bits/stdc++.h>
using namespace std;


int main(){
  int t;
  int sum=0;
  cin>>t;
  while(t--){
   string s;
    cin>>s;
    
    int first = s[0]-'0' ;
    int last = s[s.size()- 1 ] - '0';
    int sum = first + last ;

    cout<<"Sum = "<<sum<<endl;
   
 
  }
}
