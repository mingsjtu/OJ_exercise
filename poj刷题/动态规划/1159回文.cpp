#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
string s1, s2;
int dp[5005][5002];
int n;
int main()
{
	cin >> n;
	cin >> s1;
	s2 = s1;
	reverse(s1.begin(), s1.end());
	int i, j, k;
	cout << s1 << endl;
	cout << s2 << endl;
	memset(dp, 0, sizeof(dp));
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <=n; j++)
		{
			
			dp[i][j ] = max(dp[i - 1][j], dp[i][(j - 1)]);
			//dp[i][j%2] = max(dp[i - 1][j%2], dp[i][(j - 1)%2]);
			if (s1[i-1] == s2[j-1])
			{
				printf("i %d j%d s1[i]%c s2[j] %c\n", i, j, s1[i-1], s2[j-1]);
				//dp[i][j%2] = max(dp[i][j%2], dp[i - 1][(j - 1)%2]+1);
				dp[i][j] = max(dp[i][j], dp[i - 1][(j - 1)] + 1);

				printf("i %d j%d dp%d\n", i, j, dp[i][j]);
			}
		}
	}
	//cout << dp[n][n] << endl;
	cout << n - dp[n][n]<<endl;
}