#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int w[N];
struct node {
	int id, w;
	node(int _id, int _w) : id(_id), w(_w) {}
	bool operator < (const node &rhs) const {
		return w < rhs.w;
	}
};
set<node> s0, s1;

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> w[i];
		s0.insert(node(i, w[i]));
	}
	string s;
	cin >> s;
	set<node>::iterator it;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == '0') {
			cout << s0.begin()->id << ' ';
			s1.insert(*s0.begin());
			s0.erase(*s0.begin());
		}
		else {
			cout << s1.rbegin()->id << ' ';
			s1.erase(*s1.rbegin());
		}
	}
	cout << endl;
	return 0;
}