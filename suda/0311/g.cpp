#include <cstdio>
#include <cstring>
using namespace std;

int t, cnt[200005][10], n, a[200005];
char s[200005];

void solve(){
	for(int i = n; i>=1; i--){
		for(int j = a[i] - 1; j >= (1==i); j--){
			int res = 0;
			for(int k = 0; k<=9; k++)
				res += cnt[i-1][k] ^ (k == j);
			if(res <= n - i){
				for(int k = 1; k<i; k++) printf("%d", a[k]);
				printf("%d", j);
				for(int k = 1; k <= n - i - res; k++) putchar('9');
				for(int k = 9; k >= 0; k--)
					if(cnt[i-1][k] ^ (k == j))
						printf("%d", k);
				puts("");
				return;
			}
		}
	}
	for(int i = 1; i <= n-2; i++) putchar('9');
	puts("");
	return;
}

int main(){
	scanf("%d", &t);
	while(t--){
		for(int k = 0; k<=9; k++)
			cnt[0][k] = 0;
		scanf("%s", s+1);
		n = strlen(s + 1);
		for (int i = 1; i <= n ; ++i)
		{
			a[i] = s[i] - '0';
		}
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= 9; j++){
				cnt[i][j] = cnt[i-1][j] ^ (a[i] == j);
			}
		}
		solve();
	}
	return 0;
}