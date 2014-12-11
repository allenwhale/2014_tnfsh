#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main(int a,char **b)
{
	srand(time(0)+getpid());
	int Q;
	sscanf(b[1],"%d",&Q);
	printf("%d\n",Q);
	while(Q--)
	{
		int d1=(rand()&1)?-1:1,d2=(rand()&1)?-1:1;
		printf("%d %d\n",rand()%1000*d1,rand()%1000*d2);
	}
}
