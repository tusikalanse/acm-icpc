/*
 * @Author: tusikalanse
 * @Date: 2021-10-21 09:06:48
 * @LastEditTime: 2021-10-21 10:04:41
 * @LastEditors: tusikalanse
 * @Description: 
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3e6 + 10;
string s1, s2, x;
int nxt1[N], extend[N], T;
int nxt2[N];
int ans[N];

void getnext(string &t, int nxt[]) {
	int len = t.size(), po, i = 0, j;
	nxt[0] = len;
	while(t[i] == t[i + 1] && i + 1  < len) 
		++i;
	nxt[1] = i;
	po = 1;
	for(i = 2; i < len; ++i) {
		if(nxt[i - po] + i < po + nxt[po])
			nxt[i] = nxt[i - po];
		else {
			j = po + nxt[po] - i;
			if(j < 0) j = 0;
			while(i + j < len && t[j] == t[i + j])
				++j;
			nxt[i] = j;
			po = i;
		}
	}
}

void exkmp(string &s, string &t, int nxt[]) {
	int len = s.size(), po, i = 0, j, l2 = t.size();
	getnext(t, nxt);
	while(t[i] == s[i] && i < len && i < l2) 
		++i;
	extend[0] = i;
	po = 0;
	for(i = 1; i < len; ++i) {
		if(nxt[i - po] + i < po + extend[po])
			extend[i] = nxt[i - po];
		else {
			j = po + extend[po] - i;
			if(j < 0) j = 0;
			while(i + j < len && j < l2 && t[j] == s[i + j])
				++j;
			extend[i] = j;
			po = i;
		}
	}
}

void kmp(string& s1, string& s2, int nxt[]) {
	string s = s2 + '#' + s1;
	int n = s.size(), i = 0, j = -1;
	nxt[0] = -1;
	while (i < n) {
		if (j == -1 || s[i] == s[j]) 
			nxt[++i] = ++j;
		else
			j = nxt[j];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> s1 >> s2 >> x;
		int total = x.size() + s1.size() + s2.size() + 10;

		memset(nxt1, 0, total * sizeof(int));
		memset(nxt2, 0, total * sizeof(int));
		memset(extend, 0, total * sizeof(int));
		memset(ans, 0, total * sizeof(int));
		exkmp(x, s2, nxt2);
		kmp(x, s1, nxt1);

		for (int i = 0; i <= x.size(); ++i) {
			int r = extend[i], l = nxt1[s1.size() + 1 + i];
			ans[l] = max(ans[l], r + 1);
		}

		for (int i = s1.size(); i; --i) {
			ans[nxt1[i]] = max(ans[nxt1[i]], ans[i]);
		}

		LL res = 0;
		for (int i = 0; i <= s1.size(); ++i) {
			res += ans[i];
		}
		cout << res << endl;
    }

	return 0;
}