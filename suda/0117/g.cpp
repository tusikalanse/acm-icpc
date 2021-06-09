#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
string str[100006];
int main(){
	int t, n;
	scanf("%d", &t);
	while(t--){
		int len = 1;
		scanf("%d", &n);
		for(int i = 1; i<=n; i++){
			cin >> str[i];
			if (str[i].length() > str[len].length()) len = i;
		}
		int flag = 1;
		for( int i = 1; i<=n; i++){
			if(str[len].find(str[i]) == str[len].npos){
				printf("No\n");
				flag = 0;
				break;
			}
		}
		if (flag) cout << str[len] << endl;		
	}
	
	
	return 0;
}
