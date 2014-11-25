#include <stdio.h>
#include <string.h>
#include <complex>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
const double eps=1e-15;
const double pi=M_PI;
typedef complex<double> cD;
bool A[100010],B[100010],C[100010];
cD AA[140010*8],BB[140010*8];
int N;
void convert(bool p[],cD f[],int sz)
{
    for(int i=0;i<sz;i++)
	f[i]=cD((double)((int)p[i]),0);
}
void reverse(cD f[],int sz)
{
    for(int i=1,j=0;i<sz;i++)
    {
	for(int k=sz>>1;!((j^=k)&k);k>>=1);
	if(i>j)swap(f[i],f[j]);
    }
}
void FFT(cD f[],int sz,bool flag)
{
    for(int k=2;k<=sz;k<<=1)
    {
	double omega=-2.0*pi/k;
	if(flag)omega=-omega;
	cD dtheta=cD(cos(omega),sin(omega));
	for(int j=0;j<sz;j+=k)
	{
	    cD theta=cD(1.0,0.0);
	    for(int i=j;i<j+k/2;i++)
	    {
		cD a=f[i];
		cD b=f[i+k/2]*theta;
		f[i]=a+b;
		f[i+k/2]=a-b;
		theta*=dtheta;
	    }
	}
    }
}
int main()
{
    memset(A,false,sizeof(A));
    memset(B,false,sizeof(B));
    memset(C,false,sizeof(C));
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
	int tmp;
	scanf("%d",&tmp);
	A[tmp]=true;
    }
    for(int i=0;i<N;i++)
    {
	int tmp;
	scanf("%d",&tmp);
	B[tmp]=true;
    }
    int sz=262144;
    convert(A,AA,100000);
    convert(B,BB,100000);
    for(int i=100000;i<sz;i++)AA[i]=cD(0,0),BB[i]=cD(0,0);
    reverse(AA,sz);
    reverse(BB,sz);
    FFT(AA,sz,0);
    FFT(BB,sz,0);
    for(int i=0;i<sz;i++)
	AA[i]=AA[i]*BB[i]/(double)N;
    reverse(AA,sz);
    FFT(AA,sz,1);
    for(int i=0;i<=200000;i++)
	if(AA[i].real()>=1.0)
	    C[i]=true;
    int Q;
    scanf("%d",&Q);
    while(Q--)
    {
	int q;
	scanf("%d",&q);
	if(q<=200000&&C[q])puts("yes");
	else puts("no");
    }
    return 0;
}
