#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+10;
int P[MAXN], R[MAXN], B[MAXN];
int cntp = 0, cntr = 0, cntb = 0;
char s[5];

int main() {
	int n, t;
	scanf("%d", &n);
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d %s", &t, s);
		if(s[0] == 'P') 
			P[cntp++] = t;
		else if(s[0] == 'R')
			R[cntr++] = t;
		else if(s[0] == 'B')
			B[cntb++] = t;
	}
	if(cntp == 0) {
		if(cntb)
			ans += B[cntb-1] - B[0];
		if(cntr)
			ans += R[cntr-1] - R[0];
	}
	else {
		int ib = 0, ir = 0;
		while(ib < cntb && B[ib] < P[0]) 
			ib++;
		while(ir < cntr && R[ir] < P[0])
			ir++;
		if(cntb && P[0] > B[0])
			ans += P[0] - B[0];
		if(cntr && P[0] > R[0])
			ans += P[0] - R[0];
		for(int ip = 0; ip < cntp - 1; ip++) {
			long long tmpb = 0, tmpr = 0, tttt;
			if(ib < cntb && B[ib] < P[ip + 1] && B[ib] > P[ip])
				tttt = B[ib] - P[ip];
			else
				tttt = P[ip + 1] - P[ip];
			while(ib < cntb && B[ib] < P[ip + 1]) {
				if(ib < cntb - 1 && B[ib + 1] < P[ip + 1])
					tttt = max(tttt, 0LL + B[ib + 1] - B[ib]);
				ib++;
			}
			if(ib && cntb && B[ib - 1] > P[ip])
				tttt = max(tttt, 0LL + P[ip + 1] - B[ib - 1]);
			tmpb = tttt;
			if(ir < cntr && R[ir] < P[ip + 1] && R[ir] > P[ip])
				tttt = R[ir] - P[ip];
			else
				tttt = P[ip + 1] - P[ip];
			while(ir < cntr && R[ir] < P[ip + 1]) {
				if(ir < cntr - 1 && R[ir + 1] < P[ip + 1])
					tttt = max(tttt, 0LL + R[ir + 1] - R[ir]);
				ir++;
			}
			if(ir && cntr && R[ir - 1] > P[ip])
				tttt = max(tttt, 0LL + P[ip + 1] - R[ir - 1]);
			tmpr = tttt;
			long long tmp = P[ip + 1] - P[ip];
			ans += min(2 * tmp, 3 * tmp - tmpb - tmpr);
		}
		if(cntb && P[cntp - 1] < B[cntb - 1])
			ans += B[cntb - 1] - P[cntp - 1];
		if(cntr && P[cntp - 1] < R[cntr - 1])
			ans += R[cntr - 1] - P[cntp - 1];
	}
	printf("%lld\n", ans);
	return 0;
}