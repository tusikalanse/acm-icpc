#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
char s[N];
int nxt[N], n;
int num[N];
map<int, int> cnt;

void getnext() {
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	int j = 0, k = -1;
	while(j < n) {
		if(k == -1 || s[j] == s[k])
			nxt[++j] = ++k;
		else 
			k = nxt[k];
	}
}


int main() {
	memset(num, 0, sizeof(num));
	scanf("%s", s);
	n = strlen(s);
	getnext();
	for(int i = 1; i <= n; ++i) 
		num[i]++;
	for(int i = n; i >= 0; --i)
		if(nxt[i])
			num[nxt[i]] += num[i];
	int p = n;
	while(nxt[p] > 0) {
		cnt[nxt[p]] = num[nxt[p]];
		p = nxt[p];
	}
	cnt[n] = 1;
	cout << cnt.size() << endl;
	for(auto it = cnt.begin(); it != cnt.end(); ++it)
		cout << it->first << ' ' << it->second << endl;
	return 0;
}