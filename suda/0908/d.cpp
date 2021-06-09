#include <bits/stdc++.h>
using namespace std;


int T, n, m, s, e, k, t, u, v, w, ans;
int head[1010], pnt[10010], val[10010], nxt[10010], cnt, dis[1010], times[1010];
int opphead[1010], opppnt[10010], oppval[10010], oppnxt[10010], oppcnt;
struct node {
	int dis, id;
	bool operator<(const node &rhs) const {
		return dis > rhs.dis;
	}
};

struct A_star_node {
	int id, h;
	bool operator<(const A_star_node &rhs) const {
		return dis[id] + h > dis[rhs.id] + rhs.h;
	}
};

void add(int x, int y, int v) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	val[cnt] = v;
	head[x] = cnt++;
}

void oppadd(int x, int y, int v) {
	opppnt[oppcnt] = y;
	oppnxt[oppcnt] = opphead[x];
	oppval[oppcnt] = v;
	opphead[x] = oppcnt++;
}

void dijk(int st) {
	memset(dis, 0x3f, sizeof(dis));
	dis[st] = 0;
	priority_queue<node> pq;
	pq.push({0, st});
	while(!pq.empty()) {
		node tmp = pq.top(); pq.pop();
		if(dis[tmp.id] < tmp.dis) continue;
		for(int i = opphead[tmp.id]; ~i; i = oppnxt[i]) {
			int j = opppnt[i];
			if(dis[j] > tmp.dis + oppval[i]) {
				dis[j] = tmp.dis + oppval[i];
				pq.push({dis[j], j});
			}
		}
	}
	return;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		cnt = oppcnt = 0;
		for(int i = 1; i <= n; ++i) {
			head[i] = opphead[i] = -1;
			times[i] = 0;
		}
		priority_queue<A_star_node> pq;
		ans = 0x3f3f3f3f;
		scanf("%d%d%d%d", &s, &e, &k, &t);
		for(int i = 1; i <= m; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			oppadd(v, u, w);
		}
		dijk(e);
		pq.push({s, 0});
		while(!pq.empty()) {
			A_star_node tmp = pq.top();
			pq.pop();
			times[tmp.id]++;
			if(tmp.id == e && times[tmp.id] == k) {
				ans = tmp.h;
				break;
			}
			if(times[tmp.id] > k) continue;
			if(dis[tmp.id] + tmp.h > t) break;
			for(int i = head[tmp.id]; ~i; i = nxt[i]) {
				pq.push({pnt[i], tmp.h + val[i]});
			}
		}
		if(ans > t) 
			puts("Whitesnake!");
		else
			puts("yareyaredawa");
	}
	return 0;
}