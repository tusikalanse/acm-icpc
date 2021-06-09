#include <bits/stdc++.h>
using namespace std;


const int N = 5e5 + 10;
int n, d[N], a[N];
long long tot;


bool Havel(int N, int deg) {
    for (int i = N - 1; i >= 0; --i) {
        insert(a, a + i+1);
        if (!a[i]) break;
        for (int j = i - 1; j >= 0 && a[i]; j--) {
            a[j]--; a[i] --;
            if (a[j] < 0) return false;
        }
        if (a[i] > 0) return false; // 任然有剩余
    }
    return true;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &d[i]);
		tot += d[i];
	}
	sort(d + 1, d + n + 1);
	int l = 0, r = n;
	if(tot & 1)
		l++;
	if((r - l) & 1)
		r--;
	int al, ar;
	while(l <= r) {
		int d = (r - l) / 3;
		int ll = l + d, rr = r - d;
		if(check(ll) <= check(rr)) {

		}
	}

	return 0;
}