#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, V = 7007;

bitset<V> Div[V], M[V], S[N];
bool sqfree[V];
int n, m, op, x, y, z;
void pre() {
	for(int i = 1; i < V; ++i) {
		for(int j = 2; j <= i; ++j) {
			if(i % (j * j) == 0)
				sqfree[i] = 1;
		}
	}
	for(int i = 1; i < V; ++i) {
		for(int j = 1; j * i < V; ++j) {
			Div[j * i][i] = 1;
			if(sqfree[j] == 0)
				M[i][i * j] = 1;
		}
	}
}

int main() {
	pre();
	scanf("%d%d", &n, &m);
	while(m--) {
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1)
			S[x] = Div[y];
		else if(op == 2) {
			scanf("%d", &z);
			S[x] = S[y] ^ S[z];
		}
		else if(op == 3) {
			scanf("%d", &z);
			S[x] = S[y] & S[z];
		}
		else 
			putchar('0' + (S[x] & M[y]).count() % 2);
	}
	putchar('\n');
	return 0;
}