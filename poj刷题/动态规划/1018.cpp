//http://poj.org/problem?id=1018
#include<iostream>
#include<cstdio>
#include<cstring>
int t, n, m;
int b[101][101];
//int p[101][101];
int dp[101][1200];
int p, q;
using namespace std;
int min(int a, int b)
{
	return a < b ? a : b;
}
double max(double a, double b)
{
	return a > b ? a : b;
}
const int inf = 100000;
int main()
{
	int i, j, k;
	cin >> t;
	while (t-- > 0)
	{
		cin >> n;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < 1200; j++)
			{
				dp[i][j] = inf;
			}
		}
		for (i = 0; i < n; i++)
		{
			cin >> m;
			for (j = 0; j < m; j++)
			{
				cin >> p >> q;
				if (i == 0)
					dp[i][p] = min(dp[i][p], q);
				else
				{
					for (k = 0; k < 1200; k++)
					{
						if (dp[i - 1][k] != inf)
						{
							//cout << 1;
							//cout << dp[i - 1][120] << endl;
							if (k <= p)
							{
								dp[i][k] = min(dp[i][k], dp[i - 1][k] + q);
								//printf("gengxin dp%d i%d k%d\n", dp[i][k], i, k);
							}
							else
								dp[i][p] = min(dp[i][p], dp[i - 1][k] + q);
						}
					}
				}
			}
		}
		double res = 0;
		for (j = 0; j < 1200; j++)
		{
			if (dp[n - 1][j] != inf) {
				//cout << dp[n - 1][j] << endl;
				double tmp = double(j) / double(dp[n - 1][j]);
				res = max(res, tmp);
			}
		}
		printf("%.3f\n", res);
	}
}