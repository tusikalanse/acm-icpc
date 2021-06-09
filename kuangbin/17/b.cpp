#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

const int KIND = 128;
const int MAXN = 10010;

char s[MAXN];
set<int> ans;

struct Trie {
	Trie *fail;
	Trie *nxt[KIND];
	int id;
	Trie() {
		memset(nxt, 0, sizeof(nxt));
		fail = NULL;
		id = 0;
	}
}*root, *queue[500];

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
		int id = s[i];
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
		tail %= 500;
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
			head %= 500;
		}
	}
}

void AC_automation(const char *str) {
	int len = strlen(str);
	int id;
	Trie *p = root;
	for(int i = 0; i < len; ++i) {
		id = str[i];
		while(p->nxt[id] == NULL && p != root)
			p = p->fail;
		p = p->nxt[id];
		if(p == NULL)
			p = root;
		Trie *tmp = p;
		while(tmp != root) {
			if(tmp->id > 0) {
				ans.insert(tmp->id);
			}
			else
				break;
			tmp = tmp->fail;
		}
	}
}

int main() {
	char word[210];
	int n, m, sum = 0;
	scanf("%d", &n);
	root = new Trie;
	getchar();
	for(int i = 1; i <= n; ++i) {
		gets(word);
		Insert(word, i);
	}
	bfs();
	scanf("%d", &m);
	getchar();
	for(int i = 1; i <= m; ++i) {
		gets(s);
		ans.clear();
		AC_automation(s);
		if(!ans.empty()) {
			sum++;
			printf("web %d:", i);
			for(set<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
				printf(" %d", *it);
			}
			puts("");
		}
	}
	printf("total: %d\n", sum);
	return 0;
}