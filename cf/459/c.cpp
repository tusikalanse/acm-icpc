#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;

int main(){
	char str[MAXN];
	scanf("%s", str);
	int len = strlen(str);
	int l, r, ans = 0;
	for(int i = 0; i<len; i++){
		l = r = 0;
		for (int j = i; j<len; j++)
		{
			switch(str[j]){
				case '(':
					l++;
					r++;
					break;
				case ')':
					l--;
					r--;
					break;
				case '?':
					l--;
					r++;
					break;
			}
			if(r<0) break;
			if(l<0) l+=2;
			if(l==0) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}