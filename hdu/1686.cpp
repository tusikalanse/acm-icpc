#include <cstring>
#include <cstdio>
#include <algorithm>


int nxt[1000006], T[1000006], W[10006];
void getnext(char T[]){
	memset(nxt, 0, sizeof(nxt));
	int j = 0, k = -1, l = strlen(T);
	nxt[0] = -1;
	while(j < l){
		if(k == -1 || T[j] == T[k]) nxt[++j] = ++k;
		else k = nxt[k];
	}
}

int kmp(char T[], char W[]){
	int i = 0, j = 0, cnt = 0, m = strlen(W), l = strlen(T);
	getnext(T);
	while(i < l){
		if (j == -1 || 
		
		
		
		
	}
	
	
	
	
}
