#include <stdio.h>

int main()
{
	int t, n;
	char ch;
	scanf("%d", &t);
	getchar();
	while(t--){
		scanf("%c %d", &ch, &n);
		getchar();
		if('a'<=ch && 'z'>=ch) printf("%d\n", n-(ch-96));
		else printf("%d\n", n+(ch-64));
	}
	return 0;
}

