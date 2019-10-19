#define _CRT_SECURE_NO_WARNINGS
//https://blog.csdn.net/da_kao_la/article/details/82468781
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
int n, m;
int lu[1000];
int dis0[1000], dis1[1000];
struct edge
{
	int sta;
	int en;
	int len;
	
}e_m[1000];
vector<edge> node[100];
void finddis(int sta, int* dis)
{
	int i, j, k,ok=0;
	bool marked[1000];
	memset(marked, false, sizeof(marked));
	for (i = 0; i < n; i++)dis[i] = -1;
	ok = 1; marked[sta] = true;
	int newp = sta;
	dis[sta] = 0;
	while (ok <n)
	{
		cout << "newp" << newp <<"size"<<node[newp].size()<< endl;
		int min = 0xfffff;
		for(i=0;i<node[newp].size();i++)
		{
			edge e=node[newp][i];
			j = e.en;
			//cout << e.len<<endl;
			if (marked[j] == true) { cout << j <<"marked"<< endl; continue; }
			if (dis[j] == -1||dis[j]>dis[newp]+e.len)
			{
				dis[j] = dis[newp] + e.len;
				cout <<j<<" "<<dis[j] << endl;
			}
		}
		for (j = 0; j < n; j++)
		{
			if (marked[j] == true)
				continue;
			if (dis[j]!=-1&&dis[j] < min)
			{
				min = dis[j];
				newp = j;
			}
			
		}
		marked[newp] = true;
		ok++;
	}
}
int main()
{
	cin >> n >> m;
	int i,statmp,entmp,lentmp;
	for (i = 0; i < m; i++)
	{
		cin >> statmp >> entmp>>lentmp;
		edge e;
		e.sta = statmp;
		e.en = entmp; e.len = lentmp;
		e_m[i] = e;
		node[statmp].push_back(e);
		e.en = statmp; e.len = lentmp;
		node[entmp].push_back(e);
	}
	finddis(0,dis0);
	finddis(n - 1,dis1);
	int minzong = 0xfffff;
	int ressta, resen;
	for (i = 0; i < m; i++)
	{
		statmp=e_m[i].sta;
		entmp = e_m[i].en;
		lentmp = e_m[i].len;
		int tmp=(dis0[statmp] + dis1[entmp]> dis1[statmp] + dis0[entmp])? dis0[statmp] + dis1[entmp]:dis1[statmp] + dis0[entmp];
		tmp += lentmp/2;
		if (tmp < minzong)
		{
			minzong = tmp;
			ressta = statmp; resen = entmp;
		}
	}
	cout << ressta << " " << entmp << endl;

}