#include <bits/stdc++.h>
using namespace std;

int convert(char ch) {
	if(ch >= 'a' && ch <= 'z')
		return ch - 'a';
	if(ch == '.')
		return 26;
	return ch - '0' + 27;
}

map<long long, set<int> > ans;

char s[10010][10], t[10];
void gethash(char s[], int id) {
	long long hh = 1;
	for(int i = 0; s[i]; ++i) {
		hh = hh * 37 + convert(s[i]);
		ans[hh].insert(id);
	}
}

int n, q;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", &s[i][0]);
		int l = strlen(s[i]);
		for(int j = 0; j < l; ++j)
			gethash(&s[i][j], i);
	}
	scanf("%d", &q);
	while(q--) {
		scanf("%s", t);
		long long hh = 1;
		for(int i = 0; t[i]; ++i) 
			hh = hh * 37 + convert(t[i]);
		if(!ans.count(hh)) {
			puts("0 -");
		}
		else {
			printf("%d %s\n", (int)ans[hh].size(), s[*(ans[hh].begin())]);
		}
	}
	return 0;
}