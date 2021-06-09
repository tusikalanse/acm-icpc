#include <bits/stdc++.h>
using namespace std;

int n, k, cnt = 0;

char s[200010];
int stk[200010], top = 0;
char ans[200010];

int main() {
	cin >> n >> k >> s;
	k /= 2;	
	for(int i = 0; i < n; ++i) {
		if(k && s[i] == '(') {
			top++;
			k--;
			ans[cnt++] = '(';
		}
		if(s[i] == ')' && top) {
			top--;
			ans[cnt++] = ')';
		} 
	}
	cout << ans << endl;
	return 0;
}