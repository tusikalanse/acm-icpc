#include <stdio.h>
#include <math.h>
int main(void)
{
	int n,x1,y1,x2,y2,temp;
	const double sqrt_2=sqrt(2);
	double output;
	scanf("%d",&n);
	while(n--)
	{
		output=0;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if((x1+y1)!=(x2+y2))	
		{
			if((x1+y1)>(x2+y2))
			{
				temp=x1;
				x1=x2;
				x2=temp;
				temp=y1;
				y1=y2;
				y2=temp;
			}
			output+=sqrt_2*(x2+y1);
			for(int i=2*(x1+y1);i<=2*(x2+y2-1);i++)
				output+=sqrt(pow((i+1)/2,2)+pow((i+2)/2,2));
		}
		else
			output=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
		printf("%.3lf\n",output);
	}
	return 0;
}

