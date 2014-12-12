#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main(int a,char **b)
{
	srand(time(0)+getpid());
	int N,M,S;
	sscanf(b[1],"%d",&N);
	sscanf(b[2],"%d",&M);
	sscanf(b[3],"%d",&S);
	printf("%d %d %d\n",N,M,S);
	int Q;
	sscanf(b[4],"%d",&Q);
	for(int i=0;i<M;i++)
	{
		printf("%d %d %d\n",rand()%N,rand()%N,rand()%1900+100);
	}
	printf("%d\n",Q);
	while(Q--)
		printf("%d %d\n",rand()%N,rand()%N);
	return 0;
}
