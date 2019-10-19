//http://poj.org/problem?id=2488
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int dx[]={-1,1,-2,2,-2,2,-1,1};
int dy[]={-2,-2,-1,-1,1,1,2,2};
int routex[26];
int routey[26];
int p,q;
int n;
int marked[27][27];
bool flag;
void dfs(int x,int y,int d)
{
    routex[d]=x;
    routey[d]=y;
    int i;
     printf("test %d %d %d\n",x,y,d);
    if(d==p*q-1)
    {
    flag=true;
    return;}
    for(i=0;i<8;i++)
    {
        int nx=x+dx[i];
        int ny=x+dy[i];
        if(nx<0||nx>=p||ny<0||ny>=q)
            continue;
        if(marked[nx][ny]==1)
            continue;
        marked[nx][ny]=1;
        dfs(nx,ny,d+1);
        if(flag)break;
        marked[nx][ny]=0;
    }
}
void solve()
{
    int i,j,k;
    memset(marked,0,sizeof(marked));
    marked[0][0]=1;
    flag=false;
    dfs(0,0,0);
    if(flag)
    cout<<"ok"<<endl;
    for(i=0;i<p*q;i++)
    {
        cout<<char(routey[i]+'A')<<routex[i]+1;
    }
}


int main()
{
    cin>>n;
    int i,j,k;
    for(i=0;i<n;i++)
    {
        cin>>p>>q;
        solve();
    }
}
