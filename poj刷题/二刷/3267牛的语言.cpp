//http://poj.org/problem?id=3267
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;
int w, l;
char juzi[305];
string s[605];
int dp[305];
int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int i, j, k;
	scanf("%d %d", &w, &l);
	scanf("%s", juzi);
	for (i = 0; i < w; i++)
	{
		cin >> s[i];
	}
	dp[l] = 0;
	for (i = l - 1; i >= 0; i--)
	{
		dp[i] = dp[i + 1] + 1;
		for (j = 0; j < w; j++)
		{
			int len = s[j].length();
			if (juzi[i] == s[j][0] && l - i >= len)
			{
				k = 0;
				int r = i;
				for (r = i; r < l&&k<len; r++)
				{
					if (juzi[r] == s[j][k])
						k++;
				}
				if (k < len)
					continue;
				else
				{
					//cout << s[j];
					//printf("   pipei %d j %d\n", r,i);
					dp[i] = min(dp[i],dp[r] + r - i  - len);
				}
			}
		}
	}
	cout << dp[0] << endl;
}