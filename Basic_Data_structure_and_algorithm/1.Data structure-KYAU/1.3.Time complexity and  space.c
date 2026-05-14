// Write a C/C++ program to extend the 1.2 program to find out the time complexity and space
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(){
    int i ,n,data[100000];
    srand(time(NULL));

    printf("Enter the numbers:") ;
    scanf("%d",&n);
     
    clock_t begin = clock();
    for(i=0 ;i<n;i++){
        data[i]= (rand()%100) ;
    }

    printf("\n The %d Number are follow:\n", n);
    for(i=0;i<n;i++){
        printf("%5d", data[i]);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; 
    printf("\nTotal time spend : %f Seconds",time_spent); 
}