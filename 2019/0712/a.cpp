#include <bits/stdc++.h>
using namespace std;

int n, p, q, m, T, cas; 
unsigned int SA, SB, SC;
unsigned long long ans;
unsigned int rng61() { 
	SA ^= SA << 16; 
	SA ^= SA >> 5;
	SA ^= SA << 1; 
	unsigned int t = SA; 
	SA = SB; 
	SB = SC; 
	SC ^= t ^ SA; 
	return SC; 
} 


struct node {
	unsigned val;
	int pos;
	node() {val = 0; pos = 0;}
	node(unsigned _v, int _p) {val = _v, pos = _p;}
};
stack<node> s;
stack<int> id;


void PUSH(unsigned a, int p) {
	//cout << "pushing " << a << " in " << p << endl;
	node t(a, p);
	id.push(p);
	if(s.empty() || a > s.top().val) { 
		s.push(t);
	}
	//cout << p << " " << s.top().val<< endl;
	ans ^= 1ULL * p * s.top().val;
}

void POP(int p) {
	if(s.empty()) return;
	int dd = id.top();
	id.pop();
	if(dd == s.top().pos) {
		s.pop();
	}
	if(s.empty()) return;
	//cout << p << " " << s.top().val<< endl;
	ans ^= 1ULL * p * s.top().val;
}

void gen() { 
	while(!s.empty()) s.pop();
	while(!id.empty()) id.pop(); 
	ans = 0;
	for(int i = 1; i <= n; i++) { 
		if(rng61() % (p + q) < p) 
			PUSH(rng61() % m + 1, i); 
		else 
			POP(i);
	}
	printf("Case #%d: %llu\n", ++cas, ans);
}


int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
		gen();
	}
	return 0;
}