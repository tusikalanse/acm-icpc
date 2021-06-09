#include <bits/stdc++.h>
using namespace std;

const int N = 5010;

int n, G[N][N], a[N];

int vis[N], match[N], tot, mid, mark;
int cnt;
vector<int> S, T, eg[N];

int dfs(int s) {
    for(int i = 1; i <= n; ++i){
    	if(!G[s][i]) continue;
        if(mark != vis[i]){
            vis[i] = mark;
            if(match[i] == -1 || dfs(match[i])){
                match[i] = s;
                return 1;
            }
        }
    }
    return 0;    
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			int x = a[i] ^ a[j];
			if((x & (x - 1)) == 0) {
				if(__builtin_parity(a[i]))
					G[i][j] = 1;
				else
					G[j][i] = 1;
				eg[i].push_back(j);
				eg[j].push_back(i);
			}
		}
	}
	memset(match, -1, sizeof(match));
	for(int i = 1; i <= n; ++i) {
		if(__builtin_parity(a[i])) {
			mark++;
			tot += dfs(i);
		}
	}
	printf("%d\n", n - tot);
	++mark;
	for(int i = 1; i <= n; ++i) {
		if(match[i] != -1)
			match[match[i]] = i;
	}
	for(int i = 1; i <= n; ++i) {
		if(match[i] == -1) {
			vis[i] = mark;
			S.push_back(i);
		}
	}
	for(auto s: S) {
		cout << "s = " << s << endl;
		for(auto t: eg[s]) {
			if(vis[t] != mark) {
				vis[t] = mark;
				T.push_back(t);
			}
		}
	}
	for(auto t: T) {
		if(match[t] != -1 && vis[match[t]] != mark) {
			vis[match[t]] = mark;
			S.push_back(match[t]);
		} 
	}
	cout << T.size() << endl;
	cout << S.size() << endl;
	return 0;
}