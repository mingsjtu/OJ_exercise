#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;
#define INF 0xfffffff
const int maxn=10005;
const int maxm=105;

int head[maxn];//touzhizhen ji
int dis[maxn];//juli ji
bool used[maxn];

struct edge
{
	int u,v;
	int next;
	int w;
}e[maxn];

void add(int u, int v, int w,int k)
{
	e[k].u=u;
	e[k].v=v;
	e[k].w=w;
	e[k].next=head[u];
	head[u]=k;
}
void spaf(int sta,int num)//qishi jiedian;jiedian shu
{
	int i=0,j=0;
	queue<int> q1;
	q1.push(sta);
	while(!q1.empty())
	{
		int tmp=q1.front();
		q1.pop();
		//cout<<"pop"<<tmp<<endl;
		used[tmp]=false;
		int t; 
		for(t=head[tmp];t!=0;t=e[t].next)
		{
			
			int u=e[t].u,v=e[t].v,len=e[t].w;
			//cout<<"t"<<t<<"check"<<v<<"pre"<<dis[v]<<endl;
			//cout<<"now"<<dis[u]+len<<endl;
			if(dis[u]+len<dis[v])
			{
				dis[v]=dis[u]+len;
				//cout<<used[v]<<"used[v]"<<endl;
				if(used[v]==false)
				{
					used[v]=true;
					//cout<<"push"<<v<<endl;
					q1.push(v);
				}
			}	
		}
	}
}
int main() 
{
	int N,A,B,k=0;
	scanf("%d%d%d",&N,&A,&B);
	int n1;
	//memset(v,0,sizeof(v));
	memset(head,0,sizeof(head));
	memset(used,0,sizeof(used));
	
	
	for(int i=1;i<=N;i++)
	{
		dis[i]=INF;
		scanf("%d",&n1);
		if(!n1)continue;
		int tmp;
		cin>>tmp;
		add(i,tmp,0,k++);
		for(int j=1;j<n1;j++)
		{
			cin>>tmp;
			add(i,tmp,1,k++);
		}
	}
//	for(int i=1;i<=N;i++)
//	{
//		//cout<<"head"<<head[i]<<endl;
//	}
	//cout<<"myedge"<<endl;
//	for(int i=0;i<k;i++)
//	cout<<"no"<<i<<"u"<<e[i].u<<"v"<<e[i].v<<"w"<<e[i].w<<"next"<<e[i].next<<endl;
	dis[A]=0;
	spaf(A,N);
	if(dis[B]==INF)
	cout<<-1;
	else 
	cout<<dis[B];
}
