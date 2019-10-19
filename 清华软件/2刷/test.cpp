#define _CRT_SECURE_NO_WARNINGS
// 用堆优化的Dijkstra算法算两遍，分别从源点和汇点开始算，
// 算得d1数组记录所有点到源点的距离，d2数组记录所有点到汇点的距离
// 遍历m条边，ans = min(min(d1[u] + d2[v], d1[v] + d2[u]) + len[u,v])

#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>

const int NMAX = 1000005, INF = 0x3f3f3f3f;

struct toEdge {
	int v, t;

	toEdge(int vv, int tt) : v(vv), t(tt) {}
	toEdge(void) {}
};

struct cmp {
	bool operator() (const toEdge& a, const toEdge& b)
	{
		return a.t > b.t;
	}
};

struct Edge {
	int u, v, t;

	Edge(int uu, int vv, int tt) : u(uu), v(vv), t(tt) {}
	Edge(void) {}
}edges[NMAX];


int n, m;
std::vector<toEdge> E[NMAX];	// 邻接表
int d[NMAX] = {};
int vis[NMAX] = {};
int d1[NMAX] = {};			// 从节点1出发到各点的最短路
int d2[NMAX] = {};			// 从节点2出发到各点的最短路

void dijkstra(int src)		// 用Dijkstra算法求从src出发到各点的最短路
{
	int i, v, t;
	std::priority_queue<toEdge, std::vector<toEdge>, cmp> q;
	memset(vis, 0, sizeof(vis));
	memset(d, 0x3f, sizeof(d));
	vis[src] = 1;
	d[src] = 0;
	for (i = 0; i < E[src].size(); i++)
	{
		q.push(toEdge(E[src].at(i).v, E[src].at(i).t));
	}
	while (!q.empty())
	{
		v = q.top().v;
		while (vis[v])
		{
			q.pop();
			if (q.empty())
			{
				return;
			}
			v = q.top().v;
		}
		vis[v] = 1;
		t = q.top().t;
		d[v] = t;
		for (i = 0; i < E[v].size(); i++)
		{
			if (!vis[E[v].at(i).v] && d[E[v].at(i).v] > E[v].at(i).t + t)
			{
				q.push(toEdge(E[v].at(i).v, E[v].at(i).t + t));
			}
		}
	}
}

int main()
{

	scanf("%d%d", &n, &m);
	int i = 0, u, v, t, minv = INF, minid = -1;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &t);
		E[u].push_back(toEdge(v, t));
		E[v].push_back(toEdge(u, t));
		edges[i] = Edge(u, v, t);
	}
	dijkstra(1);
	memcpy(d1, d, sizeof(d));
	dijkstra(n);
	memcpy(d2, d, sizeof(d));
	for (i = 0; i < m; i++)
	{
		u = edges[i].u;
		v = edges[i].v;
		t = edges[i].t;
		if (t / 2 + d1[u] + d2[v] < minv)			// 取std::min(d1[u] + d2[v], d1[v] + d2[u])
		{
			minv = t / 2 + d1[u] + d2[v];
			minid = i + 1;
		}
		else if (t / 2 + d1[v] + d2[u] < minv)
		{
			minv = t / 2 + d1[v] + d2[u];
			minid = i + 1;
		}
	}
	printf("%d %d", minid, minv);
	return 0;
}
