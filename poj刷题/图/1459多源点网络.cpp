//http://poj.org/problem?id=1459
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n, np, nc, m;
int map[105][105];
int pre[105];
bool vis[105];

int s, e;

bool find(int s, int e)
{
	int tmp;
	memset(vis, 0, sizeof(vis));
	memset(pre, -1, sizeof(pre));
	queue<int> q1;
	while (!q1.empty())
		q1.pop();
	q1.push(s);

	tmp = s;
	int i, j, k;
	bool have = false;
	vis[s] = true;
	while (!q1.empty() && !have)
	{
		tmp = q1.front();
		q1.pop();
		for (i = 0; i < n; i++)
		{
			//printf("map tmp %d ,i %d ,%d vis %d\n", tmp, i, map[tmp][i], vis[i]);
			if (!vis[i] && map[tmp][i])
			{
				//cout << "pre" << tmp << "findi" << i << "vis" << vis[i] << endl;
				vis[i] = true;
				pre[i] = tmp;
				if (i == e)
				{
					have = true;
					break;
				}
				q1.push(i);

			}
		}
	}
	if (have)
		return true;
	else
		return false;
}
int solve()
{
	int i, j, k;
	int minv;
	int res = 0;
	while (find(s, e))
	{
		//cout << "jinru\n";

		i = e;
		minv = 10000;
		//pre[s] = -1;
		while (pre[i] != -1)
		{
			//cout << "prei" << pre[i] << endl;
			//map[pre[i]][i] -= minv;
			//map[]
			minv = min(minv, map[pre[i]][i]);
			i = pre[i];
		}
		//cout << "minv" << minv << endl;
		i = e;
		while (pre[i] != -1)
		{
			//cout << "prei" << pre[i] << endl;
			//cout << "jian\n";
			map[pre[i]][i] -= minv;
			map[i][pre[i]] += minv;
			i = pre[i];
		}
		res += minv;
	}
	return res;
}
int main()
{
	//shuru
	int i, j, k;
	char rub;
	int x, y, z;
	while (cin >> n >> np >> nc >> m)
	{
		memset(map, 0, sizeof(map));

		for (i = 0; i < m; i++)
		{
			cin >> rub >> x >> rub >> y >> rub >> z;
			if (x == y)
				continue;
			map[x][y] = z;
		}
		//cout << "get" << endl;
		n += 2;
		s = n - 2;
		e = n - 1;
		for (i = 0; i < np; i++)
		{
			cin >> rub >> x >> rub >> z;
			map[s][x] = z;
		}
		for (i = 0; i < nc; i++)
		{
			cin >> rub >> x >> rub >> z;
			map[x][e] = z;
		}
		//cout << "get" << endl;

		//cout << "get" << endl;
		int res = solve();


		cout << res << endl;
	}

}