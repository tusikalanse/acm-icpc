#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char word[1000006];
int alphabet[30];

int main()
{
	int t, n, c, cnt, l, r, len;
	long long ans;
	scanf("%d", &t);
	while(t--){
		scanf("%s %d", word, &n);
		ans = cnt = 0;
		len = strlen(word);
		l = 0, r = 0;
		memset(alphabet, 0, sizeof(alphabet));
		while(l < len && r <= len){
			while(cnt<n && r<len) {alphabet[word[r]-'a']++; 
				if(alphabet[word[r]-'a']==1) cnt++; 
				r++;
			}
			if(cnt==n) 	ans += len-r+1;
			if(alphabet[word[l]-'a']==1) cnt--;
			alphabet[word[l]-'a']--;
			l++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}