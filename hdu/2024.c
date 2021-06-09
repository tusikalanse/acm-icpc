#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		char ch;
		int flag=1;
		ch=getchar();
		if ((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||ch=='_')
		{
			while((ch=getchar())!='\n')
			{
				if (!((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9')||ch=='_')) 
				{
					printf("no\n");
					flag=0;
					break;
				}
			}
			if (flag) printf("yes\n");
		}
		else printf("no\n");
		if (ch!='\n') 
			while((ch=getchar())!='\n');
	}
	return 0;
}

