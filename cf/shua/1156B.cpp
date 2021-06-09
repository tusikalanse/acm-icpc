#include <bits/stdc++.h>
using namespace std;

int T, n, cnt[26], tot;
string s;

bool judge() {
	tot = 0;
	for(int i = 0; i < 26; ++i) 
		tot += !!cnt[i];
	if(tot == 1 || tot > 3)
		return true;
	int i = 0;
	while(!cnt[i]) i++;
	if(tot == 2 && cnt[i + 1])
		return false;
	if(tot == 3 && cnt[i + 1] && cnt[i + 2])
		return false;
	return true;
}

void print() {
	int i = 0, j, k, l;
	if(tot == 1) {
		while(!cnt[i]) i++;
		while(cnt[i]--)
			cout << (char)('a' + i);
		cout << endl;
		return;
	}
	while(!cnt[i]) i++;
	if(tot == 2) {
		j = i + 1;
		while(!cnt[j]) j++;
		while(cnt[i]--) cout << (char)('a' + i);
		while(cnt[j]--) cout << (char)('a' + j);
		cout << endl;
		return;
	}
	if(tot == 3) {
		j = i + 1;
		while(!cnt[j]) j++;
		k = j + 1;
		while(!cnt[k]) k++;
		if(i + 1 == j) {
			while(cnt[j]--) cout << (char)('a' + j);
			while(cnt[k]--) cout << (char)('a' + k);
			while(cnt[i]--) cout << (char)('a' + i);
		}
		else if(j + 1 == k) {
			while(cnt[j]--) cout << (char)('a' + j);
			while(cnt[i]--) cout << (char)('a' + i);
			while(cnt[k]--) cout << (char)('a' + k);	
		}
		else {
			while(cnt[i]--) cout << (char)('a' + i);
			while(cnt[j]--) cout << (char)('a' + j);
			while(cnt[k]--) cout << (char)('a' + k);
		}
		cout << endl;
		return;
	}
	j = i + 1;
	while(!cnt[j]) j++;
	k = j + 1;
	while(!cnt[k]) k++;
	l = k + 1;
	while(!cnt[l]) l++;
	string ans = "";
	while(cnt[k]--) ans += 'a' + k;
	while(cnt[i]--) ans += 'a' + i;
	while(cnt[l]--) ans += 'a' + l;
	while(cnt[j]--) ans += 'a' + j;
	for(int _ = 4; _ < tot; ++_) {
		l++;
		while(!cnt[l]) l++;
		if(_ % 2 == 0) {
			while(cnt[l]--) ans = (char)('a' + l) + ans;
		}
		else
			while(cnt[l]--) ans += (char)('a' + l);
	}
	cout << ans << endl;
}

int main() {
	cin >> T;
	while(T--) {
		cin >> s;
		n = s.size();
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < n; ++i) {
			cnt[s[i] - 'a']++;
		}
		if(!judge())
			cout << "No answer" << endl;
		else
			print();
	}
	return 0;
}