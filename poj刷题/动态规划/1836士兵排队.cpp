//http://poj.org/problem?id=1836
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
int dp1[1005];
int dp2[1005];
float h[1005];
int n;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	scanf("%d", &n);
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		scanf("%f", &h[i]);
	}
	dp1[0] = 1;
	for (i = 1; i < n; i++)
	{
		dp1[i] = 1;
		for (k = i - 1; k >= 0; k--)
		{
			if(h[k]<h[i])
				dp1[i] = max(dp1[i],dp1[k] + 1);
		}
	}
	/*for (i = 0; i < n; i++)
	{
		cout << dp1[i]<<endl;
	}*/
	dp2[n - 1] = 1;
	for (i = n - 2; i >= 0; i--)
	{
		dp2[i] = 1;
		for (k = i + 1; k < n; k++)
		{
			if (h[k] < h[i])
				dp2[i] = max(dp2[i], dp2[k] + 1);
		}
	}
	/*for (i = 0; i < n; i++)
	{
		cout << dp2[i]<<endl;
	}*/
	int res = 2;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n - 1; j++)
		{
			res = max(res, dp1[i] + dp2[j]);
		}
	}
	cout << n-res << endl;
}