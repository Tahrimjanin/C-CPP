#include<bits/stdc++.h>
using namespace std ;

int main(){
  int t;
  cin>>t;
  cin.ignore(); 

  while(t--){
   int count =0;
   int num ;
   string s;
   getline(cin, s);
   stringstream ss(s);


  while (ss >> num) {
            count++;
        }
         cout << count  << endl; 
  }
 
}
