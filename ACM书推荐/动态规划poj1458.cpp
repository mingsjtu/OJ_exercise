#define _CRT_SECURE_NO_DEPRECATE
//http://poj.org/problem?id=1458
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str1[1000];
char str2[1000];
int dp[1000][1000];
int l1, l2;
int ans = 0;
int main()
{
	while (cin>>str1>>str2)
	{
		ans = 0;
		dp[0][0] = 0;
		l1 = strlen(str1);
		l2 = strlen(str2);
		int i, j, k;

		for (i = 0; i <= l1; i++)
		{
			dp[i][0] = 0;
		}
		for (i = 0; i <= l2; i++)
		{
			dp[0][i] = 0;
		}
		for (i = 1; i <= l1; i++)
		{
			for (j = 1; j <= l2; j++)
			{

				if (str1[i-1] == str2[j-1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				if (str1[i-1] != str2[j-1])
				{
					dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
				}
				//printf("dp i %d j %d is %d\n", i, j, dp[i][j]);
			}
		}
		cout << dp[l1][l2] << endl;
	}
}