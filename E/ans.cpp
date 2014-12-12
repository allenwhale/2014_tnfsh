#include <stdio.h>
#include <string.h>
int board[1010][1010];
int dx[][4]={	{0,0,0,0},  {-2,-1,1,2},{-2,-1,1,2},{-2,-1,1,2},
	{0,0,0,0},   {0,0,0,0},   {-3,-2,-1,1},{1,-1,-2,-3},
	{-3,-2,-1,1},{-3,-2,-1,1},{3,2,1,-1},{3,2,1,-1},
	{0,0,0,0},    {0,0,0,0},{1,2,3,4},{-1,-2,-3,-4},
	{1,2,3,4},{1,2,3,4},    {-1,-2,-3,-4},{-1,-2,-3,-4}};
int dy[][4]={	{-2,-1,1,2},{0,0,0,0},  {-2,-1,1,2},{2,1,-1,-2},
	{-3,-2,-1,1},{1,-1,-2,-3},{0,0,0,0},   {0,0,0,0},
	{-3,-2,-1,1},{3,2,1,-1},  {3,2,1,-1},{-3,-2,-1,1},
	{-1,-2,-3,-4},{1,2,3,4},{0,0,0,0},{0,0,0,0},
	{1,2,3,4},{-1,-2,-3,-4},{-1,-2,-3,-4},{1,2,3,4}};
int N;
bool isin(int x,int y)
{
	return x>=0&&y>=0&&x<N&&y<N;
}
bool check(int x,int y,int n)
{
	for(int i=0;i<20;i++)
	{
		bool tf=true;
		for(int j=0;j<4;j++)
		{
			int tx=x+dx[i][j],ty=y+dy[i][j];
			if(!(isin(tx,ty)&&board[tx][ty]==board[x][y]))
				tf=false;
		}
		if(tf)return true;
	}
	return false;
}
int px[1000010],py[1000010];
int main()
{
	while(~scanf("%d",&N))
	{
		int step;
		scanf("%d",&step);
		for(int i=0;i<step;i++)
		{
			scanf("%d %d",&px[i],&py[i]);
		}
		memset(board,-1,sizeof(board));
		for(int i=0;i<step;i++)
		{
			if(board[px[i]][py[i]]!=-1)
			{
				puts("invalid");
				goto end;
			}
			board[px[i]][py[i]]=i&1;
			if(check(px[i],py[i],i&1))
			{
				printf("%c wins\n",(i&1)?'B':'A');
				goto end;
			}
		}
		puts("not yet");
end:;
	}
	return 0;
}
