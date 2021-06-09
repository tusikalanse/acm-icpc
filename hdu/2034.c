#include <stdio.h>

int main(void)
{
	int n, m, count, flag;
	int a[101], b[101], c[101];
	while(~scanf("%d %d", &n, &m)&&(n||m))
	{
		count = 0;
		for(int i=0;i<n;i++) scanf("%d", &a[i]);
		for(int i=0;i<m;i++) scanf("%d", &b[i]);
		for(int i=0;i<n;i++)
		{
			flag=1;
			for(int j=0;j<m;j++)
				if (a[i]==b[j])
				{
					flag = 0;
					break;
				}
			if (flag)
			c[count++]=a[i];
		}
		if (count)
		{
			for(int i=0;i<count-1;i++)
				for(int j=i+1;j<count;j++)
					if(c[i]>c[j])
						c[i]^=c[j]^=c[i]^=c[j];
			for(int i=0;i<count;i++)
			printf("%d ", c[i]);
			puts("");
		}
		else printf("NULL\n");
		}
	return 0;
}

