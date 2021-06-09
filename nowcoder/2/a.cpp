#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char stack[2][103];
int main(){
	int ptr = 0, c, flag;
	while(~scanf("%s", &stack[0][0])){
		ptr = c = 0;
		memset(stack[1], '\0', sizeof(stack[1]));
		int len = strlen(stack[c]);
		int pre = 1000000;
		while(pre != len){
			ptr  = 0;
			pre = len;
			flag = 1;
			for(int i = 0; i<len; i++){
				stack[c^1][ptr] = stack[c][i];
				if(flag && ptr && stack[c^1][ptr] == stack[c^1][ptr-1]){
					flag = 0;
					if(stack[c^1][ptr] == 'o') stack[c^1][--ptr] = 'O';
					else ptr -= 2;
				}
				else flag = 1;
				ptr++;
			}
			c ^= 1;
			len = ptr;
		}
		for(int i = 0; i<ptr; i++) putchar(stack[c][i]);
		puts("");
	}
	return 0;
}
