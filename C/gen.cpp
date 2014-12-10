#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
char s[100010],s2[100010];
int T,S,C;
void chaos()
{
	for(int i=0;i<100;i++)
	{
		int idx=rand()%S;
		if(rand()&1)s[idx]=toupper(s[idx]);
		else s[idx]=tolower(s[idx]);
	}
}
void wrong()
{
	srand(time(0)+getpid());
	memcpy(s2,s,sizeof(s));
	for(int i=0;i<5;i++)
	{
		int idx=rand()%S;
		if(rand()&1)s2[idx]=(rand()&1)?' ':'%';
		else
		{
			s2[idx]='a'+rand()%26;
		}
	}
}
int main(int a,char **b)
{
	srand(time(NULL));
	sscanf(b[1],"%d",&T);
	sscanf(b[2],"%d",&S);
	//sscanf(b[3],"%d",&C);
	memset(s,'a',sizeof(char)*S);
	s[S]=0;
	int N=10;
	while(N--)
	{
		if(rand()&1)
		{
			int cnt=T/S;
			for(int i=0;i<cnt-1;i++)
			{
				chaos();
				printf("%s\bb",s);
			}
			printf("%s\n",s);
			puts(s);
		}
		else
		{
			int cnt=T/S;
			for(int i=0;i<cnt;i++)
			{
				wrong();
				printf("%s",s2);
			}
			printf("\n%s\n",s);
		}
	}
	return 0;
}
