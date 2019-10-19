//http://poj.org/problem?id=3041
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;
bool used[505];
int girl[505];
int lian[505][505];
int n, m, tmp1, tmp2;

bool find(int x)
{
	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		if (lian[x][i] && used[i] == false)
		{
			used[i] = 1;
			if (girl[i] == 0 || find(girl[i]))
			{
				girl[i] = x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int i, j, k;
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &tmp1, &tmp2);
		lian[tmp1][tmp2] = 1;
	}
	int res = 0;
	for (i = 1; i <=n; i++)
	{
		memset(used, 0, sizeof(used));
		if (find(i)) res++;
	}
	cout << res << endl;
}