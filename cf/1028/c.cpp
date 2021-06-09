#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL qp(LL a, LL n) {
	LL res = 1;
	while(n) {
		if(n & 1)
			res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

int n, x1, Y1, x2, y2;
int id1, id2, id3, id4;
int rec[132677][4];
int lm = -0x3f3f3f3f, rm = -lm, dm = lm, um = rm;

void find(int id) {
	int fi = 1;
	if(id == 1)
		fi++;
	int l = rec[fi][0], d = rec[fi][1], r = rec[fi][2], u = rec[fi][3];
	for(int i = fi + 1; i <= n; ++i) if(i != id) {
		l = max(l, rec[i][0]);
		d = max(d, rec[i][1]);
		r = min(r, rec[i][2]);
		u = min(u, rec[i][3]);
	}
	if(l <= r && d <= u) {
		cout << l << ' ' << d << endl;
		exit(0);
	}
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> x1 >> Y1 >> x2 >> y2;
		rec[i][0] = x1; rec[i][1] = Y1; rec[i][2] = x2; rec[i][3] = y2;
		if(x1 > lm) {
			lm = x1;
			id1 = i;
		}
		if(Y1 > dm) {
			dm = Y1;
			id2 = i;
		}
		if(x2 < rm) {
			rm = x2;
			id3 = i;
		}
		if(y2 < um) {
			um = y2;
			id4 = i;
		}
	}
	find(id1);
	find(id2);
	find(id3);
	find(id4);
	return 0;
}