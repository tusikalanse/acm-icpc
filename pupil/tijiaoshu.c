#include <stdio.h>
int err[100005]={0};
int main(void)
{
	int n, m, com, a, b, out, i;
	scanf("%d %d", &n, &m);
	for (i = 0; i<n; i++)
		scanf("%d", &err[i]);
	while(m--)
	{
		scanf("%d%d%d", &com, &a, &b);
		if (com==1)
		{
			for(i=a-1;i<b;i++)
			err[i]++;
		}
		else
		{
			out = 0;
			for(i=a-1;i<b;i++) out+=err[i];
			printf("%d\n", out);
		}
	}
	return 0;
}

