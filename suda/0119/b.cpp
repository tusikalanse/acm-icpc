#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


int nxt[1005];
char S[1005], T[1005];

void getnext(char T[]){
	memset(nxt, 0, sizeof(nxt));
	int j = 0, k = -1, l = strlen(T);
	nxt[0] = -1;
	while(j < l){
		if(k == -1 || T[j] == T[k]) nxt[++j] = ++k;
		else k = nxt[k];
	}
}

int kmp(char S[], char T[]){
	int i = 0, j = 0, cnt = 0, m = strlen(T), l = strlen(S);
	getnext(T);
	while(i < l){
		if (j == -1 || S[i] == T[j]) i++,j++;
		else j = nxt[j];
		if (j == m){
			cnt++;
			j = 0;
		}
	}
	return cnt;
}

int main(){
	while(scanf("%s", S) && S[0] != '#' && scanf("%s", T)){
		printf("%d\n", kmp(S, T));
	}


}

