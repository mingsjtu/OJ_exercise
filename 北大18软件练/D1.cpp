#include<stdio.h>
#include<string.h>
#include<math.h>
char s[20],a[20],ans[20];
int len,t,vis[20];
void dfs(int step)
{
int i;
if(step==5)
{
if(((a[0]-'A'+1)-pow(a[1]-'A'+1,2)+pow(a[2]-'A'+1,3)-pow(a[3]-'A'+1,4)+pow(a[4]-'A'+1,5))==t)
{
if(strcmp(a,ans)>0)
{
strcpy(ans,a);
}
}
return;
}
for(i=0;i<len;i++)
{
if(!vis[i])
{
vis[i]=1;
a[step]=s[i];
dfs(step+1);
vis[i]=0;
}
}
}
int main()
{
int j;
while(1)
{
scanf("%d%s",&t,s);
if(t==0&&strcmp(s,"END")==0)
break;
len=strlen(s);
memset(vis,0,sizeof(vis));
memset(ans,'\0',sizeof(ans));
memset(a,'\0',sizeof(a));
dfs(0);
if(strlen(ans)==0)
printf("no solution\n");
else
puts(ans);
}
return 0;
}
