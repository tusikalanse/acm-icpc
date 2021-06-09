#include <bits/stdc++.h>
using LL = long long;
using namespace std;


int nxt[200010];
pair<char, LL> t[200010], s[200010], mt[200010];
int n, m, nn, mm, num;
LL ans = 0;
char ch;


void getnext() {
	int k = -1, j = 0;
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	while(j < m) {
		if(k == -1 || mt[j] == mt[k])
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

void kmp() {
	int i = 0, j = 0;
	getnext();
	while(i < nn) {
		if(j == -1 || s[i] == mt[j]) {
			++i;
			++j;
		}
		else
			j = nxt[j];
		if(j == m){
            if(i < n && s[i - m - 1].first == t[0].first && s[i - m - 1].second >= t[0].second
               && s[i].first == t[mm - 1].first && s[i].second >= t[mm - 1].second){
                ans++;
            }
            j = nxt[j];
        }
	}
	return;
}


int main() {
	scanf("%d%d", &n, &m);
	nn = mm = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d-%c", &num, &ch);
		if(i == 0) {
			s[nn++] = make_pair(ch, num);
			continue;
		}
		if(s[nn - 1].first == ch) {
			s[nn - 1].second += num;
		}
		else {
			s[nn++] = make_pair(ch, num);
		}
	}
	for(int i = 0; i < m; ++i) {
		scanf("%d-%c", &num, &ch);
		if(i == 0) {
			t[mm++] = make_pair(ch, num);
			continue;
		}
		if(t[mm - 1].first == ch) {
			t[mm - 1].second += num;
		}
		else {
			t[mm++] = make_pair(ch, num);
		}
	}
	if(mm == 1) {
		for(int i = 0; i < nn; ++i)
			if(s[i].first == t[0].first && s[i].second >= t[0].second)
				ans += s[i].second - t[0].second + 1;
	}
	else if(mm == 2) {
		for(int i = 0; i < nn - 1; ++i) {
			if(s[i].first == t[0].first && s[i + 1].first == t[1].first && s[i].second >= t[0].second && s[i + 1].second >= t[1].second)
				ans++;
		}
	}
	else {
		m = 0;
		for(int i = 1; i < mm - 1; ++i)
			mt[m++] = t[i];
		kmp();
	}
	printf("%lld\n", ans);
	return 0;
}