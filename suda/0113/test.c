#include <stdio.h>

int main()
{
	int n, x, a[100];
	while(~scanf("%d", &n)){
		for(int i = 0; i<n; i++)
			scanf("%d", &a[i]);
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++)
				if(a[i]<a[j]){
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
		for(int i = 0; i<n; i++)
			printf("a[%d] = %d", i, a[i]);
	}
	return 0;
}
