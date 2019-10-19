//http://poj.org/problem?id=1050
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int juzhen[105][105];
int sum=-2000000;
int n;
int qian[105][105];
int dp[105];

int main()
{
	cin >> n;
	int i,j,k;
	memset(qian, 0, sizeof(qian));
	memset(dp,0,sizeof(dp));
	for (i = 1; i <=n; i++)
	{
		for (j = 1; j <=n; j++)
		{
			scanf("%d", &juzhen[i][j]);
			qian[i][j] = qian[i-1][j]+juzhen[i][j];
		}
	}
	dp[0]=0;
	for (i = 1; i <n; i++)
	{
		for (j = i + 1; j <=n; j++)
		{
			for (k = 1; k <= n; k++)
			{
				dp[k] = dp[k - 1] + qian[j][k] - qian[i][k];
				sum = sum > dp[k] ? sum : dp[k];
			}
		}
	}
	sum=sum>0?sum:0;
	cout << sum << endl;
}
