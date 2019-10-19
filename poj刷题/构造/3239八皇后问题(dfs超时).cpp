//http://poj.org/problem?id=3239
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int col[305];
bool ok[305];
int n;
bool flag;
int fix = 400;
bool dj[805];
bool keyi(int x, int y)
{
	if (ok[y])
	{
		return false;
	}
	int i, j, k;
	for (i = 0; i < x; i++)
	{
		if (y - col[i] == x - i || col[i] - y == x - i)
		{
			return false;
		}
	}
	return true;
}
void mput(int x,int y)
{
	col[x] = y;
	ok[y] = true;
	dj[x - y + fix] = true;
}
void xiaochu(int x, int y)
{
	col[x] = -1;
	dj[x - y + fix] = false;
	ok[y] = false;

}
void dfs(int x)
{
	//cout << "dfs" << x << endl;
	if (flag)
		return;
	if (x == n)
	{
		flag = true;
		return;
	}
	int i, j, k;
	for (j = 0; j < n; j++)
	{
		if (ok[j]==false&&dj[x-j+fix]==false)
		{
			mput(x, j);
			dfs(x + 1);
			if (flag)
				return;
			xiaochu(x, j);
		}
	}
}
int main()
{
	int i, j, k;
	while (cin >> n)
	{
		if (n == 0)
			break;
		flag = false;
		memset(ok, 0, sizeof(ok));
		memset(col, -1, sizeof(col));
		dfs(0);
		if (flag)
		{
			for (i = 0; i < n; i++)
			{
				cout << col[i]+1 << ' ';
			}
			cout << endl;
		}
	}
}