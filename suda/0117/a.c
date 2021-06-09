#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char list[1000][300];
int main(void)
{
	int count, i;
	char *temp;
	char s[100000];
	while(gets(s)){
		count = 0;
		if(!strcmp(s, "#")) break;
		temp = strtok(s, " ");
		for(i = 0; temp; i++)
		{
			strcpy(list[i], temp);
			temp = strtok(NULL, " ");
		}
		for(int k=0;k<i;k++)
		{
			for(int j=k+1;j<=i;j++)
			{
				if(strcmp(list[k],list[j])==0)
				{
					count++;
					break;
				}
			}
		}
		printf("%d\n", i-count);
	}
	return 0;
}
