#include <stdio.h>
#include <string.h>
#include <algorithm>
int main(void)
{
	int m,n,list[505];
	scanf("%d",&m);
	while(m--)
	{
		int sum=0;
		scanf("%d",&n);
		memset(list,0,505*sizeof(int));
		for(int i=0;i<n;i++)	
			scanf("%d",&list[i]);
		sort(list,list+n);
		if (n%2)
			int mid=list[(n-1)/2];
		else
			int mid=(list[n/2]+list[(n/2)-1])/2;
		for(int i=0;i<n;i++)
			sum+=list[i];
		printf("%d\n",sum);
	}
	return 0;
}

