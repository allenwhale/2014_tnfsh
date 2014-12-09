#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main(int a,char **b)
{
	srand(time(0));
	int S,Q;
	sscanf(b[1],"%d",&S);
	sscanf(b[2],"%d",&Q);
	printf("%d\n",S);
	for(int i=0;i<S;i++)
	{
		printf("%d ",((long long)rand()*rand())%S);
	}
	puts("");
	printf("%d\n",Q);
	while(Q--)
		printf("%d\n",((long long )rand()*rand())%(2*S));
	return 0;
}
