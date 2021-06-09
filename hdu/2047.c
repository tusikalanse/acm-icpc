#include <stdio.h>
int main(void)
{
   long long list[41]={0,3,8};
   int n;
   for(int i=3;i<41;i++)
       list[i]=2*list[i-1]+2*list[i-2];
   while(~scanf("%d",&n))
       printf("%lld\n",list[n]);
    return 0;
}
