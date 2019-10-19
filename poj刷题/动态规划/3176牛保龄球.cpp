//http://poj.org/problem?id=3176
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int map[355][355];
int dp[355][355];
int main()
{
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i + 1; j++)
			scanf("%d", &map[i][j]);
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0] = map[0][0];
	for (i = 1; i < n; i++)
	{
		for (j = 0; j <=i; j++)
		{
			if (j - 1 >= 0)
				dp[i][j] = max(dp[i - 1][j - 1]+map[i][j], dp[i][j]);
			if (j <= i - 1)
				dp[i][j] = max(dp[i - 1][j]+map[i][j], dp[i][j]);
		}
	}
	int res = 0;
	for (i = 0; i <= n-1; i++)
	{
		res = max(res, dp[n - 1][i]);
	}
	cout << res << endl;

}