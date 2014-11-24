#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<int>vc[2010];
int mx[2010],my[61000],px[20010],py[20010];
bool vis[2010];
map<int,int>mp1;
map<pair<int,int>,int>mp2;
int sn1=0,sn2=0;
int find1(int x)
{
    if(mp1.find(x)==mp1.end())mp1[x]=sn1++;
    return mp1[x];
}
int find2(pair<int,int> x)
{
    if(mp2.find(x)==mp2.end())mp2[x]=sn2++;
    return mp2[x];
}
int gcd(int a,int b)
{
    while((a%=b)&&(b%=a));
    return a+b;
}
bool match(int x)
{
    if(vis[x])return false;
    vis[x]=true;
    for(int &y:vc[x])
    {
	if(my[y]==-1||match(my[y]))
	{
	    my[y]=x;mx[x]=y;
	    return true;
	}
    }
    return false;
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
	scanf("%d %d",&px[i],&py[i]);
	int d=gcd(px[i],py[i]);
	int tx=px[i]/d,ty=py[i]/d;
	vc[find1(px[i]+py[i])].push_back(find2(make_pair(tx,ty)));
    }
    memset(mx,-1,sizeof(mx));
    memset(my,-1,sizeof(my));
    int ans=0;
    for(int i=0;i<sn1;i++)
    {
	if(mx[i]==-1)
	{
	    memset(vis,false,sizeof(vis));
	    if(match(i))ans++;
	}
    }
    printf("%d\n",ans);
    return 0;
}
