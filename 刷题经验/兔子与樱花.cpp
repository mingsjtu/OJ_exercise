//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
#include<stack>
#include<vector>
using namespace std;
int mm[35][35];
int n, m;
map<string,int> m1;
int lu[35][35];
string m2[35];
stack<int> s1;
struct edge
{
	int en, w;
};
vector<edge> v[100];
bool vis[100];
int dis[100];
int prev1[100];
void dfs(int s,int x)
{
	while (!s1.empty())
		s1.pop();
	while(prev1[x] != -1)
	{
		s1.push(x);
		x = prev1[x];
	}
	int cur,cur1;
	cur = s;
	cout << m2[cur];
	while (!s1.empty())
	{
		cur1 = s1.top();
		s1.pop();
		printf("->(%d)->", mm[cur][cur1]);
		cout << m2[cur1];
		cur = cur1;
	}
	cout << "\n";
}
void dij(int sta,int end)
{
	int i, j, k, newp;
	newp = sta;
	memset(vis, 0, sizeof(vis));
	memset(dis, -1, sizeof(dis));
	memset(prev1, -1, sizeof(prev1));
	vis[newp] = 1;
	dis[newp] = 0;
	int ok = 1;
	edge tmpedge;
	int tmpen;
	while (vis[end] == 0)
	{
		for (i = 0; i < v[newp].size(); i++)
		{
			tmpedge = v[newp][i];
			tmpen = tmpedge.en;
			if (vis[tmpen])
				continue;
			if (dis[tmpen] == -1 || dis[tmpen] > dis[newp]+tmpedge.w)
			{
				dis[tmpen] = dis[newp] + tmpedge.w;
				prev1[tmpen] = newp;
			}
		}
		int minv = 1000000;
		for (i = 0; i < n; i++)
		{
			if (vis[i])
				continue;
			if (dis[i] != -1 && dis[i] < minv)
			{
				minv = dis[i];
				newp = i;
			}
		}
		vis[newp] = 1;
	}
}
int main()
{
	int i, j, k,d1,d2;
	cin >> n;
	memset(mm, 0, sizeof(mm));
	memset(lu, -1, sizeof(lu));
	string didian1,didian2;
	for (i = 0; i < n; i++)
	{
		cin >> didian1;
		m2[i] = didian1;
		m1[didian1] = i;
	}
	cin >> m;
	edge tmpedge;
	while (m--)
	{
		cin >> didian1 >> didian2>>j;
		d1 = m1[didian1];
		d2 = m1[didian2];
		mm[d1][d2] = mm[d2][d1] = j;
		tmpedge.en = d2;
		tmpedge.w = j;
		v[d1].push_back(tmpedge);
		tmpedge.en = d1;
		v[d2].push_back(tmpedge);
	}
	int t;
	cin >> t;
	while (t--)
	{
		cin >> didian1 >> didian2;
		d1 = m1[didian1];
		d2 = m1[didian2];
		dij(d1,d2);
		dfs(d1,d2);
	}
}