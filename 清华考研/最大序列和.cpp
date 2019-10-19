//https://www.nowcoder.com/practice/df219d60a7af4171a981ef56bd597f7b?tpId=40&tqId=21353&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<math.h>
using namespace std;
typedef long long ll;
ll dp[1000005];
int n;
ll a[1000005];
ll max(ll x, ll y)
{
	if (x > y)
		return x;
	else
		return y;
}
int main()
{
	int i, j, k;
	while (cin >> n)
	{
		scanf("%ld",&a[0]);
		dp[0] = a[0];
		for (i = 1; i < n; i++)
		{
			scanf("%ld", &a[i]);
			printf("%ld ", a[i]);
			printf("%ld and %ld\n",dp[i-1]+a[i],a[i]);
			
			dp[i] = max(dp[i - 1] + a[i], a[i]);
			printf("xuan %ld\n", dp[i]);
		}
		ll res = 0;
		printf("res %ld\n", res);
		for (i = 0; i < n; i++)
		{

			if (res < dp[i])
			{
				printf("bian %ld and %ld\n", res, dp[i]);

				res = max(res,dp[i]);

			}
		}
		printf("%d\n", res);
		getchar();
	}
}