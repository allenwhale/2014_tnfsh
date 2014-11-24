#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const double eps=1e-15;
struct obj
{
    double w,p;
    obj(){}
    obj(double _w,double _p)
    {
        w=_w,p=_p;
    }
    bool operator < (const obj& n)const
    {
        return n.w/n.p>w/p;
    }
}o[10010];
int main()
{
    int N;
    double V;
    scanf("%d %lf",&N,&V);
    for(int i=0;i<N;i++)
        scanf("%lf %lf",&o[i].w,&o[i].p);
    sort(o,o+N);
    double ans=0.0;
    for(int i=0;i<N&&fabs(V)>eps;i++)
    {
        if(o[i].p>=V)
        {
            ans+=(V*o[i].w)/o[i].p;
            V=0;
        }
        else
        {
            ans+=o[i].w;
            V-=o[i].p;
        }
    }
    printf("%.3f\n",ans);
    return 0;
}
