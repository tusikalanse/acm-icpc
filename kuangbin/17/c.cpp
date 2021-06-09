#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

const int KIND = 26;
const int MAXN = 2000010;

char s[MAXN];
char word[1010][60];
int ans[1010];

struct Trie {
	Trie *fail;
	Trie *nxt[KIND];
	int id;
	Trie() {
		memset(nxt, 0, sizeof(nxt));
		fail = NULL;
		id = 0;
	}
}*root, *queue[50010];

void Del(Trie *rt) {
	for(int i = 0; i < KIND; ++i) {
		if(rt->nxt[i] != NULL)
			Del(rt->nxt[i]);
	}
	delete rt;
}

void Insert(const char *s, int num) {
	Trie *p = root;
	int len = strlen(s);
	for(int i = 0; i < len; ++i) {
		int id = s[i] - 'A';
		if(p->nxt[id] == NULL) {
			p->nxt[id] = new Trie();
		}
		p = p->nxt[id];
	}
	p->id = num;
}

void bfs() {
	int head = 0, tail = 0;
	queue[head++] = root;
	while(head != tail) {
		Trie *p = NULL;
		Trie *tmp = queue[tail++];
		for(int i = 0; i < KIND; ++i) {
			if(tmp->nxt[i] == NULL)
				continue;
			if(tmp == root) {
				tmp->nxt[i]->fail = root;
			} 
			else {
				p = tmp->fail;
				while(p != NULL) {
					if(p->nxt[i] != NULL) {
						tmp->nxt[i]->fail = p->nxt[i];
						break;
					}
					p = p->fail;
				}
				if(p == NULL)
					tmp->nxt[i]->fail = root;
			}
			queue[head++] = tmp->nxt[i];
		}
	}
}

void AC_automation(const char *str) {
	int len = strlen(str);
	int id;
	Trie *p = root;
	for(int i = 0; i < len; ++i) {
		if(str[i] > 'Z' || str[i] < 'A') {
			p = root;
			continue;
		}
		id = str[i] - 'A';
		while(p->nxt[id] == NULL && p != root)
			p = p->fail;
		p = p->nxt[id];
		if(p == NULL)
			p = root;
		Trie *tmp = p;
		while(tmp != root) {
			if(tmp->id > 0) {
				ans[tmp->id]++;
			}
			else
				break;
			tmp = tmp->fail;
		}
	}
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		memset(ans, 0, sizeof(ans));
		root = new Trie;
		for(int i = 1; i <= n; ++i) {
			scanf("%s", word[i]);
			Insert(word[i], i);
		}
		bfs();
		getchar();
		scanf("%[^\n]", s);
		AC_automation(s);
		for(int i = 1; i <= n; ++i) {
			if(ans[i] > 0)
				printf("%s: %d\n", word[i], ans[i]);
		}
		Del(root);
	}
	return 0;
}