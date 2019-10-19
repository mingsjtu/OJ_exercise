//http://poj.org/problem?id=3041
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int n, m;
int x, y;
bool marked[505][505];
int x1[10005];
int y2[10005];
int sum = 0;
bool boy[505];
int girl[505];
bool used[505];
bool dfs(int cur)
{
	int i, j, k;
	for (i = 1; i <=n; i++)
	{
		if (marked[cur][i] == true&&used[i]==false)
		{
			used[i] = true;
			if (girl[i] == 0 ||dfs(girl[i]))
			{
			girl[i] = cur;
			boy[cur] = false;
			return true;
			}
		}
	}
	return false;
}
int main()
{
	cin >> n >> m;
	int i, j, k;
	memset(marked, 0, sizeof(marked));
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		marked[x][y] = 1;
		boy[x] = true;
		x1[i] = x;
		y2[i] = y;
	}
	int res=0;
	bool flag;
	memset(girl, 0, sizeof(girl));
	for (i = 1; i <= n; i++)
	{
		flag = false;
		memset(used, 0, sizeof(used));
		//if (boy[i] == true)
		//	flag = dfs(i);
		if (dfs(i))
			res++;
	}

	cout << res << endl;
}
