#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
#define MAXN 100
int N,M,S;
int dis[MAXN+10][MAXN+10];
int dis2[MAXN+10][MAXN+10];
int main()
{
	memset(dis,0x3f,sizeof(dis));		
	scanf("%d %d %d",&N,&M,&S);
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		dis[a][b]=dis[b][a]=min(dis[a][b],c);
	}
	for(int i=0;i<N;i++)
		dis[i][i]=0;
	for(int k=0;k<N;k++)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(dis[i][j]<=S)
			{
				dis2[i][j]=1;
			}
			else dis2[i][j]=0x3f3f3f3f;
		}
	}
	for(int i=0;i<N;i++)
		dis2[i][i]=0;
	for(int k=0;k<N;k++)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(dis2[i][j]>dis2[i][k]+dis2[k][j])
				{
					dis2[i][j]=dis2[i][k]+dis2[k][j];
				}

			}
		}
	}
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(dis2[a][b]==0x3f3f3f3f)
			puts("Impossible");
		else printf("%d\n",dis2[a][b]);
	}
	return 0;
}
