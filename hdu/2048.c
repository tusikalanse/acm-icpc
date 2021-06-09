#include <stdio.h>
int main(void)
{
	int n,m,p;
	long long t;
	double list[21]={0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for(int i=3;i<=21;i++)
		list[i]=(i-1)*(list[i-1]+list[i-2]);
	scanf("%d",&n);
	while(n--)
	{
		t=1;
		scanf("%d",&m);
		p=m;
		t*=m;
		while(--m)
			t*=m;
		printf("%.2lf%%\n",(list[p]/t)*100);
	}
	return 0;
}

