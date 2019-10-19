//http://noi.openjudge.cn/ch0206/1944/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int n;
int dp[30];
int main()
{
	int i, j, k;
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	for (i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n] << endl;
}