#include<stdio.h>
int main(){
   int classes,max_roll;
   int mark[4][3];
   scanf("%d%d",&classes,&max_roll);

   for(int i=0;i<classes;i++){
    for(int j=0;j<max_roll;j++){
      scanf("%d",&mark[j][i]);
    }
   }

   for(int i=0;i<classes;i++){
    for(int j=0;j<max_roll;j++){
      if(mark[j][i]>50) printf("g ");
      else printf("b ");
    }
    printf("\n");
   }

}