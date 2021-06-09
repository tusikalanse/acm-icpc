#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct node {
	int l, r;
	node() : l(0), r(0){}
	bool operator<(const node &rhs) const {
		if(l < r && rhs.l >= rhs.r) 
			return false;
		if(l >= r && rhs.l < rhs.r) 
			return true;
		if(l >= r && rhs.l >= rhs.r) 
			return r < rhs.r;
		return l > rhs.l;
	}
}lis[100010];

char s[100010];
int T, n, l, r, sum;


int main() {
	scanf("%d", &T);
	while(T--) {
		LL ans = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			node tmp;
			scanf("%s", s);
			sum = l = r = 0;
			int len = strlen(s);
			for(int i = 0; i < len; ++i) {
				if(s[i] == ')' && l == 0)
					r++;
				else if(s[i] == ')') {
					l--;
					sum += 2;
				}
				else
					l++;
			}
			tmp.l = l, tmp.r = r;
			ans += sum;
			lis[i] = tmp;
		}
		sort(lis, lis + n);
		l = r = 0;
		for(int i = 0; i < n; ++i) {
			ans += min(lis[i].r, l) * 2;
			l -= min(lis[i].r, l);
			l += lis[i].l;
		}
		printf("%lld\n", ans);
	}
	return 0;
}