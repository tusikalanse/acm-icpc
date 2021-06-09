#include <bits/stdc++.h>
using namespace std;

const int seed = 13331;
int k, ans = 0, n;
char s[1600], mp[28];
int a[1600];
unsigned long long h[1600], ex[1600];

int main() {
	scanf("%s%s%d", s + 1, mp, &k);
	n = strlen(s + 1);
	for(int i = 1; i <= n; ++i)
		a[i] = a[i - 1] + (mp[s[i] - 'a'] == '0');
	ex[0] = 1;
	for(int i = 1; i <= n; ++i) {
		ex[i] = ex[i - 1] * seed;
		h[i] = h[i - 1] * seed + s[i];
	}
	set<unsigned long long> u;
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; ++j) {
			if(a[j] - a[i - 1] <= k) {
				unsigned long long t = h[j] - h[i - 1] * ex[j - i + 1];
				u.insert(t);
			}
		}
	}
	printf("%d\n", (int)u.size());
	return 0;
}