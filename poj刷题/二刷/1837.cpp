//http://poj.org/problem?id=1837
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int dp[22][15005];
int pian = 7502;
int c, g;
int b[22];
int w[22];
int main()
{
	cin >> c >> g;
	int i, j, k,r;
	for (i = 0; i < c; i++)
		cin >> b[i];
	for (j = 1; j <=g; j++)
		cin >> w[j];
	memset(dp, 0, sizeof(dp));
	dp[0][pian] = 1;

	for (i = 1; i <=g; i++)
	{
		for (j = 0; j <=15005; j++)
		{
			for (r = 0; r < c; r++)
			{
				dp[i][j] += dp[i - 1][j - w[i] * b[r]];
			}
			//printf("at i%d ,at j%d ,is dp%d\n", i, j, dp[i][j]);

		}
	}
	cout << dp[g][pian] << endl;
}