#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


const int kind = 2;
struct Trie  
{
	Trie *nxt[kind];
	void init(){
		for (int i = 0; i<kind; i++)
				nxt[i] = NULL;
		}
};
Trie *root;

void Insert(unsigned s){
	Trie *p = root;
	for(int i = 31; i >= 0; i--){
		unsigned id = (s>>i)&1;
		if(p->nxt[id] == NULL){
			p->nxt[id] = new Trie;
			p->nxt[id]->init();
		}
		p = p->nxt[id];
	}
}

int Query(unsigned s){
	Trie *p = root;
	unsigned ans = 0;
	for(int i = 31; i >= 0; i--){
		unsigned id = (s>>i)&1;
		if(p->nxt[id^1] != NULL) 
			id ^= 1;
		p = p-> nxt[id];
		ans += id << i;
	}
	return ans;
}

void Trie_del(Trie *rt) {
	for(int i = 0; i < kind; ++i) {
		if(rt->nxt[i] != NULL)
			Trie_del(rt->nxt[i]);
	}
	delete rt;
}

int main(){
	int t, m, n, u, T;
	scanf("%d", &t);
	T = t;
	while(t--){
		root = new Trie;
		root->init();
		scanf("%d %d", &n, &m);
		printf("Case #%d:\n", T-t);
		for(int i = 0; i<n; i++){
			scanf("%d", &u);
			Insert(u);
		}
		for (int i = 0; i < m; ++i)
		{
			scanf("%d", &u);
			printf("%d\n", Query(u));
		}
		Trie_del(root);
	}
	return 0;
}

