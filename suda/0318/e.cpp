#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int ans[1000006];
char A[1000006], B[1000006];

int main(){
	int t, ida, idb, mmax, cas = 0;
	char ch;
	scanf("%d", &t);
	while(t--){
		int cnt = 0, digits = 0;
		scanf("%s%s", A, B);
		digits = strlen(A);
		int a[10] = {0}, b[10] = {0};
		for(int i = 0; i < digits; i++){
			a[A[i] - '0']++;
			b[B[i] - '0']++;
		}
		if(digits == 1){
			printf("Case #%d: %d\n", ++cas, (A[0] + B[0] - '0' - '0') % 10);
			continue;
		}
		mmax = -1;
		for(int i = 1; i<=9; i++){
			for(int j = 1; j<=9; j++){
				if(a[i] && b[j] && (i + j) % 10 > mmax){
					ida = i;
					idb = j;
					mmax = (i + j) % 10;
				}
			}
		}
		a[ida]--;
		b[idb]--;
		ans[cnt++] = mmax;
		for(int p = 9; p >= 0; p--){
			for(int i = 0; i<=9; i++){
				if(a[i]){
					if(i <= p){
						int j = p-i;
						int k = min(a[i], b[j]);
						a[i] -= k;
						b[j] -= k;
						while(k--)
							ans[cnt++] = p;
					}
					else{
						int j = p + 10 - i;
						if(j > 9) continue;
						int k = min(a[i], b[j]);
						a[i] -= k;
						b[j] -= k;
						while(k--)
							ans[cnt++] = p;
					}
				}
			}
		}
		printf("Case #%d: ", ++cas);
		int s = 0;
		while(s < cnt-1 && ans[s] == 0)s++;
		for(int i = s; i<digits; i++) printf("%d", ans[i]);
		puts("");
	}
	return 0;
}
