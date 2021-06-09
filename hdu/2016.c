#include <stdio.h>
#include <stdlib.h>
int abs(int x){return x>0?x:-x;}
int main(void)
{
	int n,i,temp;
	while(scanf("%d",&n)&&n)
	{
		int *list;
		list=(int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
			scanf("%d",(list+i));
		for(i=0;i<n-1;i++)
		{
			int j;
			for(j=i+1;j<n;j++)
			{
				if(abs(list[i])<abs(list[j]))
				{
					temp=list[i];
					list[i]=list[j];
					list[j]=temp;
				}
			}
		}
		for(i=0;i<n-1;i++)
			printf("%d ",list[i]);
		printf("%d\n",list[n-1]);
	}	
	return 0;
}
