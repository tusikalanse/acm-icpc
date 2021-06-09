#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int ans[N], n, a[N], cnt[N*100], unit, sum;

struct node{
	int l, r, id;
	bool operator < (const node &rhs)const{
		if (l/unit == rhs.l/unit)
			return r < rhs.r;
		else l < rhs.l;
	}
} q[N];

inline void add(int i){
	cnt[a[i]]++;
	if(cnt[a[i]] == 1) sum++;
}

inline void remove(int i){
	cnt[a[i]]--;
	if(cnt[a[i]] == 0) sum--;
}

int main(){
	int m;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a+i);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].id = i;
	}
	unit = sqrt(n);
	sort(q + 1, q+ m + 1);
	int l = 0, r = 0;
	for(int i = 1; i<=m; i++){
		while( l > q[i].l) add(--l);
		while( r < q[i].r) add(++r);
		while( l < q[i].l) remove(l++);
		while( r > q[i].r) remove(r--);
		ans[q[i].id] = sum;
	}
	for(int i = 1; i<=m; ++i) printf("%d\n", ans[i]);
	return 0;
}
