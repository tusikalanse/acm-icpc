#include <stdio.h>

int main()
{
	unsigned long long list[21]={1,0,1};
	for(int i=3;i<=21;i++)
		list[i]=(i-1)*(list[i-1]+list[i-2]);
	int t, n, m;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		unsigned long long out = 1;
		for(int i = 0; i<m; i++)
		 out = out*(n-i)/(i+1); 
		 printf("%llu\n", out*list[m]);
	}
	return 0;
}

