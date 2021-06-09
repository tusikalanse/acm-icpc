#include <bits/stdc++.h>
using namespace std;

const int N = 510;

int n, k, a[N], b[N], l[N], r[N];

bool judge() {
	int pre = 1, p = 1, tot = 0;
	for(int i = 1; i <= k; ++i) {
		tot = 0;
		p = pre;
		while(p <= n && tot < b[i])
			tot += a[p++];
		if(tot != b[i])
			return false;
		int t = a[pre], f = 0;
		for(int j = pre; j < p; ++j) {
			f |= a[j] != t;
		}
		if(f == 0 && pre != p - 1)
			return false;
		l[i] = pre;
		r[i] = p - 1;
		pre = p;
	}
	return p == n + 1;
}

void print() {
	int tot = 0;
	for(int i = 1; i <= k; ++i) {
		if(l[i] == r[i]) continue;
		tot = i - 1;
		int ml = l[i], mr = l[i];
		for(int j = l[i]; j <= r[i]; ++j) {
			if(a[j] > a[ml])
				ml = j;
		}
		mr = ml;
		while(a[mr] == a[mr + 1]) mr++;
		if(ml != l[i]) {
			for(int j = ml; j - 1 >= l[i]; --j)
				printf("%d L\n", tot + j - l[i] + 1);
			for(int j = ml; j + 1 <= r[i]; ++j)
				printf("%d R\n", 1 + tot);
		}
		else {
			for(int j = mr; j + 1 <= r[i]; ++j)
				printf("%d R\n", tot + mr - l[i] + 1);
			for(int j = mr; j - 1 >= l[i]; --j)
				printf("%d L\n", tot + j - l[i] + 1);
		}
	}
}


int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &k);
	for(int i = 1; i <= k; ++i) {
		scanf("%d", &b[i]);
	}
	if(judge()) {
		puts("YES");
		print();
	}
	else
		puts("NO");
	return 0;
}