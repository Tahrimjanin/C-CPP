#include<bits/stdc++.h>
using namespace std ;
int main(){
   int n ;
   scanf("%d",&n);

   int b[n];

for(int i=0;i<n;i++){
   scanf("%d",&b[i]);}

for(int i=n-1;i>=0;i--){
   printf("%d ",b[i]);}
}