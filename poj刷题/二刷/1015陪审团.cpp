//http://poj.org/problem?id=1015
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int n, m;
int p[205], d[205];
int det[205], sum[205];
int dp[205][805];
bool vis[205];
const int fix = 400;
int path[205][805];
int sorted[30];
bool select(int i, int j, int k)
{
	int a=path[i][j];
	if (i > 0&&path[i][j] != k)
	{
		j = j - det[path[i][j]];
		i--;
	}
	if (i > 0)
		return false;
	return true;
}
int main()
{
	int i, j, k;
	int t = 0;
	while (scanf("%d %d", &n, &m))
	{
		if (n == 0 && m == 0)
			break;
		t++;
		for (i = 1; i <=n; i++)
		{
			cin >> p[i] >> d[i];
			det[i] = p[i] - d[i];
			sum[i] = p[i] + d[i];
			//printf("det %d is %d \n", i, det[i]);
		}
		memset(sorted, 0, sizeof(sorted));
		memset(path, 0, sizeof(path));
		memset(dp, -1, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		dp[0][fix] = 0;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j <= 2 * fix; j++)
			{

				if (dp[i][j] >=0)
				{
					//printf("i%d j%d\n", i, j);

					for (k = 1; k <=n; k++)
					{
						if (dp[i + 1][j + det[k]] < dp[i][j] + sum[k]&&select(i, j, k))
						{
							//printf("select %d for i%d j%d\n", k, i, j);
							//if()
							dp[i + 1][j + det[k]] = dp[i][j] + sum[k];
							path[i + 1][j + det[k]] = k;
							//dp[i + 1][j - det[k]] = dp[i][j] + sum[k];
						}
					}
				}
			}
		}
		int resd = 0, ress = 0;
		for (i = 0; i <= fix; i++)
		{
			if (dp[m][fix - i] > 0 || dp[m][fix + i] > 0)
			{
				resd = i;
				break;
			}
		}
		ress = max(dp[m][fix - i], dp[m][fix + i]);
		printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n", t,(ress + resd) / 2, (ress - resd) / 2);
		int m1 = m;
		int dis = 0;
		while (m1 > 0)
		{
			sorted[m1-1] = path[m1][resd + fix-dis];
			//printf("search m%d det%d is%d\n", m1, fix - dis + resd,sorted[m1-1]);
			dis = det[sorted[m1 - 1]];
			//printf("dis%d\n", det[sorted[m1-1]]);
			m1--;


		}
		sort(sorted, sorted + m);
		for (i = 0; i < m; i++)
		{
			cout << sorted[i] << ' ';
		}
		cout <<endl;
	}

}