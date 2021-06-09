#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
char d[4] = "ABC";
struct node
{
	int f[9], Hash;
}Start, End, temp;
const int MAXN = 1e6;
int vis[MAXN];
struct path
{
	int fa;
	char ch;
}p[MAXN];

int cantor(int a[]){
	int k, ans = 0;
	for(int i = 0; i<8; i++){
		k = 0;
		for(int j = i+1; j<8; j++)
			if(a[j] < a[i]) k++;
		ans += k*fact[7-i];
	}
	return ans;
}

void print(int t){
	if(p[t].fa == -1) return;
	print(p[t].fa);
	printf("%c", p[t].ch);
}


int main(){
	char a[30], b[30];
	int pos[10];
	int tar, k;
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i<8; i++) Start.f[i] = i+1;
	Start.Hash = cantor(Start.f);
	vis[Start.Hash] = 1;
	p[Start.Hash].fa = -1;
	queue<node> bfs;
	bfs.push(Start);
	while(!bfs.empty()){
		temp = bfs.front();
		bfs.pop();
		for(int i = 0; i<3; i++){
			node e;
			switch(i){
					case 0:
						e.f[0] = temp.f[7];
						e.f[1] = temp.f[6];
						e.f[2] = temp.f[5];
						e.f[3] = temp.f[4];
						e.f[4] = temp.f[3];
						e.f[5] = temp.f[2];
						e.f[6] = temp.f[1];
						e.f[7] = temp.f[0];
						break;
					case 1:
						e.f[0] = temp.f[3];
						e.f[1] = temp.f[0];
						e.f[2] = temp.f[1];
						e.f[3] = temp.f[2];
						e.f[4] = temp.f[5];
						e.f[5] = temp.f[6];
						e.f[6] = temp.f[7];
						e.f[7] = temp.f[4];
						break;
					case 2:
						e.f[0] = temp.f[0];
						e.f[1] = temp.f[6];
						e.f[2] = temp.f[1];
						e.f[3] = temp.f[3];
						e.f[4] = temp.f[4];
						e.f[5] = temp.f[2];
						e.f[6] = temp.f[5];
						e.f[7] = temp.f[7];
						break;
			}	
			k = cantor(e.f);
			if(vis[k]) continue;
			vis[k] = 1;
			e.Hash = k;
			p[k].fa = temp.Hash;
			p[k].ch = d[i];
			bfs.push(e);
		}
	}
	while(~scanf("%s %s", a, b)){
		for(int i = 0; i<8; i++){
			pos[a[i]-'0'] = i+1;
		}
		for(int i = 0; i<8; i++)
			End.f[i] = pos[b[i]-'0'];
		print(cantor(End.f));
		puts("");
	}
	return 0;
}
