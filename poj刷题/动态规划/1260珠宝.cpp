//http://poj.org/problem?id=1260
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
int t, n;
ll dp[105];
ll a[105];
ll b[105];
ll qian[105];
int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	cin >> t;
	int i, j, k;
	while (t-- > 0)
	{
		cin >> n;
		memset(qian, 0, sizeof(qian));
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &a[i], &b[i]);
			//if (i > 0)
				qian[i+1] = qian[i] + a[i];
			//else
				//qian[0] = a[i];
		}
		dp[0] = 0;
		//dp[1] = (a[0] + 10) * b[0];

		for (i = 1; i <= n; i++)
		{
			dp[i] = 100000005;
			for (k = 0; k <i; k++)
			{
				dp[i] = min(dp[i],dp[k] + (qian[i] - qian[k] + 10)*b[i-1]);
			}
		}
		cout << dp[n] << endl;
	}
}