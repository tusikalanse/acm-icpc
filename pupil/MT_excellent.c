#include <stdio.h>

int mat[8][8],out[64];
int n, tot = 0;

inline int abs(int x){
    return x>=0?x:-x;
}

void MT(int step, int x, int y)
{
	if (step == n*n){
		for(int i = 0;i < n*n;i++)
			printf("%d,%d%c",out[i]/10,out[i]%10,i!=n*n-1?' ':'\n');
		tot++;
		return;
    }
    for (int i = -2 ; i <= 2 ; i ++)
        for (int j = -2 ; j <= 2 ; j ++)
            if (abs(i)+abs(j)==3)
                if (x+i>=0 && x+i<n && y+j>=0 && y+j<n)
                    if (!mat[x+i][y+j])
                    {
                        out[step] = x*10 + y;
                        mat[x+i][y+j] = 1;
                        MT(step+1,x+i,y+j);
                        mat[x+i][y+j] = 0;
                    }
}

int main(void)
{
	int x, y;
	printf("please input the size of the chessboard:");
	scanf("%d", &n);
	printf("please input the coordinate of the knight(from 0 to size-1):");
	scanf("%d %d", &x, &y);
	mat[x][y]=1;
	out[0]=x*10 + y;
	MT(1, x, y);
	printf("%d\n",tot);
	return 0;
}
