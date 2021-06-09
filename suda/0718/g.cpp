#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int vis[10];

bool check(int s) {
	while(s) {
		int dig = s % 10;
		if(vis[dig])
			return 0;
		vis[dig] = 1;
		s /= 10;
	}
	return 1;
}


bool check(int s, int t) {
	memset(vis, 0, sizeof(vis));
	int a = 5, b = 5;
	while(a--) {
		int dig = s % 10;
		if(vis[dig])
			return 0;
		vis[dig] = 1;
		s /= 10;
	}
	while(b--) {
		int dig = t % 10;
		if(vis[dig])
			return 0;
		vis[dig] = 1;
		t /= 10;
	}
	return 1;
}


int main() {
	int n, flag, up, down;
	bool first = 0;
	while(~scanf("%d", &n) && n) {
		if(first)
			puts("");
		first = 1;
		flag = 0;
		for(int a = 0; a < 10; ++a) {
			for(int b = 0; b < 10; ++b) { if(a == b) continue;
				for(int c = 0; c < 10; ++c) { if(a == c || b == c) continue;
					for(int d = 0; d < 10; ++d) { if(a == d || b == d || c == d) continue;
						for(int e = 0; e < 10; ++e) { if(a == e || b == e || c == e || d == e) continue;
							up = 10000 * a + 1000 * b + 100 * c + 10 * d + e;
							if(up % n) {
								continue;
							}
							down = up / n;
							if(check(up, down)) {
								flag = 1;
								printf("%05d / %05d = %d\n", up, down, n);
								goto out;
							}
						}
					}
				}
			}
		}
		out:;
		if(flag) {
			for(int p = up + n; p < 1e5; p += n) {
				if(p % n)
					continue;
				down = p / n;
				if(check(p, down)) {
					printf("%05d / %05d = %d\n", p, down, n);
				}
			}
		}
		if(flag == 0)
			printf("There are no solutions for %d.\n", n);
	}
	return 0;
}