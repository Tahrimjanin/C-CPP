#include<bits/stdc++.h>
using namespace std ;

int main(){
  int t;
  cin>>t;
  cin.ignore(); 
  while(t--){
   int count =0;
   string s;
   
   getline(cin, s);

  for(int i=0; i<s.size(); i++){
    if(s[i]==' '){
    count++;
    }
  }
  cout << count + 1 << endl; 
}


}