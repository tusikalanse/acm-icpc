#include <stdio.h>
int main(void)
{
	char ch='1';
	while (ch!=EOF)
	{
		char max='a';
		int i=0;
		char list[100]={'\0'};
		while((ch=getchar())!=EOF)
		{
			if(ch!='\n')
			{
				list[i]=ch;
				i++;
				if(ch>max) max=ch;
			}
			else
			{
				i=0;
				for(;list[i]!='\0';i++)
				{
					if(list[i]==max) printf("%c(max)",list[i]);
					else printf("%c",list[i]);
				}
				i=0;
				printf("\n");
				break;
			}
		}
	}			
	return 0;
}

