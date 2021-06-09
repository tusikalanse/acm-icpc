#include <stdio.h>
#include <string.h>
char a[100000], b[100000], temp[100000];
int main()
{
	int l, flag, f;
	while(~scanf("%s %s", a, b)){
		 flag = 0;
		 f = 0;
		 for(;;)
			 if (a[0]!='0') break;
			 else {
				 strcpy(temp, &a[1]);
				 strcpy(a, temp);
			 }
		 for(;;)
			if (b[0]!='0') break;
			else {
				strcpy(temp, &b[1]);
				strcpy(b, temp);
			 }
		/*printf("%s %s", a, b);*/
		 l = strlen(a);
		 l = l>strlen(b)?strlen(b):l;
		 for(int i = 0; i<l; i++){ if(a[i]!=b[i]) {flag = 1; break;} else if(a[i]=='.') f = 1;}
		 if (l == strlen(a)) for(int i = l; i<strlen(b); i++) { 
								if(!f) 
									if(b[i] != '.') {flag = 1; break;}
									else f = 1;
								else if(b[i]!='0') {flag = 1; break;}}
		else for(int i = l; i<strlen(a); i++) { 
								if(!f) 
									if(a[i] != '.') {flag = 1; break;}
									else f = 1;
								else if(a[i]!='0') {flag = 1; break;}		
		 }
		 
		 
		 
		 if(flag) puts("NO");
		 else puts("YES");
		 
	}
	return 0;
}

