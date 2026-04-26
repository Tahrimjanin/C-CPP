#include <bits/stdc++.h>
using namespace std;

int main(){
   int n  ;
   cout << "num of process" ;
   cin>> n;
   
   int pro[n],arr[n] ,burst[n] , completion [n], turnAr[n],wainting[n];
    int i ,j,temp ,pos,ct= 0 ;

    for (i=0 ;i<n ;i++ ){
        pro[i] = i+1 ;
        cout <<"enter AT of pro :" << pro[i] <<":" ;
        cin >>arr[i] ;
        cout <<"enter BT of pro :" << pro[i] <<":" ;
        cin >>burst[i] ;
        completion[i] = -1 ;
    }
for (i = 0 ;i<n ;i++ ) {
    pos = i ;
    for (j=i+1 ;j<n ; j++ ){
        if(arr[j] < arr[pos] ){
            pos = j ;
        }
    }
  // swap arrival 
  temp = arr[i] ;
  arr [i] = arr[pos ] ;
  arr[pos] = temp ;
// bt 
   temp = burst[i];
burst [i] =burst[pos] ;
burst[pos]= temp ;
//process id 
 
     temp = pro[i] ;
  pro [i] = pro[pos ] ;
  pro[pos] = temp ;
}

int  comp = 0 ,is_comp[n] ;
for(i=0 ;i<n;i++) is_comp[i] = 0 ;

while (comp != n ){
    int min_burst = 9999 ,index= -1 ;
    for(i=0 ;i<n ;i++ ) {
        if(arr[i] <= ct && is_comp[i]== 0){
            if(burst[i] <min_burst[i]);
                index = i ;
        }
        else if (burst[i] == min_burst && arrival[i] < arrival[index]){
            index = i ;
        }

    }

     if (index != -1) {
            comp[index] = ct + burst[index];
          turnAr[index] = comp[index] -arrival[index ] ;
            waiting[index] = turnAr[index] - burst[index];
            ct= comp[index];
            is_comd[index] = 1;
            comp++;
        } else {
            ct++;
        }



}

   

cout << "\nPro \tAt \t Burst \t Ct \tTurnAr\tWaiting \n " ;
 
 for (i = 0; i < n; i++) {
        cout << pro[i] << "\t" << arl[i] << "\t\t" << burst[i] << "\t\t"
             << comn[i] << "\t\t" << turnAr[i] << "\t\t" << waiting[i] << "\n";
    }



}