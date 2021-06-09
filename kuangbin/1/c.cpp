#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 100005;

struct node
{
	int x, s;
}start, temp, t;
int vis[MAXN];
int main(int argc, char const *argv[])
{
	int n, m, nx, ans = 0;
	memset(vis, 0, sizeof(vis));
	scanf("%d %d", &n, &m);
	queue<node> bfs;
	start.x = n;
	start.s = 0;
	vis[n] = 1;
	bfs.push(start);
	while(!bfs.empty()){
		temp = bfs.front();
		bfs.pop();
		if(temp.x < m){
			nx = 2*temp.x;
			if(nx < MAXN && vis[nx] == 0){
				t.x = nx;
				t.s = temp.s + 1;
				if(t.x == m){
					ans = t.s;
					goto nxt;
				}
				vis[nx] = 1;
				bfs.push(t);
			}
		}
		nx = temp.x - 1;
		if(nx>=0 && vis[nx] == 0){
			t.x = nx;
			t.s = temp.s + 1;
			if(t.x == m){
					ans = t.s;
					goto nxt;
			}
			vis[nx] = 1;
			bfs.push(t);
		}
		nx = temp.x + 1;
		if(nx<MAXN && vis[nx] == 0){
			t.x = nx;
			t.s = temp.s + 1;
			if(t.x == m){
					ans = t.s;
					goto nxt;
			}
			vis[nx] = 1;
			bfs.push(t);
		}
	}
	nxt:;
	printf("%d\n", ans);
	return 0;
}