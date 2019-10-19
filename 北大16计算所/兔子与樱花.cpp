#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,k;//点数，边数 ，寻找路径数
string didian,didian1;
map<string,int> m1;
map<int,string> m2;

struct edge
{
	int pre,dis;//终点，距离
	void init(int n,int d)
	{
		pre=n;
		dis=d;
	 }
	 bool operator<(const edge e1)
	 {
	 	return dis<e1.dis;
	 }
}e[55];
edge route[31][31];
int marked[31];
int son[31];
void solve()
{
int i,j,k;
for(k=0;k<n;k++)
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(route[k][j].dis!=-1&&route[i][k].dis!=-1&&(route[i][j].dis>route[i][k].dis+route[k][j].dis||route[i][j].dis==-1))
            {route[i][j].dis=route[i][k].dis+route[k][j].dis;
            route[i][j].pre=route[k][j].pre;
            }
        }
    }
}
}
void display(int s,int e)
{
    cout<<m2[s]<<"   "<<m2[e]<<endl;
    if(s==e)
    {
        cout<<m2[s];
        return;
    }
    display(s,route[s][e].pre);
    printf("->(%d)->",route[route[s][e].pre][e].dis);
    cout<<m2[e];
}
int main()
{

	cin>>n;
	int i,j=0,s1,e1,d1;
	m1.clear();
	for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {route[i][j].dis=0;}
            else route[i][j].dis=-1;
        }
    }
	for(i=0;i<n;i++)
	{
		cin>>didian;
		m1[didian]=i;
		m2[i]=didian;
//		m1.insert(pair<string,int>(didian,i));
//		m2.insert(pair<int,string>(i,didian));//两种都可以
	}
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>didian>>didian1>>d1;
		s1=m1[didian];
		e1=m1[didian1];
		//e[i].init(s1,e1,d1);//j边数
		edge tmpe;
		if(route[s1][e1].dis==-1||route[s1][e1].dis>d1)
		{
        tmpe.init(s1,d1);
		route[s1][e1]=tmpe;
		tmpe.init(e1,d1);
        route[e1][s1]=tmpe;
		}
	 }
	 solve();
	 cin>>k;
	 for(i=0;i<k;i++)
	 {
	 	cin>>didian>>didian1;
	 	s1=m1[didian];
	 	e1=m1[didian1];
	 	cout<<s1<<e1<<endl;
	 	display(s1,e1);
	 	cout<<endl;
	  }
 }
