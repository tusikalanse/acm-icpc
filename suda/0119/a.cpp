#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


const int kind = 26;
char word[100000];
struct Trie  
{
	int count, num;
	Trie *nxt[kind];
	void init(){
		for (int i = 0; i<kind; i++)
				nxt[i] = NULL;
			count = num = 0;
		}
} r;
Trie *root = &r;

void Insert(char s[]){
	Trie *p = root;
	int l = strlen(s);
	for(int i = 0; i < l; i++){
		int id = s[i] - 'a';
		if(p->nxt[id] == NULL){
			p->nxt[id] = new Trie;
			p->nxt[id]->init();
		}
		p = p->nxt[id];
		p->count++;
	}
	p->num++;
}

int Query(char s[]){
	Trie *p = root;
	int l = strlen(s);
	for(int i = 0; i < l; i++){
		int id = s[i] - 'a';
		if(p->nxt[id] == NULL) return 0;
		p = p->nxt[id];
	}
	return p->count;
}


int main(){
	while (gets(word)){
		if(strcmp(word, "") == 0) break;
		Insert(word);
	}
	while (gets(word)){
		if(strcmp(word, "") == 0) break;
		printf("%d\n", Query(word));
	}
	return 0;
}
