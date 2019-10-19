//http://poj.org/problem?id=1258
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int sum = 0;
int n;
int d[105];
short map[105][105];
bool vis[105];
int main()
{
	int i, j, k;
	while (cin >> n)
	{
		sum = 0;
		memset(vis, 0, sizeof(vis));

		int ok = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		for (i = 0; i < n; i++)
			d[i] = map[i][0];
		int newp = 0;
		d[newp] = 0;
		vis[newp] = true;
		while (ok++ < n-1)
		{
			int minv = 200000;
			
			for (i = 0; i < n; i++)
			{
				if (vis[i] == false && d[i] < minv)
				{
					newp = i;
					minv = d[i];
				}
			}
			//cout <<"minv" << minv << endl;
			vis[newp] = true;
			sum += minv;
			for (i = 0; i < n; i++)
			{
				if (vis[i] == false && d[i] > map[i][newp])
				{
					d[i] = map[i][newp];
				}
			}
		}
		printf("%d\n", sum);

	}
}