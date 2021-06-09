#include <stdio.h>
#include <stdlib.h>

int main(){
	int t, n, m;
	int list[100006];
	scanf("%d", &t);
	while(t--){
	scanf("%d %d", &n, &m);
	for(int i = 0; i<n; i++) scanf("%d", &list[i]);
	int flag = 1, sum;
	for(int i = 0; i<n; i++){ sum = 0;
		for(int j = i; j<n; j++)
		{
			sum += list[j];
			if (sum%m == 0) { flag = 0; printf("YES\n"); break; }
		}
		if (flag == 0) break;
	}
	if (flag) printf("NO\n");
	}
	return 0;
}
