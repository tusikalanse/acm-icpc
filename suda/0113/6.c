#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str[100006];
char st[27] = {'\0'};
int main(){
	int t, k;
	scanf("%d", &t);
	while(t--){
		int sum = 0;
		scanf("%s %d", str, &k);
		for(int i = 0; i<strlen(str)+1-k; i++){
			memset(st, '\0', sizeof(st));
			for(int j = i; j<strlen(str); j++){
				int flag = 1;
				for (int u = 0; u<strlen(st); u++)
					if (st[u] == str[j]) {flag = 0; break;}
				if (flag) st[strlen(st)] = str[j];
				if (strlen(st) == k){sum += strlen(str)-j; break;}
				}
			}
			printf("%d\n", sum);
	}
	return 0;
}
