#include <bits/stdc++.h>
using namespace std;


long long pnt[100010][2];
int vis[10] = {0};
long long tmp[2];

long long dx1, dy1, dx2, dy2;
long long kx1, ky1, kx2, ky2;
int f1 = 0, f2 = 0;

bool oneline(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	return ((x1-x2)*(y1-y3) == (x1-x3)*(y1-y2));
}

void joinline(long long x1, long long y1, long long x2, long long y2) {
	if(y1 == y2) {
		f1 = 1;
	}
	else {
		f1 = -1;
		kx1 = (x1-x2);
		ky1 = (y1-y2);
	}
	dx1 = x1;
	dy1 = y1;
}

void joinline2(long long x1, long long y1, long long x2, long long y2) {
	if(y1 == y2) {
		f2 = 1;
	}
	else {
		f2 = -1;
		kx2 = (x1-x2);
		ky2 = (y1-y2);
	}
	//printf("%lld %lld %lld %lld %lld %lld\n", x1, y1, x2, y2, kx2, ky2);
	dx2 = x1;
	dy2 = y1;
}

bool judgeline1(long long x1, long long y1, long long x2, long long y2) {
	if(f1 == 1)
		return y1 == y2;
	if(y1 == y2)
		return false;
	return ky1*(x1-x2) == kx1*(y1-y2);
}

bool judgeline2(long long x1, long long y1, long long x2, long long y2) {
	if(f2 == 1)
		return y1 == y2;
	if(y1 == y2)
		return false;
	return ky2*(x1-x2) == kx2*(y1-y2);
}



int main() {
	int n;
	int flag = 0, lastone = 0;
	scanf("%d", &n);
	if(n <= 4) {
		puts("YES");
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		scanf("%lld %lld", &pnt[i][0], &pnt[i][1]);
	}
	for(int i = 1; i <= 3; i++) {
		int fff = 0;
		for(int j = i + 1; j <= 4; j++) {
			for(int k = j + 1; k <= 5; k++) {
				if(oneline(pnt[i][0], pnt[i][1], pnt[j][0], pnt[j][1], pnt[k][0], pnt[k][1])) {
					joinline(pnt[i][0], pnt[i][1], pnt[j][0], pnt[j][1]);
					flag = 1;
					vis[i] = vis[j] = vis[k] = 1;
					fff = 1;
					break;
				}
			}
			if(fff)
				break;
		}
		if(fff)
			break;
	}
	if(flag) {
		for(int i = 1; i <= n; i++) {
			if(i > 5 || vis[i] == 0) {
				if(judgeline1(dx1, dy1, pnt[i][0], pnt[i][1]))
					continue;
				else if(f2) {
					if(judgeline2(dx2, dy2, pnt[i][0], pnt[i][1])) 
						continue;
					else {
						flag = 0;
						break;
					}
				}
				else if(lastone) {
					joinline2(tmp[0], tmp[1], pnt[i][0], pnt[i][1]);
					lastone = 0;
				}
				else {
					tmp[0] = pnt[i][0];
					tmp[1] = pnt[i][1];
					lastone = 1;
				}
			}
		}
	}
	//printf("%lld %lld %lld %lld\n", dx2, dy2, kx2, ky2);
	puts(flag?"YES":"NO");
	return 0;
}