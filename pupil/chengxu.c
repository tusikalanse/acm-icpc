#include <stdio.h>
int main(void)
{
	int x,y,z;
	for(x=0;x<=120;x++)
	for(y=0;y<=120;y++)
	for(z=0;z<=120;z++)
	{
	 if ((x+y+z==120) && (0.5*x+2*y+3*z==150) && (y<z))
		 printf("\n x= %d  y=%d  z=%d  \n",x,y,z);
	}
	return 0;
}
