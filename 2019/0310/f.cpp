#include <bits/stdc++.h>
using namespace std;

set<char> op;
char s[1010];
int n, match[1010], a[1010];
stack<int> stk;
bool flag = true;

void dfserror(int l, int r) {
	if(flag == false)
		return;
	if(l > r) {
		flag = false;
		return;
	}
	int ll = l, p = l, fd = 0;
	while(ll <= r) {
		while(p < r && op.count(s[p]) == 0) {
			if(s[p] == '(')
				p = match[p];
			else
				p++;
		}
		if(p == r) {
			bool f = true;
			while(ll <= r && s[ll] == ' ')
				ll++;
			while(p >= l && s[p] == ' ')
				p--;
			if(ll > p) {
				flag = false;
				return;
			}
			for(int pp = ll; pp <= p; ++pp) {
				if(!isalpha(s[pp])) {
					f = false;
					break;
				}
			}
			if(f && ll == p)
				return;
			else {
				while(ll <= r && s[ll] == ' ')
					ll++;
				while(p >= l && s[p] == ' ')
					p--;
				if(ll + 1 > p - 1) {
					flag = false;
					return;
				}
				if(isalpha(s[ll])) {
					flag = false;
					return;
				} 
				if(match[ll] != p) {
					flag = false;
					return;
				}
				dfserror(ll + 1, p - 1);
				return;
			}
		}
		dfserror(ll, p - 1);
		ll = p + 1;
		p = ll;
	}
}

void dfsproper(int l, int r) {
	if(flag == false)
		return;
	int cnt = 0;
	while(s[l] == ' ')
		l++;
	while(s[r] == ' ')
		r--;	
	int ll = l, p = l;
	if(match[l] == r && s[l] == '(' && s[r] == ')') {
		flag = false;
		return;
	}
	bool f = true;
	for(int i = l; i <= r; ++i)
		if(!isalpha(s[i])) {
			f = false;
			break;
		}
	if(f)
		return;
	while(ll <= r) {
		while(p < r && op.count(s[p]) == 0) {
			if(s[p] == '(')
				p = match[p];
			else
				p++;
		}
		if(op.count(s[p])) {
			cnt++;
		}
		while(s[ll] == ' ')
			ll++;
		while(s[p] == ' ')
			p--;
		if(isalpha(s[p]))
			dfsproper(ll, p);
		else 
			dfsproper(ll + 1, p - 2);
		ll = p + 1;
		while(s[ll] == ' ')
			ll++;
		p = ll;
	}
	if(cnt != 1)
		flag = false;
}

int main() {
	op.insert('+');
	op.insert('-');
	op.insert('*');
	op.insert('/');
	op.insert('%');
	cin.getline(s, 1010);
	n = strlen(s);
	for(int i = 0; i < n; ++i) {
		if(i != 0)
			a[i] = a[i - 1];
		if(s[i] == '(') {
			a[i]++;
			stk.push(i);
		}
		else if(s[i] == ')') {
			if(stk.empty()) {
				flag = false;
				break;
			}
			match[i] = stk.top();
			match[stk.top()] = i;
			stk.pop();
		}
	}
	if(stk.size()) 
		flag = false;
	if(flag == false) {
		printf("error\n");
		return 0;
	}
	dfserror(0, n - 1);
	if(flag == false) {
		printf("error\n");
		return 0;
	}
	dfsproper(0, n - 1);
	if(flag) 
		printf("proper\n");
	else
		printf("improper\n");
	return 0;
}