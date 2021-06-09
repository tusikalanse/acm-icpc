#include <bits/stdc++.h>
using namespace std;

int deg[400010];

int main() {
	int n, d, k;
	long long tmp;
	scanf("%d %d %d", &n, &d, &k);
	long long pt = 1;
	tmp = k;
	if(d == 1 || k == 1) {
		pt = 2;
	}
	else if(d == 2) {
		pt = 1 + k;
	}
	else {
		pt += k;
		for(int i = 4; i <= d; i += 2) {
			tmp *= (k-1);
			pt += tmp;
			if(pt >= n) 
				break;
		}
		if(pt < n && (d & 1) == 1) {
			pt += 1LL * (tmp / k) * (k - 1);
		}
	}
	if(pt >= n && d <= n - 1) {
		puts("YES");
		int t = 3;
		queue<int> ans;
		for(int i = 1; i <= n; ++i)
			deg[i] = k;
		ans.push(1);
		n--;
		int tpd = d;
		printf("1 2\n");
		deg[1]--;
		deg[2]--;
		n--;
		ans.push(2);
		tpd--;
		while(tpd--) {
			printf("%d %d\n", ans.front(), t);
			deg[ans.front()]--;
			deg[t]--;
			ans.push(t++);
			n--;
			ans.pop();
		}
		while(!ans.empty())
			ans.pop();
		ans.push(1);
		ans.push(2);
		tpd = 1;
		while(n) {
			tpd = ans.front();
			if(tpd < d) {
				ans.push(tpd + 2);
			}
			while(deg[tpd]--) {
				if(n) {
					printf("%d %d\n", tpd, t);
					deg[t]--;
					n--;
					ans.push(t++);
				}	
			}
			ans.pop();
		}
	}
	else
		puts("NO");
	return 0;
}