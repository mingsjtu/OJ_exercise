#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
char map[105][105];
//bool vis[105][105];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int cnt=0;
void dfs(int x,int y)
{
	map[x][y]='.';
	//vis[x][y]=true;
	cnt++;
	for(int i=0;i<4;i++)
	{
		int x1=x+dx[i],y1=y+dy[i];
		if(map[x1][y1]=='#')
		{
			dfs(x1,y1);
		}
	}
}
int main()
{
	int n,m,k,x,y;
	int i=0,j=0,maxcnt=-1;
	cin>>n>>m>>k;
	memset(map,'.',sizeof(map));
	for(i=0;i<k;i++)
	{
		cin>>x>>y;
		map[x-1][y-1]='#';
	 }
	 for(i=0;i<n;i++)
	 {
	 	for(j=0;j<m;j++)
	 	{
	 		if(map[i][j]=='#')
	 		{
			 cnt=0;
			 dfs(i,j);
			 if(cnt>=maxcnt)
			 maxcnt=cnt;}	 
		 }
	  }
	  cout<<maxcnt; 
}
