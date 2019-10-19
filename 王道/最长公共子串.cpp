#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 102;
int dp[maxn][maxn];
char s1[maxn];
char s2[maxn];
int max(int n1, int n2)
{
	int tmp;
	tmp = (n1 > n2) ? n1 : n2;
	return tmp;
}
int main()
{
	while (cin.getline(s1, maxn, '\n'))
	{
		cin.getline(s2, maxn, '\n');
		int l1 = strlen(s1), l2 = strlen(s2);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i < l1; i++)
		{
			for (int j = 1; j < l2; j++)
			{
				if (s1[i] == s2[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}

			}
		}
		cout << dp[l1 - 1][l2 - 1] << endl;
	}
}