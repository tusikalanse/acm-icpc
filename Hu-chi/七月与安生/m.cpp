#include <bits/stdc++.h>
using namespace std;

bool vis[50010];

int main() {
	mt19937 mt_rand(time(NULL));
	int n, st, x;
	int mmax, id, nxt, val;
	scanf("%d%d%d", &n, &st, &x);
	printf("? %d\n", st);
	fflush(stdout);
	scanf("%d%d", &mmax, &nxt);
	if(mmax >= x) {
		printf("! %d\n", mmax);
		fflush(stdout);
		return 0;
	}
	nxt = st;
	if(n < 1900) {
		while(true) {
			printf("? %d\n", nxt);
			fflush(stdout);
			scanf("%d%d", &mmax, &nxt);
			if(mmax >= x) {
				printf("! %d\n", mmax);
				fflush(stdout);
				return 0;
			}
			if(nxt == -1) {
				printf("! -1");
				fflush(stdout);
				return 0;
			}
		}
	}
	id = st;
	for(int i = 0; i < 800; ++i) {
		int tt;
		do {
			tt = mt_rand() % n + 1;
		} while(vis[tt]);
		vis[tt] = 1;
		printf("? %d\n", tt);
		fflush(stdout);
		scanf("%d%d", &val, &nxt);
		if(val == x) {
			printf("! %d\n", x);
			fflush(stdout);
			return 0;
		}
		if(val < x && val > mmax) {
			mmax = val;
			id = tt;
		}
		if(val < x && nxt == -1) {
			printf("! -1\n");
			fflush(stdout);
			return 0;
		}
	}
	nxt = id;
	for(int i = 0; i < 800; ++i) {
		printf("? %d\n", nxt);
		fflush(stdout);
		scanf("%d%d", &mmax, &nxt);
		if(mmax >= x) {
			printf("! %d\n", mmax);
			fflush(stdout);
		 	return 0;
		}
		if(nxt == -1) {
			printf("! -1\n");
			fflush(stdout);
			return 0;
		}
	}
	cout << "! -2" << endl;
	return 0;
}