#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int Array[MAXN];
int oddlist[MAXN], evenlist[MAXN], cnt1 = 0, cnt2 = 0;

int main() {
	int odd = 0, n, k, p, id1 = 0, id2 = 0;
	scanf("%d%d%d", &n, &k, &p);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &Array[i]);
		if(Array[i] & 1) {
			odd++;
			oddlist[cnt1++] = Array[i];
		}
		else
			evenlist[cnt2++] = Array[i];
	}
	if(odd < k - p || ((odd - (k-p)) & 1) || ((odd-(k-p))/2 + (n-odd)) < p)
		puts("NO");
	else {
		puts("YES");
		for(int i = 1; i < k-p; i++) {
			printf("1 %d\n", oddlist[id1++]);
		}
		if(p == 0) {
			printf("%d", n - id1);
			for(int i = id1; i < cnt1; i++){
				printf(" %d", oddlist[i]);
			}
			for(int i = id2; i < cnt2; i++)
				printf(" %d", evenlist[i]);
			puts("");
		}
		else if(k-p)
			printf("1 %d\n", oddlist[id1++]);
		for(int i = 1; i < p; i++) {
			if(id1 < cnt1){
				printf("2 %d %d\n", oddlist[id1], oddlist[id1+1]);
				id1 += 2; 
			}
			else {
				printf("1 %d\n", evenlist[id2]);
				id2++;
			}
		}
		if(p) {
			printf("%d", n-id1-id2);
			for(int i = id1; i < cnt1; i++){
				printf(" %d", oddlist[i]);
			}
			for(int i = id2; i < cnt2; i++)
				printf(" %d", evenlist[i]);
			puts("");
		}
	}
	return 0;
}