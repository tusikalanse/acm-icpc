#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int **list,m,n;
	double *subject,*student;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int count=0;
		subject=(double*)malloc(m*sizeof(double));
		student=(double*)malloc(n*sizeof(double));
		list=(int**)malloc(n*sizeof(int*));
		for(int i=0;i<n;i++) *(list+i)=(int*)malloc(m*sizeof(int));
		for(int i=0;i<n;i++) student[i]=0;
		for(int i=0;i<m;i++) subject[i]=0;
		for(int i=0;i<n;i++) 
			for(int j=0;j<m;j++)
				list[i][j]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",*(list+i)+j);
				*(subject+j)+=*(*(list+i)+j);
				*(student+i)+=*(*(list+i)+j);
			}
		}
		for(int i=0;i<n;i++) {*(student+i)/=m; printf("%.2f%s",*(student+i),i==n-1?"\n":" ");}
		for(int i=0;i<m;i++) {*(subject+i)/=n; printf("%.2f%s",*(subject+i),i==m-1?"\n":" ");}
		for(int i=0;i<n;i++)
		{
			int flag=1;
			for(int j=0;j<m;j++)
			{
				if (*(*(list+i)+j)<*(subject+j)){flag=0;break;}
			}
			if (flag) count++;
		}
		printf("%d\n\n",count);
	}	
	return 0;
}
