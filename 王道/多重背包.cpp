//《王道》211页，捐大米，多重背包
#include<iostream>
#include<cstdio>

using namespace std;

int dp[1000];
int w[1000], v[1000];
int p[100], h[100], c[100];
int max(int a1,int a2)
{
	int tmp = (a1 > a2) ? a1 : a2;
	return tmp;
}
int main()
{
	int n, m;
	cin >> n >> m;
	int i, j,k=0;
	for (i = 0; i < m; i++)
	{
		cin >> p[i] >> h[i] >> c[i];
		printf("yuanshi %d  %d  %d\n", p[i], h[i], c[i]);
		for (j = 1; j <=c[i]; j = j * 2)
		{
			w[k] = j * p[i];
			v[k] = j * h[i];
			k++;
		}
		if (c[i] > j)
		{
			w[k] = (c[i] - j)*p[i];
			v[k++] = (c[i] - j)*h[i];
		}
	}
	for (i = 0; i < k; i++)
		printf("dangqian value %d\n", w[i]);
	int newm = k;
	memset(dp, 0, sizeof(dp));
	for (i = 0; i < newm; i++)
	{
		for (j = n; j >= 0; j--)
		{
			if (j >= w[i])
			{
				dp[j] = max(v[i] + dp[j - v[i]], dp[j]);
				printf("renew,dp[%d] wei %d\n", j, dp[j]);
			}
		}
	}
	cout << dp[n] << endl;
	


}