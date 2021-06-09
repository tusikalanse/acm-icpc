#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int n, nc;
char str[16000007];
bool hash[16000007];
int num[128];

int main(){
	while(~scanf("%d %d", &n, &nc)){
		scanf("%s", str);
		memset(hash, 0, sizeof(hash));
		int ans = 0, sum = 0, tot = 1, cnt = 0, len = strlen(str);
		for(int i = 0; i < len && cnt != nc; i++){
			if(!num[str[i]])
				num[str[i]] = cnt++;
		}
		for(int i = 0; i < n; i++){
			sum = sum * nc + num[str[i]];
			tot *= nc;
		}
		tot /= nc;
		for(int i = 0; i <= len - n; i++){
			if(!hash[sum]){
				ans++;
				hash[sum] = true;
			}
			sum = (sum - tot*num[str[i]]) * nc + num[str[i+n]];
		}
		printf("%d\n", ans);
	}
	return 0;
}