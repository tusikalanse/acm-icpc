#include <stdio.h>
int main(void)
{
	char ch,pre=' ';
	while((ch=getchar())!=EOF)
	{
		if (pre==' '||pre=='\n') printf("%c",ch-32);
		else printf("%c",ch);
		pre=ch;
	}
	return 0;
}

