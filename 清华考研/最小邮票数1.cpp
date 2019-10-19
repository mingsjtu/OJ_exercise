//https://www.nowcoder.com/practice/83800ae3292b4256b7349ded5f178dd1?tpId=40&tqId=21345&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
int M,N;
int a[25];
int dp[105];
using namespace std;
int main()
{
	int i, j, k;
	//bool ok[105];
	while (cin >> M >> N)
	{
		for (i = 0; i <= M; i++)
			dp[i] = N + 1;
		for (i = 1; i <=N; i++)
		{
			scanf("%d", &a[i]);
		}
		dp[a[1]] = 1;
		dp[0] = 0;
		
		for (i = 2; i <=N; i++)
		{
			//dp[a[i]] = 1;
			for (j = M; j >= a[i]; j--)
			{
				if (dp[j - a[i]] == -1)
					continue;
				if (dp[j]==-1|| (dp[j] > dp[j - a[i]] + 1))
				{
					dp[j] = dp[j - a[i]] + 1;
				}
			}
			//cout << dp[M] << endl;
			
		}
		if (dp[M] == N+1)
			cout << 0 << endl;
		else
			cout << dp[M] << endl;
	}
}