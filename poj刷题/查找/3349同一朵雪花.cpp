//http://poj.org/problem?id=3349
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
const int bigp = 999983;
int n;
int a[100005][6];
vector<int> hsh[bigp];
bool same(int x, int y)
{
	for (int i = 0; i < 6; i++)
	{
		if (a[x][0] == a[y][i] && a[x][1] == a[y][(i - 1+6) % 6] && a[x][2] == a[y][(i - 2+6) % 6] && a[x][3] == a[y][(i - 3+6) % 6] && a[x][4] == a[y][(i - 4+6) % 6] && a[x][5] == a[y][(i - 5+6) % 6])
			return true;
		if (a[x][0] == a[y][i] && a[x][1] == a[y][(i + 1) % 6] && a[x][2] == a[y][(i + 2) % 6] && a[x][3] == a[y][(i + 3) % 6] && a[x][4] == a[y][(i + 4) % 6] && a[x][5] == a[y][(i + 5) % 6])
			return true;
	}
	return false;
}
int main()
{
	int i, j, k;
	cin >> n;
	int sum;
	for(i=0;i<n;i++)
	{
		sum = 0;
		for (j = 0; j < 6; j++)
		{
			scanf("%d", &a[i][j]);
			sum += a[i][j];
		}
		sum %= bigp;
		for (j = 0; j < hsh[sum].size(); j++)
		{
			if (same(i, hsh[sum][j]))
			{
				printf("Twin snowflakes found.\n");
				return 0;
			}
		}
		hsh[sum].push_back(i);
	}
	printf("No two snowflakes are alike.\n");
}