#include <bits/stdc++.h>
using namespace std;

char s[200010];
int cnt[26], n, f = -1;

int main() {
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; ++i)
		cnt[s[i] - 'a']++;
	vector<int> odd;
	for(int i = 0; i < 26; ++i) {
		if(cnt[i] & 1)
			odd.push_back(i);
	}
	if(odd.size() & 1) {
		f = odd[odd.size() / 2];
	}
	int i = 0, j = odd.size() - 1;
	while(i < j) {
		cnt[odd[i]]++;
		cnt[odd[j]]--;
		i++;
		j--;
	}
	for(int i = 0; i < 26; ++i) {
		for(int j = 1; j * 2 <= cnt[i]; ++j)
			putchar('a' + i);
	}
	if(f != -1) 
		putchar('a' + f);
	for(int i = 25; ~i; --i) {
		for(int j = 1; j * 2 <= cnt[i]; ++j)
			putchar('a' + i);
	}
	puts("");
	return 0;
}