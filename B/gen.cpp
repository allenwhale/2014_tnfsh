#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main(int a,char **b)
{
	srand(time(0)+getpid());
	int N,V;
	sscanf(b[1],"%d",&N);
	sscanf(b[2],"%d",&V);
	printf("%d %d\n",N,V);
	for(int i=0;i<N;i++)
	{
		printf("%d %d\n",rand()%1000+1,rand()%V+1);
	}
	return 0;
}
