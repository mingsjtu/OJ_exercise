//http://poj.org/problem?id=2485
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n;
short map[505][505];
int d[505];
bool vis[505];
int ok;
int main()
{
	cin >> t;
	int i,j,k;
	while (t--)
	{
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		/*for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("map %d ", map[i][j]);
			}
			cout << endl;
		}*/

		d[0] = 0;
		int newp = 0;
		memset(vis, 0, sizeof(vis));
		vis[0] = true;
		int minv = 100000;
		ok = 1;
		int res = 0;
		int prep = 0;
		for (i = 0; i < n; i++)
			d[i] = map[i][0];
		while (ok < n)
		{
			minv = 100000;
			prep = newp;
			for (i = 0; i < n; i++)
			{
				
				if (vis[i] == false&&d[i] < minv)
				{
					minv = d[i];
					newp = i;
				}
				//
			}
			//printf("newp %d ,minv %d\n",newp,minv);

			if (res < minv)
				res = minv;
			vis[newp] = true;
			ok++;
			for (i = 0; i < n; i++)
			{
				if (vis[i] == false && d[i] > map[i][newp])
					d[i] = map[i][newp];
			}
			//printf("newp%d  , dis %d\n", prep, minv);

		}
		
		printf("%d\n", res);
	}
}