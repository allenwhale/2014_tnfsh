#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
int main(int a,char **b)
{
	int N;
	sscanf(b[1],"%d",&N);
	double R;
	sscanf(b[2],"%lf",&R);
	double o=0.0;
	double d=3.1415926/(double)N;
	printf("%d\n",N);
	for(int i=0;i<N;i++,o+=d)
	{
		double x=R*cos(o),y=R*sin(o);
		printf("%d %d\n",(int)x,(int)y);
	}
	return 0;
}
