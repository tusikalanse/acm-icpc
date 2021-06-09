#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	char str[60];
	int i = 0;
	while(scanf("%s", str) && strcmp(str, "STOP"))
	{
		printf("#%d: ", ++i);
		vector<char> a(str, str+strlen(str));
		vector<char> b(a);
		reverse(b.begin(), b.end());
		if(a == b)
			printf("YES\n");
		else
			printf("NO\n");
	}	
	return 0;
}
