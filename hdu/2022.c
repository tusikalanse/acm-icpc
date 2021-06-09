#include <stdio.h>
int abs(int x){return x>0?x:-x;}
int main(void)
{
	int m,n,i,j,row,col,out,t;
	while(scanf("%d %d",&m,&n)!=EOF)
{	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&t);
			if(i==0&&j==0)
			{
				row=col=0;
				out=t;
			}
			else if(abs(out)<abs(t))
			{
				out=t;
				row=i+1;
				col=j+1;
			}
		}
	}
	printf("%d %d %d\n",row,col,out);
}
return 0;
}
