///Write a C/C++ program to read N inputted numbers randomly, where N is inputted from keyboard. 


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
 void main(){
    int i ,n,data[10000];
    srand(time(NULL));

    printf("Enter the numbers:") ;
    scanf("%d",&n);

    for(i=0 ;i<n;i++){
        data[i]= (rand()%1000) ;
    }

    printf("\n The %d Number are follow:\n", n);
  
    for(i=0;i<n;i++){
        printf("%5d", data[i]);
    }
 }