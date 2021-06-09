#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

const int N = 16e6 + 10;

int n, nc;
char str[N];
bool Hash[N];
int num[128];

int main(){
	while (~scanf("%d %d", &n, &nc)){
		scanf("%s", str);
		memset(Hash, 0, sizeof(Hash));
		int ans = 0, sum = 0, tot = 1, cnt = 0, len = strlen(str);
		for (int i = 0; i < len && cnt != nc; i++){
			if (!num[str[i]])
				num[str[i]] = cnt++;
		}
		for (int i = 0; i < n; i++){
			sum = sum * nc + num[str[i]];
			tot *= nc;
		}
		tot /= nc;
		for (int i = 0; i <= len - n; i++){
			if(!Hash[sum]){
				ans++;
				Hash[sum] = true;
			}
			sum = (sum - tot * num[str[i]]) * nc + num[str[i + n]];
		}
		printf("%d\n", ans);
	}
	return 0;
}