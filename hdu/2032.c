#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void yanghui(int n);
int main(void)
{
    int n;
    while(~scanf("%d",&n))
        yanghui(n);
    return 0;
}
void yanghui(int n)
{
    int *a,*b;
    a=(int*)malloc(n*sizeof(int));
    b=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        a[i]=b[i]=0;
    a[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i==j)
                printf("%d",a[j]);
            else
                printf("%d ",a[j]);
        }
        for(int j=0;j<=i;j++)
        {
            b[j]=a[j];
        }
        for(int j=0;j<=i+1;j++)
        {
            if(j==0||j==i+1)
                a[j]=1;
            else
                a[j]=b[j]+b[j-1];
        }
        printf("\n");
    }
    printf("\n");
}
