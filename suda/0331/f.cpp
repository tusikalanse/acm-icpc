#include <bits/stdc++.h>
using namespace std;

struct node
{
	int cnt;
	node *p[2];
	void init() {
		cnt = 0;
		p[0] = p[1] = NULL;
	}
}*Trie;

void Insert(int t) {
	node *pnt = Trie;
	for(int i = 31; i >= 0; i--) {
		int q = (t >> i) & 1;
		if(pnt->p[q] != NULL) {
			pnt = pnt->p[q];
			pnt->cnt++;
		}
		else {
			pnt->p[q] = new node;
			pnt = pnt->p[q];
			pnt->init();
			pnt->cnt++;
		}
	}
}

int query(int x) {
	node *pnt = Trie;
	int ans = 0;
	for(int i = 31; i >= 0; i--) {
		ans <<= 1;
		int q = (x >> i) & 1;
		if(pnt->p[q] && pnt->p[q]->cnt != 0) {
			pnt = pnt->p[q];
			pnt->cnt--;
		}
		else {
			pnt = pnt->p[q^1];
			ans |= 1;
			pnt->cnt--;
		}
	}
	return ans;
}

int a[300005], t;

int main() {
	Trie = new node;
	Trie->init();
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		scanf("%d", &t);
		Insert(t);
	}
	for (int i = 1; i <= n; ++i)
	{
		printf("%d ", query(a[i]));
	}
	puts("");
	return 0;
}