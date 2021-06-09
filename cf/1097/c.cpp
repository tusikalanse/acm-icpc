#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
char s[N];
int n, ans, eq;
vector<int> l, r;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%s", s);
		int mx = 0, tmp = 0, len = strlen(s);
		for(int j = 0; j < len; ++j) {
			if(s[j] == '(')
				tmp++;
			else
				tmp--;
		}
		if(tmp == 0) {
			bool flag = 1;
			tmp = 0;
			for(int j = 0; j < len; ++j) {
				if(s[j] == '(')
					tmp++;
				else
					tmp--;
				flag &= tmp >= 0;
			}
			if(flag)
				eq++;
		}
		else if(tmp > 0) {
			bool flag = 1;
			tmp = 0;
			for(int j = 0; j < len; ++j) {
				if(s[j] == '(')
					tmp++;
				else
					tmp--;
				flag &= tmp >= 0;
			}
			if(flag)
				l.push_back(tmp);
		}
		else {
			bool flag = 1;
			tmp = 0;
			for(int j = len - 1; ~j; --j) {
				if(s[j] == ')')
					tmp++;
				else
					tmp--;
				flag &= tmp >= 0;
			}
			if(flag)
				r.push_back(tmp);
		}
	}
	ans = eq / 2;
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	int i = 0, j = 0;
	while(i < l.size() && j < r.size()) {
		if(l[i] == r[j]) {
			ans++;
			i++;
			j++;
		}
		else if(l[i] < r[j])
			i++;
		else
			j++;
	}
	printf("%d\n", ans);
	return 0;
}