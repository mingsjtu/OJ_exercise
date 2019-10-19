//http://poj.org/problem?id=1015
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[22][805];
int sum[22][805];
int fix = 400;
int n,m;
int d[202];
int p[202];
int v[202];
int s[202];
int path[22][805];
bool select(int k, int i, int j)
{
	if (path[i][j] == k)
		return false;
	if (i == 1)
	{
		if (path[i][j] != k)
			return true;
		else
			return false;
	}
	return select(k,i-1,j - v[path[i][j]]);
}


int main()
{
	int i,j,k;
	while (cin >> n >> m)
	{
		if (!(n || m))
			break;
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &d[i], &p[i]);
			s[i] = d[i] + p[i];
			v[i] = d[i] - p[i] + fix;
			//cout << i << " " << s[i] << "  " << v[i] << endl;
		}
		memset(dp, -1, sizeof(dp));
		dp[0][0] =0;
		memset(path, -1, sizeof(path));
		
		for (i = 1; i <= m; i++)
		{
			for (j = 0; j <= fix * 2; j++)
			{
				for (k = 0; k < n; k++)
				{
					if (j-v[k]>=0 && dp[i - 1][j-v[k]] >= 0)
					{
						printf(">0 i %d k%d j-v[k] %d\n", i,k, j - v[k]);
						if (select(k, i, j))
						{
							printf("select i %d k%d j%d\n", i, k, j);
							if (dp[i][j] < dp[i - 1][j - v[k]] + s[k])
							{
								dp[i][j] = dp[i - 1][j - v[k]] + s[k];
								path[i][j] = k;
							}
							printf("update i %d k%d j%d dp%d path %d\n", i,k, j-fix, dp[i][j], path[i][j]);
						}
					}

				}
			}
		}
		int res=0;
		for (j = fix; j <= fix * 2; j++)
		{
			if (dp[m][j] > 0)
			{
				res = j;
				break;
			}
		}
		for (j = fix; j >= fix-res; j--)
		{
			if (dp[m][j] > 0)
			{
				res = j;
				break;
			}
		}
		cout << dp[m][res] << endl;
		cout << dp[m][res] + res - fix << endl;
		cout << dp[m][res] - res - fix << endl;


	}

	

}