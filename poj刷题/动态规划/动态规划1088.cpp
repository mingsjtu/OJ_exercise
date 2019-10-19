//http://poj.org/problem?id=1088
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int r, c;
int map[102][102];
int dp[102][102] = { 0 };
int ans = 1;
int max(int a, int b)
{
	return a > b ? a : b;
}
int f(int x, int y)
{
	if (dp[x][y] > 0)
		return dp[x][y];
	int zeng = 1;
	if (x + 1 <= r)
	{
		if (map[x][y] > map[x + 1][y])
			zeng = max(zeng,f(x + 1, y) + 1);
	}
	if (x - 1 >0)
	{
		if (map[x][y] > map[x - 1][y])
			zeng = max(zeng, f(x - 1, y) + 1);
	}
	if (y + 1 <= c)
	{
		if (map[x][y] > map[x][y+1])
			zeng = max(zeng, f(x, y+1) + 1);
	}
	if (y - 1 > 0)
	{
		if (map[x][y] > map[x][y-1])
			zeng = max(zeng, f(x, y-1) + 1);
	}
	//cout << "zeng" << zeng << endl;
	return zeng;
}
int main()
{
	cin >> r >> c;
	int i, j, k;
	for (i = 1; i <=r; i++)
	{
		for (j = 1; j <=c; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			dp[i][j]=f(i,j);c
			ans=ans>dp[i][j]?ans:dp[i][j];
		}
	}
	cout << ans << endl;
}
