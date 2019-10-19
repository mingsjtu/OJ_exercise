//http://poj.org/problem?id=2533
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int dp[1005];
int shu[1005];
int num;
int main()
{
	cin >> num;
	int i, j, k;
	for (i = 0; i < num; i++)
	{
		dp[i] = 1;
		scanf("%d", &shu[i]);
	}
	for (i = 1; i < num; i++)
	{
		for (k = 0; k < i; k++)
		{
			if (shu[k] < shu[i])
				dp[i] = max(dp[i],dp[k] + 1);
		}
		
	}
	int res = 1;
	for (i = 0; i < num; i++)
		res = max(res, dp[i]);
	cout << res << endl;
}