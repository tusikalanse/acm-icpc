#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <map>
#include <iostream>
using namespace std;

string sentences[408]={
"pron.v.",
"pron.vi.",
"pron.adv.v.",
"pron.adv.vi.",
"art.n.v.",
"art.n.vi.",
"art.n.adv.v.",
"art.n.adv.vi.",
"art.adj.n.v.",
"art.adj.n.vi.",
"art.adj.n.adv.v.",
"art.adj.n.adv.vi.",
"prep.pron.pron.v.",
"prep.pron.pron.vi.",
"prep.pron.pron.adv.v.",
"prep.pron.pron.adv.vi.",
"prep.pron.art.n.v.",
"prep.pron.art.n.vi.",
"prep.pron.art.n.adv.v.",
"prep.pron.art.n.adv.vi.",
"prep.pron.art.adj.n.v.",
"prep.pron.art.adj.n.vi.",
"prep.pron.art.adj.n.adv.v.",
"prep.pron.art.adj.n.adv.vi.",
"prep.art.n.pron.v.",
"prep.art.n.pron.vi.",
"prep.art.n.pron.adv.v.",
"prep.art.n.pron.adv.vi.",
"prep.art.n.art.n.v.",
"prep.art.n.art.n.vi.",
"prep.art.n.art.n.adv.v.",
"prep.art.n.art.n.adv.vi.",
"prep.art.n.art.adj.n.v.",
"prep.art.n.art.adj.n.vi.",
"prep.art.n.art.adj.n.adv.v.",
"prep.art.n.art.adj.n.adv.vi.",
"pron.prep.pron.v.",
"pron.prep.pron.vi.",
"pron.prep.pron.adv.v.",
"pron.prep.pron.adv.vi.",
"pron.prep.art.n.v.",
"pron.prep.art.n.vi.",
"pron.prep.art.n.adv.v.",
"pron.prep.art.n.adv.vi.",
"art.n.prep.pron.v.",
"art.n.prep.pron.vi.",
"art.n.prep.pron.adv.v.",
"art.n.prep.pron.adv.vi.",
"art.n.prep.art.n.v.",
"art.n.prep.art.n.vi.",
"art.n.prep.art.n.adv.v.",
"art.n.prep.art.n.adv.vi.",
"art.adj.n.prep.pron.v.",
"art.adj.n.prep.pron.vi.",
"art.adj.n.prep.pron.adv.v.",
"art.adj.n.prep.pron.adv.vi.",
"art.adj.n.prep.art.n.v.",
"art.adj.n.prep.art.n.vi.",
"art.adj.n.prep.art.n.adv.v.",
"art.adj.n.prep.art.n.adv.vi.",
"pron.v.prep.pron.",
"pron.v.prep.art.n.",
"pron.vi.prep.pron.",
"pron.vi.prep.art.n.",
"pron.adv.v.prep.pron.",
"pron.adv.v.prep.art.n.",
"pron.adv.vi.prep.pron.",
"pron.adv.vi.prep.art.n.",
"art.n.v.prep.pron.",
"art.n.v.prep.art.n.",
"art.n.vi.prep.pron.",
"art.n.vi.prep.art.n.",
"art.n.adv.v.prep.pron.",
"art.n.adv.v.prep.art.n.",
"art.n.adv.vi.prep.pron.",
"art.n.adv.vi.prep.art.n.",
"art.adj.n.v.prep.pron.",
"art.adj.n.v.prep.art.n.",
"art.adj.n.vi.prep.pron.",
"art.adj.n.vi.prep.art.n.",
"art.adj.n.adv.v.prep.pron.",
"art.adj.n.adv.v.prep.art.n.",
"art.adj.n.adv.vi.prep.pron.",
"art.adj.n.adv.vi.prep.art.n.",
"pron.v.pron.",
"pron.v.art.n.",
"pron.v.art.adj.n.",
"pron.vt.pron.",
"pron.vt.art.n.",
"pron.vt.art.adj.n.",
"pron.adv.v.pron.",
"pron.adv.v.art.n.",
"pron.adv.v.art.adj.n.",
"pron.adv.vt.pron.",
"pron.adv.vt.art.n.",
"pron.adv.vt.art.adj.n.",
"art.n.v.pron.",
"art.n.v.art.n.",
"art.n.v.art.adj.n.",
"art.n.vt.pron.",
"art.n.vt.art.n.",
"art.n.vt.art.adj.n.",
"art.n.adv.v.pron.",
"art.n.adv.v.art.n.",
"art.n.adv.v.art.adj.n.",
"art.n.adv.vt.pron.",
"art.n.adv.vt.art.n.",
"art.n.adv.vt.art.adj.n.",
"art.adj.n.v.pron.",
"art.adj.n.v.art.n.",
"art.adj.n.v.art.adj.n.",
"art.adj.n.vt.pron.",
"art.adj.n.vt.art.n.",
"art.adj.n.vt.art.adj.n.",
"art.adj.n.adv.v.pron.",
"art.adj.n.adv.v.art.n.",
"art.adj.n.adv.v.art.adj.n.",
"art.adj.n.adv.vt.pron.",
"art.adj.n.adv.vt.art.n.",
"art.adj.n.adv.vt.art.adj.n.",
"prep.pron.pron.v.pron.",
"prep.pron.pron.v.art.n.",
"prep.pron.pron.v.art.adj.n.",
"prep.pron.pron.vt.pron.",
"prep.pron.pron.vt.art.n.",
"prep.pron.pron.vt.art.adj.n.",
"prep.pron.pron.adv.v.pron.",
"prep.pron.pron.adv.v.art.n.",
"prep.pron.pron.adv.v.art.adj.n.",
"prep.pron.pron.adv.vt.pron.",
"prep.pron.pron.adv.vt.art.n.",
"prep.pron.pron.adv.vt.art.adj.n.",
"prep.pron.art.n.v.pron.",
"prep.pron.art.n.v.art.n.",
"prep.pron.art.n.v.art.adj.n.",
"prep.pron.art.n.vt.pron.",
"prep.pron.art.n.vt.art.n.",
"prep.pron.art.n.vt.art.adj.n.",
"prep.pron.art.n.adv.v.pron.",
"prep.pron.art.n.adv.v.art.n.",
"prep.pron.art.n.adv.v.art.adj.n.",
"prep.pron.art.n.adv.vt.pron.",
"prep.pron.art.n.adv.vt.art.n.",
"prep.pron.art.n.adv.vt.art.adj.n.",
"prep.pron.art.adj.n.v.pron.",
"prep.pron.art.adj.n.v.art.n.",
"prep.pron.art.adj.n.v.art.adj.n.",
"prep.pron.art.adj.n.vt.pron.",
"prep.pron.art.adj.n.vt.art.n.",
"prep.pron.art.adj.n.vt.art.adj.n.",
"prep.pron.art.adj.n.adv.v.pron.",
"prep.pron.art.adj.n.adv.v.art.n.",
"prep.pron.art.adj.n.adv.v.art.adj.n.",
"prep.pron.art.adj.n.adv.vt.pron.",
"prep.pron.art.adj.n.adv.vt.art.n.",
"prep.pron.art.adj.n.adv.vt.art.adj.n.",
"prep.art.n.pron.v.pron.",
"prep.art.n.pron.v.art.n.",
"prep.art.n.pron.v.art.adj.n.",
"prep.art.n.pron.vt.pron.",
"prep.art.n.pron.vt.art.n.",
"prep.art.n.pron.vt.art.adj.n.",
"prep.art.n.pron.adv.v.pron.",
"prep.art.n.pron.adv.v.art.n.",
"prep.art.n.pron.adv.v.art.adj.n.",
"prep.art.n.pron.adv.vt.pron.",
"prep.art.n.pron.adv.vt.art.n.",
"prep.art.n.pron.adv.vt.art.adj.n.",
"prep.art.n.art.n.v.pron.",
"prep.art.n.art.n.v.art.n.",
"prep.art.n.art.n.v.art.adj.n.",
"prep.art.n.art.n.vt.pron.",
"prep.art.n.art.n.vt.art.n.",
"prep.art.n.art.n.vt.art.adj.n.",
"prep.art.n.art.n.adv.v.pron.",
"prep.art.n.art.n.adv.v.art.n.",
"prep.art.n.art.n.adv.v.art.adj.n.",
"prep.art.n.art.n.adv.vt.pron.",
"prep.art.n.art.n.adv.vt.art.n.",
"prep.art.n.art.n.adv.vt.art.adj.n.",
"prep.art.n.art.adj.n.v.pron.",
"prep.art.n.art.adj.n.v.art.n.",
"prep.art.n.art.adj.n.v.art.adj.n.",
"prep.art.n.art.adj.n.vt.pron.",
"prep.art.n.art.adj.n.vt.art.n.",
"prep.art.n.art.adj.n.vt.art.adj.n.",
"prep.art.n.art.adj.n.adv.v.pron.",
"prep.art.n.art.adj.n.adv.v.art.n.",
"prep.art.n.art.adj.n.adv.v.art.adj.n.",
"prep.art.n.art.adj.n.adv.vt.pron.",
"prep.art.n.art.adj.n.adv.vt.art.n.",
"prep.art.n.art.adj.n.adv.vt.art.adj.n.",
"pron.prep.pron.v.pron.",
"pron.prep.pron.v.art.n.",
"pron.prep.pron.v.art.adj.n.",
"pron.prep.pron.vt.pron.",
"pron.prep.pron.vt.art.n.",
"pron.prep.pron.vt.art.adj.n.",
"pron.prep.pron.adv.v.pron.",
"pron.prep.pron.adv.v.art.n.",
"pron.prep.pron.adv.v.art.adj.n.",
"pron.prep.pron.adv.vt.pron.",
"pron.prep.pron.adv.vt.art.n.",
"pron.prep.pron.adv.vt.art.adj.n.",
"pron.prep.art.n.v.pron.",
"pron.prep.art.n.v.art.n.",
"pron.prep.art.n.v.art.adj.n.",
"pron.prep.art.n.vt.pron.",
"pron.prep.art.n.vt.art.n.",
"pron.prep.art.n.vt.art.adj.n.",
"pron.prep.art.n.adv.v.pron.",
"pron.prep.art.n.adv.v.art.n.",
"pron.prep.art.n.adv.v.art.adj.n.",
"pron.prep.art.n.adv.vt.pron.",
"pron.prep.art.n.adv.vt.art.n.",
"pron.prep.art.n.adv.vt.art.adj.n.",
"art.n.prep.pron.v.pron.",
"art.n.prep.pron.v.art.n.",
"art.n.prep.pron.v.art.adj.n.",
"art.n.prep.pron.vt.pron.",
"art.n.prep.pron.vt.art.n.",
"art.n.prep.pron.vt.art.adj.n.",
"art.n.prep.pron.adv.v.pron.",
"art.n.prep.pron.adv.v.art.n.",
"art.n.prep.pron.adv.v.art.adj.n.",
"art.n.prep.pron.adv.vt.pron.",
"art.n.prep.pron.adv.vt.art.n.",
"art.n.prep.pron.adv.vt.art.adj.n.",
"art.n.prep.art.n.v.pron.",
"art.n.prep.art.n.v.art.n.",
"art.n.prep.art.n.v.art.adj.n.",
"art.n.prep.art.n.vt.pron.",
"art.n.prep.art.n.vt.art.n.",
"art.n.prep.art.n.vt.art.adj.n.",
"art.n.prep.art.n.adv.v.pron.",
"art.n.prep.art.n.adv.v.art.n.",
"art.n.prep.art.n.adv.v.art.adj.n.",
"art.n.prep.art.n.adv.vt.pron.",
"art.n.prep.art.n.adv.vt.art.n.",
"art.n.prep.art.n.adv.vt.art.adj.n.",
"art.adj.n.prep.pron.v.pron.",
"art.adj.n.prep.pron.v.art.n.",
"art.adj.n.prep.pron.v.art.adj.n.",
"art.adj.n.prep.pron.vt.pron.",
"art.adj.n.prep.pron.vt.art.n.",
"art.adj.n.prep.pron.vt.art.adj.n.",
"art.adj.n.prep.pron.adv.v.pron.",
"art.adj.n.prep.pron.adv.v.art.n.",
"art.adj.n.prep.pron.adv.v.art.adj.n.",
"art.adj.n.prep.pron.adv.vt.pron.",
"art.adj.n.prep.pron.adv.vt.art.n.",
"art.adj.n.prep.pron.adv.vt.art.adj.n.",
"art.adj.n.prep.art.n.v.pron.",
"art.adj.n.prep.art.n.v.art.n.",
"art.adj.n.prep.art.n.v.art.adj.n.",
"art.adj.n.prep.art.n.vt.pron.",
"art.adj.n.prep.art.n.vt.art.n.",
"art.adj.n.prep.art.n.vt.art.adj.n.",
"art.adj.n.prep.art.n.adv.v.pron.",
"art.adj.n.prep.art.n.adv.v.art.n.",
"art.adj.n.prep.art.n.adv.v.art.adj.n.",
"art.adj.n.prep.art.n.adv.vt.pron.",
"art.adj.n.prep.art.n.adv.vt.art.n.",
"art.adj.n.prep.art.n.adv.vt.art.adj.n.",
"pron.v.prep.pron.pron.",
"pron.v.prep.pron.art.n.",
"pron.v.prep.pron.art.adj.n.",
"pron.v.prep.art.n.pron.",
"pron.v.prep.art.n.art.n.",
"pron.v.prep.art.n.art.adj.n.",
"pron.vt.prep.pron.pron.",
"pron.vt.prep.pron.art.n.",
"pron.vt.prep.pron.art.adj.n.",
"pron.vt.prep.art.n.pron.",
"pron.vt.prep.art.n.art.n.",
"pron.vt.prep.art.n.art.adj.n.",
"pron.adv.v.prep.pron.pron.",
"pron.adv.v.prep.pron.art.n.",
"pron.adv.v.prep.pron.art.adj.n.",
"pron.adv.v.prep.art.n.pron.",
"pron.adv.v.prep.art.n.art.n.",
"pron.adv.v.prep.art.n.art.adj.n.",
"pron.adv.vt.prep.pron.pron.",
"pron.adv.vt.prep.pron.art.n.",
"pron.adv.vt.prep.pron.art.adj.n.",
"pron.adv.vt.prep.art.n.pron.",
"pron.adv.vt.prep.art.n.art.n.",
"pron.adv.vt.prep.art.n.art.adj.n.",
"art.n.v.prep.pron.pron.",
"art.n.v.prep.pron.art.n.",
"art.n.v.prep.pron.art.adj.n.",
"art.n.v.prep.art.n.pron.",
"art.n.v.prep.art.n.art.n.",
"art.n.v.prep.art.n.art.adj.n.",
"art.n.vt.prep.pron.pron.",
"art.n.vt.prep.pron.art.n.",
"art.n.vt.prep.pron.art.adj.n.",
"art.n.vt.prep.art.n.pron.",
"art.n.vt.prep.art.n.art.n.",
"art.n.vt.prep.art.n.art.adj.n.",
"art.n.adv.v.prep.pron.pron.",
"art.n.adv.v.prep.pron.art.n.",
"art.n.adv.v.prep.pron.art.adj.n.",
"art.n.adv.v.prep.art.n.pron.",
"art.n.adv.v.prep.art.n.art.n.",
"art.n.adv.v.prep.art.n.art.adj.n.",
"art.n.adv.vt.prep.pron.pron.",
"art.n.adv.vt.prep.pron.art.n.",
"art.n.adv.vt.prep.pron.art.adj.n.",
"art.n.adv.vt.prep.art.n.pron.",
"art.n.adv.vt.prep.art.n.art.n.",
"art.n.adv.vt.prep.art.n.art.adj.n.",
"art.adj.n.v.prep.pron.pron.",
"art.adj.n.v.prep.pron.art.n.",
"art.adj.n.v.prep.pron.art.adj.n.",
"art.adj.n.v.prep.art.n.pron.",
"art.adj.n.v.prep.art.n.art.n.",
"art.adj.n.v.prep.art.n.art.adj.n.",
"art.adj.n.vt.prep.pron.pron.",
"art.adj.n.vt.prep.pron.art.n.",
"art.adj.n.vt.prep.pron.art.adj.n.",
"art.adj.n.vt.prep.art.n.pron.",
"art.adj.n.vt.prep.art.n.art.n.",
"art.adj.n.vt.prep.art.n.art.adj.n.",
"art.adj.n.adv.v.prep.pron.pron.",
"art.adj.n.adv.v.prep.pron.art.n.",
"art.adj.n.adv.v.prep.pron.art.adj.n.",
"art.adj.n.adv.v.prep.art.n.pron.",
"art.adj.n.adv.v.prep.art.n.art.n.",
"art.adj.n.adv.v.prep.art.n.art.adj.n.",
"art.adj.n.adv.vt.prep.pron.pron.",
"art.adj.n.adv.vt.prep.pron.art.n.",
"art.adj.n.adv.vt.prep.pron.art.adj.n.",
"art.adj.n.adv.vt.prep.art.n.pron.",
"art.adj.n.adv.vt.prep.art.n.art.n.",
"art.adj.n.adv.vt.prep.art.n.art.adj.n.",
"pron.v.pron.prep.pron.",
"pron.v.pron.prep.art.n.",
"pron.v.art.n.prep.pron.",
"pron.v.art.n.prep.art.n.",
"pron.v.art.adj.n.prep.pron.",
"pron.v.art.adj.n.prep.art.n.",
"pron.vt.pron.prep.pron.",
"pron.vt.pron.prep.art.n.",
"pron.vt.art.n.prep.pron.",
"pron.vt.art.n.prep.art.n.",
"pron.vt.art.adj.n.prep.pron.",
"pron.vt.art.adj.n.prep.art.n.",
"pron.adv.v.pron.prep.pron.",
"pron.adv.v.pron.prep.art.n.",
"pron.adv.v.art.n.prep.pron.",
"pron.adv.v.art.n.prep.art.n.",
"pron.adv.v.art.adj.n.prep.pron.",
"pron.adv.v.art.adj.n.prep.art.n.",
"pron.adv.vt.pron.prep.pron.",
"pron.adv.vt.pron.prep.art.n.",
"pron.adv.vt.art.n.prep.pron.",
"pron.adv.vt.art.n.prep.art.n.",
"pron.adv.vt.art.adj.n.prep.pron.",
"pron.adv.vt.art.adj.n.prep.art.n.",
"art.n.v.pron.prep.pron.",
"art.n.v.pron.prep.art.n.",
"art.n.v.art.n.prep.pron.",
"art.n.v.art.n.prep.art.n.",
"art.n.v.art.adj.n.prep.pron.",
"art.n.v.art.adj.n.prep.art.n.",
"art.n.vt.pron.prep.pron.",
"art.n.vt.pron.prep.art.n.",
"art.n.vt.art.n.prep.pron.",
"art.n.vt.art.n.prep.art.n.",
"art.n.vt.art.adj.n.prep.pron.",
"art.n.vt.art.adj.n.prep.art.n.",
"art.n.adv.v.pron.prep.pron.",
"art.n.adv.v.pron.prep.art.n.",
"art.n.adv.v.art.n.prep.pron.",
"art.n.adv.v.art.n.prep.art.n.",
"art.n.adv.v.art.adj.n.prep.pron.",
"art.n.adv.v.art.adj.n.prep.art.n.",
"art.n.adv.vt.pron.prep.pron.",
"art.n.adv.vt.pron.prep.art.n.",
"art.n.adv.vt.art.n.prep.pron.",
"art.n.adv.vt.art.n.prep.art.n.",
"art.n.adv.vt.art.adj.n.prep.pron.",
"art.n.adv.vt.art.adj.n.prep.art.n.",
"art.adj.n.v.pron.prep.pron.",
"art.adj.n.v.pron.prep.art.n.",
"art.adj.n.v.art.n.prep.pron.",
"art.adj.n.v.art.n.prep.art.n.",
"art.adj.n.v.art.adj.n.prep.pron.",
"art.adj.n.v.art.adj.n.prep.art.n.",
"art.adj.n.vt.pron.prep.pron.",
"art.adj.n.vt.pron.prep.art.n.",
"art.adj.n.vt.art.n.prep.pron.",
"art.adj.n.vt.art.n.prep.art.n.",
"art.adj.n.vt.art.adj.n.prep.pron.",
"art.adj.n.vt.art.adj.n.prep.art.n.",
"art.adj.n.adv.v.pron.prep.pron.",
"art.adj.n.adv.v.pron.prep.art.n.",
"art.adj.n.adv.v.art.n.prep.pron.",
"art.adj.n.adv.v.art.n.prep.art.n.",
"art.adj.n.adv.v.art.adj.n.prep.pron.",
"art.adj.n.adv.v.art.adj.n.prep.art.n.",
"art.adj.n.adv.vt.pron.prep.pron.",
"art.adj.n.adv.vt.pron.prep.art.n.",
"art.adj.n.adv.vt.art.n.prep.pron.",
"art.adj.n.adv.vt.art.n.prep.art.n.",
"art.adj.n.adv.vt.art.adj.n.prep.pron.",
"art.adj.n.adv.vt.art.adj.n.prep.art.n.",
};



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	set<string> valid;
	map<string, string> mp;
	cin >> n >> m;
	for(int i = 0; i < 408; ++i) {
		valid.insert(sentences[i]);
	}
	string tt;
	string s, t;
	for(int i = 0; i < n; ++i) {
		cin >> s >> t;
		mp[s] = t;
	}
	int flag;
	while(cin >> s) {
		flag = 0;
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 32;
		}
		if(s[s.size()-1] == '.') {
			flag = 1;
		}
		else if(s[s.size()-1] == ',') {
			flag = 2;
		}
		if(flag) {
			t.clear();
			for(int i = 0; i < s.size()-1; ++i)
				t += s[i];
			s = t;
		}
		tt += mp[s];
		if(flag == 1) {
			if(valid.count(tt)) {
				cout << "YES" << endl;
			}
			else 
				cout << "NO" << endl;
			tt.clear();
		}
	}
	return 0;
}
