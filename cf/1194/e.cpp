#include <bits/stdc++.h>
using namespace std;

const int N = 5010;

int n;
struct line {
	int x1, y1, x2, y2;
	void adjust() {
		x1 += N;
		y1 += N;
		x2 += N;
		y2 += N;
		if(x1 > x2)
			swap(x1, x2);
		if(y1 > y2)
			swap(y1, y2);
	}
	bool operator<(const line &rhs) const {
		if(x1 == x2) 
			return x1 < rhs.x1;
		return y1 < rhs.y1;
	}
}a[N];
vector<line> hor, ver;
vector<pair<int, int>> out[N * 2];
int now;
long long ans;

int c[2 * N];
void add(int pos, int val) {
	for(; pos < N * 2; pos += pos & -pos)
		c[pos] += val;
}

int sum(int pos) {
	int ans = 0;
	for(; pos; pos -= pos & -pos)
		ans += c[pos];
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
		a[i].adjust();
		if(a[i].y1 == a[i].y2) {
			hor.push_back(a[i]);
		}
		else {
			ver.push_back(a[i]);
			out[a[i].y2].push_back(make_pair(a[i].x1, a[i].y1));
		}
	}
	sort(hor.begin(), hor.end());
	sort(ver.begin(), ver.end());
	for(int i = 0; i < hor.size(); ++i) {
		memset(c, 0, sizeof(c));
		//cout << "horline " << hor[i].y1 << " " << hor[i].x1 << " " << hor[i].x2 << endl;
		now = hor[i].y1 + 1;
		for(int j = 0; j < ver.size(); ++j) {
			if(ver[j].y1 <= hor[i].y1 && ver[j].y2 > hor[i].y1 && ver[j].x1 >= hor[i].x1 && ver[j].x1 <= hor[i].x2) 
				add(ver[j].x1, 1);
		}
		for(int j = i + 1; j < hor.size(); ++j) {
			if(hor[i].y1 == hor[j].y1) continue;
		//cout << "calcing " << hor[j].y1 << " " << hor[j].x1 << " " << hor[j].x2 << endl;
			while(now < hor[j].y1) {
				for(auto k: out[now]) {
					if(k.first >= hor[i].x1 && k.first <= hor[i].x2 && k.second <= hor[i].y1)
						add(k.first, -1);
				}
				now++;
			}
			if(hor[j].x1 >= hor[i].x2 || hor[j].x2 <= hor[i].x1)
				continue;
			int cnt = sum(hor[j].x2) - sum(hor[j].x1 - 1);
			//cout << "cnt = " << cnt << endl;
			ans += 1LL * cnt * (cnt - 1) / 2;
		}
	}
	printf("%lld\n", ans);
	return 0;
}