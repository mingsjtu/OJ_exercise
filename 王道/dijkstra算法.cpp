#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
struct edge
{
	int next, len, cost;
	void init(int n, int l1, int cost1)
	{
		next = n;
		len = l1;
		cost = cost1;
	}
}e1[1000];
vector<edge> node[1000];
int mark[1000];//shifou yijiaru
int dis[1000];//zuiduanjuli
int huafei[1000];

int main()
{
	int n, m,i=0;//n-dian ,m-bian
	int a,b,d,p;
	edge tmp;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			return 0;
		for (i = 0; i < m; i++)
		{
			cin >> a >> b >> d >> p;
			tmp.init(b, d, p);
			node[a].push_back(tmp);
			tmp.init(a, d, p);
			node[b].push_back(tmp);
		}
		cout << 1;
		int sta, en;
		cin >> sta >> en;
		int j = 0, newp = sta;
		memset(mark, 0, sizeof(mark));
		mark[newp] = 1;
		for (i = 1; i <= n; i++)
		{dis[i] = -1;
		huafei[i] = -1;
		dis[newp] = 0;
		huafei[newp] = 0;
		int curend;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j<node[newp].size(); j++)
			{
				
				curend = node[newp][j].next;
				//cout << "curend" << curend << endl;
				if (mark[curend] == 1)continue;
				if (dis[curend] == -1 || dis[curend] > dis[newp] + node[newp].at(j).len|| dis[curend] == dis[newp] + node[newp].at(j).len|| huafei[curend] > huafei[newp] + node[newp].at(j).len)
				{
					dis[curend] = dis[newp] + node[newp][j].len;
					huafei[curend] = huafei[newp] + node[newp][j].cost;

					//printf("to j%d,is %d", curend, dis[j]);
				}
			}
			int min = 0xfffffff;
			for (j = 1; j <= n; j++)
			{
				if (mark[j] == 1||dis[j]==-1)continue;
				else
				{
					if (dis[j] < min)
					{
						min = dis[j];
						newp = j;
					}
				}
			}
			mark[j] = 1;
			//printf("jiaru j=%d", j);
		}
		
		cout << dis[en];

	}
}