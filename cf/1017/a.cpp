#include <bits/stdc++.h>
using namespace std;

struct node {
	int s, id;
	bool operator<(const node &rhs) {
		if(s == rhs.s)
			return id < rhs.id;
		return s > rhs.s;
	}
}l[1010];

int n, a, b, c, d;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", &a,&b,&c,&d);
		l[i].s = a+b+c+d;
		l[i].id = i;
	}
	sort(l + 1, l + n + 1);
	for(int i = 1; i <= n; ++i) {
		if(l[i].id == 1) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}