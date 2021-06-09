#include <stdio.h>
#include <string.h>
int main(void)
{
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int a=0,b=0,c=0,d=0;
		char what[53];
		scanf("%s",what);
		int l=strlen(what);
		if (l<8||l>16)
			printf("NO\n");
		else
		{
			for(int i=0;i<l;i++)
			{
				if(what[i]>='A'&&what[i]<='Z')
					a=1;
				else if(what[i]>='a'&&what[i]<='z')
					b=1;
				else if(what[i]>='0'&&what[i]<='9')
					c=1;
				else if(what[i]=='~'||what[i]=='!'||what[i]=='@'||what[i]=='#'||what[i]=='$'||what[i]=='%'||what[i]=='^')
					d=1;
				if((a+b+c+d)>=3)
				{	
					printf("YES\n");
					break;
				}
			}
			if((a+b+c+d)<3)
				printf("NO\n");
		}
	}
	return 0;
}
