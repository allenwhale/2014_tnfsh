#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
bool vis[1010][1010];
int main(int a,char **b)
{
	srand(time(0)+getpid());
	int N;
	sscanf(b[1],"%d",&N);
	int S;
	sscanf(b[2],"%d",&S);
	int T=10;
	while(T--)
	{
		memset(vis,false,sizeof(vis));
		printf("%d\n%d\n",N,S);
		for(int i=0;i<S;i++)
		{
			int x,y;
			do
			{
				x=rand()%N;
				y=rand()%N;
			}while(vis[x][y]);
			vis[x][y]=true;
			printf("%d %d\n",x,y);
		}
	}
}
