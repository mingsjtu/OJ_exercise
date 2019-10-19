//http://poj.org/problem?id=1080
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
map<char, int>m1;
int dp[103][103];
char a[103];
char b[103];
int t, n1,n2;
int inf = 0x7777f;
int score[5][5] = { {5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,-10000} };
int s;
int main()
{
	cin >> t;
	int i, j, k;
	m1['A'] =0;
	m1['C'] = 1;
	m1['G'] = 2;
	m1['T'] = 3;
	while (t-->0)
	{
		scanf("%d %s",&n1, a);
		scanf("%d %s",&n2, b);
		//printf("n1 %d a %s\n", n1, a);
		//printf("n2 %d b %s\n", n2, b);
		//memset(dp, -inf, sizeof(dp));
		dp[0][0] = 0;
		for (i = 1; i < n1; i++)
		{
			dp[i][0] = dp[i - 1][0] + score[m1[a[i - 1]]][4];
			//printf("dp i%d 0 is %d\n", i, dp[i][0]);
		}
		for (i = 1; i < n2; i++)
		{
			dp[0][i] = dp[0][i - 1] + score[m1[b[i - 1]]][4];
			//printf("dp i%d 0 is %d\n", i, dp[0][i]);
		}
		//cout <<"n1 n2"<< n1 << n2<<endl;
		for (i = 1; i <= n1; i++)
		{
			for (j = 1; j <= n2; j++)
			{
				dp[i][j] = max(dp[i - 1][j - 1] + score[m1[a[i - 1]]][m1[b[j - 1]]], dp[i-1][j]+score[m1[a[i - 1]]][4]);
				dp[i][j] = max(dp[i][j], dp[i][j-1] + score[m1[b[j - 1]]][4]);
			}
		}
		cout << dp[n1][n2] << endl;
	}
}