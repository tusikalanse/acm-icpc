#include <bits/stdc++.h>
using namespace std;

map< pair<int, int>, int > mp;
int n, id1 = 1, id2[2] = {1, 2}, max1, max2, a, b, c;
map< pair<int, int>, int > maxid;

int minof3(int &a, int &b, int &c) {
	if(a > b)
		swap(a, b);
	if(a > c)
		swap(a, c);
	if(b > c)
		swap(b, c);
	return a;
}

void pro(int a, int b, int c, int i) {
	if(mp[make_pair(a, b)]) {
		if(min(a, mp[make_pair(a, b)] + c) > max2) {
			max2 = min(a, mp[make_pair(a, b)] + c);
			id2[0] = i;
			id2[1] = maxid[make_pair(a, b)];
		}
	}
	if(mp[make_pair(a, b)] < c) {
		mp[make_pair(a, b)] = c;
		maxid[make_pair(a, b)] = i;
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		if(minof3(a, b, c) > max1) {
			max1 = a;
			id1 = i;
		}
		if(a == b && b == c) {
			pro(a, b, c, i);
		}
		else if(a == b) {
			pro(a, b, c, i);
			pro(a, c, b, i);
		}
		else if(b == c) {
			pro(a, b, c, i);
			pro(b, c, a, i);
		}
		else {
			pro(a, b, c, i);
			pro(a, c, b, i);
			pro(b, c, a, i);
		}
	}
	if(max1 >= max2) {
		printf("1\n%d\n", id1);
	}
	else 
		printf("2\n%d %d\n", id2[0], id2[1]);
	return 0;
}