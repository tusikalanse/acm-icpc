#include <bits/stdc++.h>
using namespace std;

struct node {
	int a, b, c, d, e, id;
}a[100010];

int n, vis[100010], id[30], cnt;
vector<node> v;

long long ans;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d%d", &a[i].a, &a[i].b, &a[i].c, &a[i].d, &a[i].e);
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, [&](const node &i, const node &j) {return i.a > j.a;});
	for(int i = 1; i <= 5; ++i)
		id[++cnt] = a[i].id;
	sort(a + 1, a + n + 1, [&](const node &i, const node &j) {return i.b > j.b;});
	for(int i = 1; i <= 5; ++i)
		id[++cnt] = a[i].id;
	sort(a + 1, a + n + 1, [&](const node &i, const node &j) {return i.c > j.c;});
	for(int i = 1; i <= 5; ++i)
		id[++cnt] = a[i].id;
	sort(a + 1, a + n + 1, [&](const node &i, const node &j) {return i.d > j.d;});
	for(int i = 1; i <= 5; ++i)
		id[++cnt] = a[i].id;
	sort(a + 1, a + n + 1, [&](const node &i, const node &j) {return i.e > j.e;});
	for(int i = 1; i <= 5; ++i)
		id[++cnt] = a[i].id;
	sort(a + 1, a + n + 1, [&](const node &i, const node &j) {return i.id < j.id;});
	for(int i = 1; i <= cnt; ++i) {
		if(vis[id[i]]) continue;
		v.push_back(a[id[i]]);
		vis[id[i]] = 1;
	}
	cnt = v.size();
	for(int aa = 0; aa < cnt; ++aa) {
		for(int bb = 0; bb < cnt; ++bb) if(aa != bb) {
			for(int cc = 0; cc < cnt; ++cc) if(aa != cc && bb != cc) {
				for(int dd = 0; dd < cnt; ++dd) if(aa != dd && bb != dd && cc != dd) {
					for(int ee = 0; ee < cnt; ++ee) if(aa != ee && bb != ee && cc != ee && dd != ee) {
						ans = max(ans, 0LL + v[aa].a + v[bb].b + v[cc].c + v[dd].d + v[ee].e);
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}