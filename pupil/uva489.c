#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char ans[100], gu[100];
int chance, left, win, lose;
void guess(char ch);


int main(void)
{
	int rnd;
	while(scanf("%d", &rnd) && ~rnd && scanf("%s%s", ans, gu)){
		printf("Round %d\n", rnd);
		left = strlen(ans);
		win = lose = 0;
		chance = 7;
		for (int i = 0; i < strlen(gu); i++){
			guess(gu[i]);
			if(win || lose) break;
			}
		if (win) puts("You win.");
		else if (lose) puts("You lose.");
		else puts("You chickened out.");
	}



return 0;
}


void guess(char ch)
{
	int wrong = 1;
	for(int i = 0; i<strlen(ans); i++)
	if (ans[i] == ch){ left--; ans[i] = ' ' ; wrong = 0;}
	if(wrong) chance--;
	if(!chance) lose = 1;
	if(!left) win = 1;		
	
}
