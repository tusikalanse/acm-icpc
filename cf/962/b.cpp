#include <bits/stdc++.h>
using namespace std;

char lst[200010];

int main() {
	int n, a, b, ans = 0;
	scanf("%d %d %d", &n, &a, &b);
	scanf("%s", &lst[1]);
	int flag = 0;
	for(int i = 1; i <= n; i++) {
		if(lst[i] == '*')
			flag = 0;
		else {
			if(flag == 0) {
				if(a > b && a > 0) {
					a--;
					flag = 1;
					ans++;
				}
				else if(b > 0){
					b--;
					flag = 2;
					ans++;
				}
			}
			else if (flag == 1) {
				if(b > 0) {
					b--;
					ans++;
					flag = 2;
				}
				else
					flag = 0;
			}
			else if(flag == 2) {
				if(a > 0) {
					a--;
					flag = 1;
					ans++;
				}
				else
					flag = 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}