#include <bits/stdc++.h>
using namespace std;

int main(){
	set<int> s;
	int n, t;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &t);
		s.insert(t);
	}
	if(s.find(0) != s.end())
		printf("%d\n", (int)s.size() - 1);
	else
		printf("%d\n", (int)s.size());
	return 0;
}