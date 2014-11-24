#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
struct point
{
    ll x,y;
    point(){}
    point(ll _x,ll _y)
    {
	x=_x,y=_y;
    }
}p[1010],X;
point operator - (point a,point b)
{
    return point(a.x-b.x,a.y-b.y);
}
ll cross(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
int Cross(point a,point b)
{
    ll t=cross(a,b);
    if(t==0ll)return 0;
    else if(t<0ll)return -1;
    return 1;
}
bool inL(point a,point b,point x)
{
    if(!(x.x<=max(a.x,b.x)&&x.x>=min(a.x,b.x)
		&&x.y<=max(a.y,b.y)&&x.y>=min(a.y,b.y)))return false;
    return cross(a-x,b-x)==0;
}
int intersect(point a,point b,point x,point y)
{
    int ta=Cross(x-a,y-a)*Cross(x-b,y-b);
    int tb=Cross(a-x,b-x)*Cross(a-y,b-y);
    return ta<0&&tb<0;
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
	scanf("%lld %lld",&p[i].x,&p[i].y);
    p[N]=p[0];
    int Q;
    scanf("%d",&Q);
    while(Q--)
    {
	scanf("%lld %lld",&X.x,&X.y);
	bool ans=false;
	for(int i=0;i<N;i++)
	{
	    if(inL(p[i],p[i+1],X))
	    {
		puts("boundary");
		ans=true;
		break;
	    }
	}
	if(ans)continue;
	point d(X.x+100ll*llabs(X.x-p[0].x),X.y+100ll*llabs(X.y-p[0].y)+1);
	int cnt=0;
	for(int i=0;i<N;i++)	
	{
	    cnt+=intersect(p[i],p[i+1],X,d);
	}
	if(cnt&1)puts("inside");
	else puts("outside");
    }
    return 0;
}
