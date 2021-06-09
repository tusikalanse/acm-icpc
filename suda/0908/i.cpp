#include <bits/stdc++.h>
using namespace std;

int mp[1030], m, T, n, num, top;
char s[200010];
char bit[12];
int two[200010];
int check[100], t_c;

int to() {
	int ans = 0;
	for(int i = 0; bit[i]; ++i)
		ans = (ans << 1) + bit[i] - '0';
	return ans;
}

int trans(char ch) {
	if(ch >= '0' && ch <= '9') return ch - '0';
	if(ch >= 'a' && ch <= 'f') return ch - 'a';
	if(ch >= 'A' && ch <= 'F') return ch - 'A';
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &m, &n);
		memset(mp, 0, sizeof(mp));
		while(n--) {
			scanf("%d%s", &num, bit);
			mp[to()] = num;
		}
		scanf("%s", s);
		int tmp = 0;
		for(int i = 0; s[i]; ++i) {
			int p = trans(s[i]);
			for(int i = 3; i >= 0; --i) {
				check[t_c++] = p >> i;
				if(t_c == 9)
					
			}
		}
	}
	return 0;
}