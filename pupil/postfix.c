#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int ptr = 0, move = 0;
int stack[100] = {0};
char raw[100];
char input[100];
char four[100] = {'\0'};

int main(void){
	int t = 0; 
	char ch;
	while (~scanf("%s", raw)){
		memset(four, '\0', sizeof(four));
		memset(stack, 0, sizeof(stack));
		memset(input, '\0', sizeof(input));
		for(int i = 0; i<strlen(raw); i++)
{
		ch = raw[i];
		if (ch<='9' && ch>='0') input[ptr++] = ch;
		else { input[ptr++] = ' ';
			if (ch!='(' && ch!='^')
		{
			if (move)
			{
				switch(ch)
				{
					case '-':
					case '+':
					for(--move; move>=0; move--)
					{
						if (four[move] == '(') break;
						else input[ptr++] = four[move];
					} move++; break;
					case '*':
					case '/':
					for(--move; move>=0; move--)
					{
						if (four[move] == '(' || four[move] == '+' || four[move] == '-') break;
						else input[ptr++] = four[move];
					} move++; break;
					case ')':
					for(--move; move>=0; move--)
					{
						if (four[move] == '(') {move--; break;}
						else input[ptr++] = four[move];
					} move++; break;
				}
				if (ch!=')') four[move++] = ch;
			}
			else four[move++] = ch;
		}
		else four[move++] = ch;} 		
}
		for(int j = move-1; j>=0; j--)   input[ptr++] = four[j]; 
		input[ptr++] = '\0';
		t = -1;
		move = 0;
        ptr = 0;
		while (input[move]!='\0')
			{ch = input[move++];
			if(ch<='9' && ch>='0') if(~t)t = t*10 + (int)(ch-'0'); else t = ch - '0';
			else	{
					if (~t)	{stack[ptr++] = t; t = -1;}
						switch(ch)
					{
						case '+':
							stack[ptr-2] = stack[ptr-1]+stack[ptr-2];
							ptr--;
							break;
						case '-':
							stack[ptr-2] = stack[ptr-2]-stack[ptr-1];ptr--;break;
						case '*':
							stack[ptr-2] *= stack[ptr-1];ptr--;break;
						case '/':
							stack[ptr-2] /= stack[ptr-1];ptr--;break;
						case '^': stack[ptr-2] = (int)pow(stack[ptr-2], stack[ptr-1]); ptr--; break;
						default: break;
					}
					}
			}if (~t) stack[0] = t;
		printf("%d\n", stack[0]);
		ptr = 0;
		move = 0;	
		}
	return 0;
}
