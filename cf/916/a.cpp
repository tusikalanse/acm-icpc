#include <bits/stdc++.h>
using namespace std;

int main(){
	int hh, mm, delta, ans = 0;
	scanf("%d %d %d", &delta, &hh, &mm);
	while(true){
		if(hh%10 == 7 || mm%10 == 7){
			printf("%d\n", ans);
			return 0;
		}
		else{
			ans++;
			mm -= delta;
			if(mm < 0) {
				hh--;
				mm += 60;
			}
			if(hh<0) hh += 24;
		}
	}
	return 0;
}