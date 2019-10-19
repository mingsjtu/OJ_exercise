//http://bailian.openjudge.cn/practice/1050
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int a[505][505],s[505][505],temp[505],dp[505];
int res;
int main()
{
	int n;
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int maxn = -31750005;
	s[0][0] = a[0][0];
	dp[0] = a[0][0];
	maxn = dp[0];
	//printf("line 0\n");
	//printf("dp 0 is %d\n", dp[0]);
	for (i = 1; i < n; i++)
	{
		s[i][0] = a[i][0];
		dp[i] = max(dp[i - 1] + a[i][0], a[i][0]);
		//printf("dp %d is %d\n", i, dp[i]);
		maxn = max(maxn, dp[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			s[i][j] = s[i][j - 1] + a[i][j];

		}
	}
	for (i = 0; i < n-1; i++)
	{
		//printf("line -1 to %d \n",i);
		for (k = 0; k < n; k++)
		{
			temp[k] = s[k][i];
			//printf("temp %d is %d\n", k, temp[k]);
		}
		dp[0] = temp[0];
		maxn = max(maxn, dp[0]);
		for (k = 1; k < n; k++)
		{
			dp[k] = max(dp[k - 1] + temp[k], temp[k]);
			//printf("dp %d is %d\n", k, dp[k]);
			maxn = max(maxn, dp[k]);
		}
		for (j = i + 1; j < n; j++)
		{
			//printf("line %d to %d \n",i,j);
			for (k = 0; k < n; k++)
			{
				temp[k] = s[k][j] - s[k][i];
				//printf("temp %d is %d\n", k, temp[k]);
			}
			dp[0] = temp[0];
			maxn = max(maxn, dp[0]);
			for (k = 1; k < n; k++)
			{
				dp[k] = max(dp[k - 1] + temp[k], temp[k]);
				//printf("dp %d is %d\n", k, dp[k]);
				maxn = max(maxn, dp[k]);
			}
		}
	}
	cout << maxn << endl;
}