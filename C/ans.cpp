#include <stdio.h>
#include <string.h>
#include <ctype.h>
char T[100010],P[1010];
char tmp[100010];
int fail[1010];
int lenT=0,lenP=0;
void convert(char pre[],char S[],int &len)
{
    len=0;
    for(int i=0;pre[i];i++)
    {
	char t=tolower(pre[i]);
	if('a'<=t&&t<='z')
	    S[len++]=t;
    }
    S[len]=0;
}
void failure(int f[],char S[],int len)
{
    f[0]=-1;
    int i=1,j=f[0];
    for(;i<len;i++)
    {
	while(j>=0&&S[i]!=S[j+1])j=f[j];
	if(S[i]==S[j+1])j++;
	f[i]=j;
    }
}
bool match(char t[],int lent,char p[],int lenp,int f[])
{
    int i=0,j=-1;
    for(;i<lent;i++)
    {
	while(j>=0&&t[i]!=p[j+1])j=f[j];
	if(t[i]==p[j+1])j++;
	if(j==lenp-1)return true;
    }
    return false;
}
int main()
{
    while(gets(tmp)!=NULL)
    {
	convert(tmp,T,lenT);
	gets(tmp);
	convert(tmp,P,lenP);
	failure(fail,P,lenP);
	if(match(T,lenT,P,lenP,fail))
	    printf("Yes\n");
	else printf("No\n");
    }
    return 0;
}
