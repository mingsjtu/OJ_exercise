//http://poj.org/problem?id=1976
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int dp[50005][4];
int a[50005];
int sum[50005];
int main()
{
	int i, j, k, t, n,m;
	cin >> t;
	while (t--)
	{
		memset(sum, 0, sizeof(sum));
		cin >> n;
		sum[0] = 0;
		for (i = 1; i <=n; i++)
		{
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		cin >> m;
		for (i = 1; i <= m; i++)
		{
			for (j = 1; j <= 3; j++)
				dp[i][j] = sum[i];
		}
		int maxn = 0;
		for (i = m+1; i <=n; i++)
		{
			for (j = 1; j <= 3; j++)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + sum[i] - sum[i - m]);
			}
			if (dp[i][3] > maxn)
				maxn = dp[i][3];
		}
		cout << maxn << endl;
	}
}