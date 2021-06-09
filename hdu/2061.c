#include <stdio.h>

int main(){
	int t, n, flag;
	double c, score, credit, sum;
	char subject[100];	
	scanf("%d", &t);
	while(t--){
		credit = sum = flag = 0;
		scanf("%d", &n);
		while(n--){
			scanf("%s %lf %lf", subject, &c, &score);
			sum += c*score;
			credit += c;
			if (score<60) flag = 1;
		}
		if (flag) printf("Sorry!\n");
		else printf("%.2lf\n", sum/credit);
		if (t) puts("");
		}


	return 0;
}
