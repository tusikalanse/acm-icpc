#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

struct node
{
	int id, in, cnt;
	map<int, int> out;
	map<pair<int, int>, int> vis;
	int line[27];
	void init(){
		in = 0;
		cnt = 0;
		memset(line, 0, sizeof(line));
		return;
	}
	int M(){
		int ans = 0;
		for(int i = 0; i<27; i++)
			ans = max(ans, line[i]);
		return ans;
	}
}point[MAXN], temp;


int main()
{
	int n, m, x, y, ans = 0;
	char ch;
	scanf("%d %d", &n, &m);
	getchar();
	for(int i = 1; i<=n; i++){
		ch = getchar();
		point[i].init();
		point[i].id = ch - 'a' + 1;
		point[i].line[point[i].id] = 1;
	}
	for(int i = 0; i<m; i++){
		scanf("%d %d", &x, &y);
		if(point[x].vis.find(make_pair(x, y)) == point[x].vis.end()){
			point[y].in++;
			point[x].out[point[x].cnt++] = y;
			point[x].vis[make_pair(x, y)] = 1;
		}
	}
	queue<node> topo;
	for(int i = 1; i<=n; i++){
		if(point[i].in == 0)
			topo.push(point[i]);
	}
	while(!topo.empty()){
		temp = topo.front();
		topo.pop();
		for(int j = 0; j<temp.cnt; j++){
			for(int k = 1; k<=26; k++){
				if(k != point[temp.out[j]].id)
					point[temp.out[j]].line[k] = max(point[temp.out[j]].line[k], temp.line[k]);
				else
					point[temp.out[j]].line[k] = max(point[temp.out[j]].line[k], temp.line[k]+1);		
			}
			point[temp.out[j]].in--;
			if(point[temp.out[j]].in == 0)
				topo.push(point[temp.out[j]]);
		}
	}
	for(int i = 1; i<=n; i++){
		if(point[i].in != 0){
			ans = -1;
			goto nxt;
		}
		ans = max(ans, point[i].M());
	}
	nxt:;
	printf("%d\n", ans);
	return 0;
}u