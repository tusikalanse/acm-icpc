#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

struct node {
	int typ, rnk;
	bool operator < (const node &rhs) {
		if(typ == rhs.typ)
			return rnk < rhs.rnk;
		else
			return typ < rhs.typ;
	}
}a[100010];


int main() {
	int T, n, m, id;
	char ch[10], r;
	scanf("%d", &T);
	while(T--) {
		id = 0;
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; ++i) {
			scanf("%s", ch);
			if(ch[0] == 'W') {
				id = i;
			}
			else if(ch[0] == 'C') {
				a[i].typ = 1;
				scanf("%d", &a[i].rnk);
			}
			else if(ch[0] == 'B') {
				a[i].typ = 2;
				scanf("%d", &a[i].rnk);
			}
			else {
				a[i].typ = 3;
				scanf("%d", &a[i].rnk);
			}
		}
		if(id == 0) {
			if(n == 1) {
				printf("%d\n", 3 * m);
			}
			else if(a[1] < a[2]) {
				printf("%d\n", 3 * m - n + 1);
			}
			else 
				puts("1");
		}
		else {
			if(id > 2 && n >= 3 && a[2] < a[1]) {
				puts("1");
			}
			else if(id == 2 && n >= 3) {
				printf("%d\n", (a[id+1].typ - a[id-1].typ) * m + a[id+1].rnk - a[id-1].rnk);
			}
			else if(id == 2 && n == 2) {
				printf("%d\n", m * (3 - a[n-1].typ) + m - a[n-1].rnk + 1);
			}
			else if(id == 1) {
				if(n == 1)
					printf("%d\n", 3 * m);
				else 
					printf("%d\n", m * (a[2].typ - 1) + a[2].rnk - 1);
			}
			else if(id == n) {
				if(n == 1)
					printf("%d\n", 3 * m);
				else
					printf("%d\n", m * (3 - a[n-1].typ) + m - a[n-1].rnk);
			}
			else {
				printf("%d\n", (a[id+1].typ - a[id-1].typ) * m + a[id+1].rnk - a[id-1].rnk - 1);
			}
		}
	}
	return 0;
}
