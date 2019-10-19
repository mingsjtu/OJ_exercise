//http://poj.org/problem?id=2531
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int a[25][25];
bool in[25];
int ans = 0;
void dfs(int x,int res)
{
	in[x] = 1;
	int i, j, k;
	int resn = res;
	for (i = 0; i < n; i++)
	{
		if (in[i] == false)
		{
			resn += a[i][x];
		}
		else
		{
			resn -= a[i][x];
		}
	}
	if (resn > ans)
		ans = resn;
	if (resn > res)
	{
		for (i = x + 1; i < n; i++)
		{
			dfs(i, resn);
		}
	}
	in[x] = false;

}
int main()
{
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	memset(in, 0, sizeof(in));
	dfs(0, 0);
	cout << ans << endl;
	
}