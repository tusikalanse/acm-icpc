#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

int vis[10000];
int step[10000];
int prime[10000];


int main()
{
	memset(prime, 0, sizeof(prime));
	for(int i = 1000; i<10000; i++){
		int flag = 1;
		for(int j = 2; j*j<=i; j++){
			if(i%j==0){
				flag = 0;
				break;
			}
		}
		if(flag){
			prime[i] = 1;
		}
	}
	int t, n, m, s, temp, T;
	scanf("%d", &T);
	while(T--){
		memset(vis, 0, sizeof(vis));
		memset(step, 0, sizeof(step));
		scanf("%d %d", &n, &m);
		vis[n] = 1;
		queue<int> bfs;
		bfs.push(n);
		while(!bfs.empty()){
			temp = bfs.front();
			bfs.pop();
			if(temp == m){
				printf("%d\n", step[temp]);
				goto nxt;
			}
			s = step[temp];
			for(int i = 1; i<10; i++){
				t = i * 1000 + temp % 1000;
				if(prime[t] && vis[t] == 0){
					vis[t] = 1;
					bfs.push(t);
					step[t] = s + 1;
				}
			}
			for(int k = 1; k<=3; k++){
				for(int i = 0; i<10; i++){
					t = (temp / (int)pow(10, k)) * (int)pow(10, k) + temp % (int)pow(10, k-1) + i * (int)pow(10, k-1);
					if(prime[t] && vis[t] == 0){
						vis[t] = 1;
						bfs.push(t);
						step[t] = s + 1;
					}
				}
			}
		}
		nxt:;
	}
	return 0;
}