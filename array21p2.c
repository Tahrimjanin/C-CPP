#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr [n-1];

    for(int i=0;i<n-1;i++){
    scanf("%d",&arr[i]);
    }
    int sum1=0;
    for(int i =0 ;i<=n;i++){
        sum1 +=i ;
    }

    int sum2 =0 ;
   for(int i=0 ; i<n-1; i++){
        sum2 +=arr[i] ;
    }
    
    printf("%d",sum1-sum2);
}