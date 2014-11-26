#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>vc[200010];
int dp[200010],f[200010];
unsigned MOD,A,B;
int Rand()
{
	return (int)(A=(((A<<4)|B)%MOD));
}
int M;
map<int,int>mp;
int sn=0;
int find(int x)
{
	if(mp.find(x)==mp.end())mp[x]=sn++;
	return mp[x];
}
int dfs(int x)
{
	if(dp[x]!=-1)return dp[x];
	dp[x]=1;
	for(int &v:vc[x])
	{
		dp[x]=max(dp[x],1+dfs(v));
	}
	return dp[x];
}
int findx(int x)
{
	return x==f[x]?x:f[x]=find(f[x]);
}
int main()
{
	scanf("%u %u %u %d",&A,&B,&MOD,&M);
	for(int i=0;i<=min((int)MOD,M*2);i++)
		f[i]=i;
	for(int i=0;i<M;i++)
	{
		int a,b;
		a=Rand();b=Rand();
		int ta,tb;
		ta=find(a),tb=find(b);
		if(findx(ta)==findx(tb))continue;
		vc[ta].push_back(tb);
	}
	memset(dp,-1,sizeof(dp));
	int ans=0;
	for(int i=0;i<sn;i++)
		ans=max(ans,dfs(i));
	printf("%d\n",ans);
	return 0;
}
