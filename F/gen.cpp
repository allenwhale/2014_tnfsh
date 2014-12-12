#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main(int a,char **b)
{
	srand(time(0)+getpid());
	int N,L;
	sscanf(b[1],"%d",&N);
	sscanf(b[2],"%d",&L);
	printf("%d\n",N);
	for(int i=0;i<N;i++)
	{
		printf("%d %d\n",1+rand()%(L+1),1+rand()%(L+1));
	}
}
