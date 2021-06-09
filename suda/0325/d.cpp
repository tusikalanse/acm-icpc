#include <bits/stdc++.h>
using namespace std;

struct node
{
	int l, r, t, id;
	void init() {
		l = r = t = id = 0;
	}
	bool operator < (const node &rhs) const {
		if(t == rhs.t)
			return r - l < rhs.r - rhs.l;
		return
			t > rhs.t;
	}
}num[1000005];

int main() {
	int n, a;
	scanf("%d", &n);
	for(int i = 1; i <= 1000005; i++) {
		num[i].init();
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a);
		if(num[a].t == 0)
			num[a].l = i;
		num[a].r = i;
		num[a].t++;
		num[a].id = a;
	}
	sort(num + 1, num + 1 + n);
	printf("%d %d\n", num[1].l, num[1].r);
	return 0;
}