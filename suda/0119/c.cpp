#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


char l1[100005];
int nxt[100005];
int len;
void getnext(char T[]){
	memset(nxt, 0, sizeof(nxt));
	int j = 0, k = -1;
	nxt[0] = -1;
	while(j < len){
		if(k == -1 || T[j] == T[k]) nxt[++j] = ++k;
		else k = nxt[k];
	}
}



int main(){
	while(~scanf("%s", l1)){
		len = strlen(l1);
		l1[len++] = '|';
		scanf("%s", l1+len);
		len = strlen(l1);
		getnext(l1);
		for(int i = 0; i<nxt[len]; i++)
			putchar(l1[i]);
		if (nxt[len]) putchar(' ');
		printf("%d\n", nxt[len]);
	}
	return 0;
}