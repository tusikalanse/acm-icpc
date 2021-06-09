#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		int a=0,e=0,i=0,o=0,u=0;
		char ch;
		while((ch=getchar())!='\n')
		{
			if(ch=='a') a++;
			else if(ch=='e') e++;
			else if(ch=='i') i++;
			else if(ch=='o') o++;
			else if(ch=='u') u++;
		}
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a,e,i,o,u);
		if(n) printf("\n");
	}
	return 0;
}

