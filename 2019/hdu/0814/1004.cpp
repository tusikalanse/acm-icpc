#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
using namespace std;

int n, m, f, T;
vector<pair<int, int>> ans;

pair<int, int> p23[6] = {mp(0, 0), mp(1, 1), mp(0, 2), mp(1, 0), mp(0, 1), mp(1, 2)};
pair<int, int> p24[8] = {mp(0, 0), mp(1, 1), mp(0, 3), mp(1, 2), mp(0, 1), mp(1, 0), mp(0, 2), mp(1, 3)};
pair<int, int> p33[9] = {mp(0, 0), mp(2, 1), mp(0, 2), mp(1, 1), mp(2, 0), mp(1, 2), mp(1, 0), mp(0, 1), mp(2, 2)};
pair<int, int> p25[10] = {mp(0, 0), mp(0, 2), mp(0, 4), mp(1, 3), mp(1, 1), mp(0, 3), mp(0, 1), mp(1, 0), mp(1, 2), mp(1, 4)};
pair<int, int> p34[12] = {mp(0, 0), mp(1, 2), mp(1, 0), mp(2, 1), mp(0, 2), mp(2, 0), mp(0, 1), mp(2, 2), mp(1, 3), mp(1, 1), mp(0, 3), mp(2, 3)};
pair<int, int> p35[15] = {mp(0, 0), mp(2, 1), mp(0, 2), mp(1, 1), mp(2, 0), mp(1, 2), mp(1, 0), mp(0, 1), mp(2, 2), mp(0, 3), mp(1, 4), mp(2, 3), mp(0, 4), mp(1, 3), mp(2, 4)};

void process(int dx, int dy, int f, int sz, pair<int, int> a[]) {
	if(f) {
		for(int i = sz - 1; ~i; --i)
			ans.push_back(mp(a[i].X + dx, a[i].Y + dy));
	}
	else {
		for(int i = 0; i < sz; ++i) 
			ans.push_back(mp(a[i].X + dx, a[i].Y + dy));
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		f = 0;
		ans.clear();
		if(n > m) {
			swap(n, m);
			f ^= 1;
		}
		if(n == 1 && m == 1) {
			puts("YES");
			printf("1 1\n");
			continue;
		}
		if(n == 1) {
			puts("NO");
			continue;
		}
		if(n == 2 && m == 2) {
			puts("NO");
			continue;
		}
		if(n == 2 && m == 5) {
			process(1, 1, 0, 10, p25);
		}
		else if(n == 3 && m == 5) {
			process(1, 1, 0, 15, p35);
		}
		else if(n == 4 && m == 5) {
			process(1, 1, 0, 10, p25);
			process(3, 1, 1, 10, p25);
		}
		else if(n == 5 && m == 5) {
			process(1, 1, 0, 15, p35);
			process(4, 1, 1, 10, p25);
		}
		else {
			if(n & 1) {
				int p, q;
				for(p = 0; ; p++) {
					q = (m - 3 * p) / 4;
					if(3 * p + 4 * q == m)
						break;
				}
				int x = 1, y = 1;
				for(int i = 1; i <= p; ++i) {
					x = 1; y = 3 * (i - 1) + 1;
					process(x, y, 0, 9, p33);
				}
				for(int i = 1; i <= q; ++i) {
					x = 1; y = 3 * p + 4 * (i - 1) + 1;
					process(x, y, 0, 12, p34);
				}
				for(x = 5; x <= n; x += 4) {
					for(int i = q; i; --i) {
						y = 3 * p + 4 * (i - 1) + 1;
						process(x - 1, y, 1, 8, p24);
					}
					for(int i = p; i; --i) {
						y = 3 * (i - 1) + 1;
						process(x - 1, y, 1, 6, p23);
					}
					if(x + 2 <= n) {
						for(int i = 1; i <= p; ++i) {
							y = 3 * (i - 1) + 1;
							process(x + 1, y, 0, 6, p23);
						}
						for(int i = 1; i <= q; ++i) {
							y = 3 * p + 4 * (i - 1) + 1;
							process(x + 1, y, 0, 8, p24);
						}
					}
				}
			}
			else {
				int p, q;
				for(p = 0; ; p++) {
					q = (m - 3 * p) / 4;
					if(3 * p + 4 * q == m)
						break;
				}
				int x = 1, y = 1;
				for(; x <= n; x += 4) {
					for(int i = 1; i <= p; ++i) {
						y = 3 * (i - 1) + 1;
						process(x, y, 0, 6, p23);
					}
					for(int i = 1; i <= q; ++i) {
						y = 3 * p + 4 * (i - 1) + 1;
						process(x, y, 0, 8, p24);
					}
					if(x + 3 <= n) {
						for(int i = q; i; --i) {
							y = 3 * p + 4 * (i - 1) + 1;
							process(x + 2, y, 1, 8, p24);
						}
						for(int i = p; i; --i) {
							y = 3 * (i - 1) + 1;
							process(x + 2, y, 1, 6, p23);
						}
					}
				}
			}
		}
		puts("YES");
		if(f) {
			for(auto &t: ans) {
				printf("%d %d\n", t.Y, t.X);
			}
		}
		else {
			for(auto &t: ans) {
				printf("%d %d\n", t.X, t.Y);
			}
		}
	}
	return 0;
}