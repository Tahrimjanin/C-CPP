#include <stdio.h>
int main()
{
    int test_case,a[11];
 
    scanf("%d",&test_case);
    for(int i=0; i<test_case; i++)
    {
        for(int j=0; j<10; j++)
        {
            scanf("%d",&a[j]);
        }
 
        if(a[8]>=a[0] && a[8]<=a[2] && a[9]>=a[1] && a[9]<=a[7])
            printf("1\n");
        else printf("0\n");
    }
 
    return 0;
}