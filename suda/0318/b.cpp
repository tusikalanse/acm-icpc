#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;

int pos[10005], a[10005];
vector< pair<int, int> > ans;


void SWAP(int l, int r){
	int m = (l + r) >> 1;
	for(int i = 0; i <= m - l; i++){
		int L = l + i, R = m + i + 1;
		swap(a[L], a[R]);
		swap(pos[a[L]], pos[a[R]]);
	}
	ans.push_back(make_pair(l, r));
}

int main(){
	int n, T;
	scanf("%d", &T);
	while(T--){
		ans.clear();
		scanf("%d", &n);
		for(int i = 1; i<=n; i++){
			scanf("%d", &a[i]);
			pos[a[i]] = i;
		}
		for(int i = 1; i<=n; i++){
			if(a[i] == i) continue;
			int p = pos[i];
			int len = p - i + 1;
			if(i + 2 * (p - i) - 1 > n) {
				if(len & 1) SWAP(i + 1, p);
				else SWAP(i, p);
				p -= len/2;
			}
			SWAP(i, i + 2 * (p-i) - 1);
		}
		printf("%d\n", (int)ans.size());
		for(int i = 0; i<(int)ans.size(); i++){
			printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}
	return 0;
}