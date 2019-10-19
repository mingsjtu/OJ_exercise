#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
char map[105][105];
bool vis[105][105];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int cnt=0;
void dfs(int a,int b,int N)
{
	cnt++;
	vis[a][b]=1;
	int i=0,j=0,x1,y1;
	for(i=0;i<4;i++)
	{
		x1=a+dx[i];
		y1=b+dy[i];
		if(map[x1][y1]=='.'&&vis[x1][y1]==0)
		{
		dfs(x1,y1,N);
		}
		else continue;
	}
}
int main() 
{
	int N,i=0,j=0;//qipan daxiao
	scanf("%d",&N);
	memset(map,'#',sizeof(map));
	memset(vis,'0',sizeof(vis));
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		cin>>map[i][j]; 
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
		if(map[i][j]=='B'&&vis[i][j]==0)
		{
			dfs(i,j,N);
		}
		} 
	}
	cout<<cnt<<' '<<N*N-cnt<<endl;
}
