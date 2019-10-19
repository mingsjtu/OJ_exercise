//https://blog.csdn.net/da_kao_la/article/details/82425671
#include<iostream>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
struct edge
{
	int en;
	int len;
};
int num;
vector<edge> node[100];
map<int,int> dian;
bool marked[100];
int dis[100];
int solve(int s,int e)
{
	printf("s %d e %d", s, e);
	int i;
	memset(marked, 0, sizeof(marked));
	for (i = 0; i < 100; i++)
		dis[i] = -1;
	int np = s,j=0;
	marked[np] = 1;
	int min = 9999999;
	dis[s] = 0;
	while (marked[e] == 0) {
		min = 999999;

		for (j = 0; j < node[np].size(); j++)
		{
			int e1 = node[np][j].en, d = node[np][j].len;
			if (marked[e1] == 1)continue;

			if (dis[e1] == -1 || dis[e1] > dis[np] + d)
			{

				dis[e1] = dis[np] + d;
			}

		}
		for (i = 0; i < num; i++)
		{
			if (marked[i] == 1 || dis[i] == -1) { cout << i<<dis[i]<< endl; continue; }
			if (dis[i] < min)
			{
				min = dis[i];
				np = i;
			}
		}
		marked[np] = 1;
	}
	return dis[e];
	
}
int main()
{
	int s1, e1, d1,idx=0;

	while (scanf_s("%d %d", &s1, &e1))
	{
		cin>>d1;
		if (d1 == 0)break;
		if (dian.find(s1) == dian.end())
		{
			dian[s1]=idx;

			idx++;
			
		}
		if (dian.find(e1) == dian.end())
		{
			dian[e1] = idx;

			idx++;
		}
		edge edge1;
		edge1.en = dian[e1]; edge1.len = d1;
		
		node[dian[s1]].push_back(edge1);
		edge edge2;
		edge2.en = dian[s1]; edge2.len = d1;
		node[dian[e1]].push_back(edge2);
		
//		if()
	}
	num = idx;//dian de shumu
	int s=dian[s1], e=dian[e1];
	int dis=solve(s,e);
	cout << dis;
}