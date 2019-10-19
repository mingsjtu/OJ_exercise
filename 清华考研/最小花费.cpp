//https://www.nowcoder.com/practice/e6df3e3005e34e2598b9b565cfe797c9?tpId=40&tqId=21354&tPage=2&rp=2&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int a, b, n, dis[1005];
typedef long long ll;
ll dp[1005];
int l1, l2, l3, c1, c2, c3;
ll min(ll l1, ll l2)
{
	if (l1 > l2)
		return l2;
	else
		return l1;
}
void solve()
{
	int i, j, k;
	dp[a-1] = 0;
	for (i = a; i < b; i++)
	{
		dp[i] = dp[i - 1] + c3;
		for (j = i-1; j>=0; j--)
		{
			if (dis[i] - dis[j] > l3)
				break;
			if (dis[i] - dis[j] <=l1)
			{
				dp[i] = min(dp[j] + c1, dp[i]);
				//printf("1updata dp%d to %d by j%d\n",i, dp[i],j);
			}
			else
			{
				if (dis[i] - dis[j] <= l2)
				{
					//printf("2updata dp%d to %d by j%d\n", i, dp[i], j);
					dp[i] = min(dp[j] + c2, dp[i]);
				}
				else
				{
					//printf("3updata dp%d to %d by j%d\n", i, dp[i], j);
					dp[i] = min(dp[j] + c3, dp[i]);

				}
			}
		}
		//printf("dp %d is %d\n", i, dp[i]);
	}
	cout << dp[b - 1] << endl;
}
int main()
{
	int i, j, k;
	while (cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3)
	{
		memset(dp, 0, sizeof(dp));
		cin >> a >> b >> n;
		dis[0] = 0;
		for (i = 1; i < n; i++)
		{
			scanf("%d", &dis[i]);
			//printf("dis %d is%d\n", i,dis[i]);
		}
		solve();
	}
}