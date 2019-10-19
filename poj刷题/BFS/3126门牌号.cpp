//http://poj.org/problem?id=3126
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<queue>
using namespace std;
bool vis[10000];
bool used[10000];
int res[10000];
int t;
int fa[10000];
bool ispri(int x)
{
	int i, j;
	bool flag = true;
	for (i = 2; i <= sqrt(x)+1&&i<x; i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}
int x;

int bfs()
{
	if (x == t)
		return 0;
	queue<int> q1;
	int i, j, k;
	if (!q1.empty())
	{
		q1.pop();
	}
	q1.push(x);
	int tmp;
	res[x] = 0;
	int dig[4];
	used[x] = 1;
	while (!q1.empty())
	{
		tmp = q1.front();
		q1.pop();
		dig[0] = tmp % 10;
		dig[3] = tmp / 1000*1000;
		dig[2] = (tmp - dig[3]) / 100*100;
		dig[1] = (tmp - tmp / 100 * 100) / 10*10;
		int tmp1,tmp2;
		for (i = 0; i < 4; i++)
		{
			tmp1 =tmp-dig[i];
			for (j = 0; j <= 9; j++)
			{
				tmp2 =tmp1+j * pow(10, i);
				if (tmp2>1000&&vis[tmp2] == 1 && used[tmp2] == 0 )
				{
					res[tmp2] = res[tmp] + 1;
					
					//printf("push %d at %4d\n", tmp2, res[tmp2]);
					fa[tmp2] = tmp;
					used[tmp2] = 1;
					if (tmp2 == t)
						return res[tmp2];
					q1.push(tmp2);
				}
			}
		}
	}
	return -1;
}
void dfs()
{
	int tmp;
	tmp = t;
	while (tmp != x)
	{
		tmp = fa[tmp];
		cout << "ori " << tmp << endl;
	}
}
int main()
{
	int i, j, k;
	memset(vis, 0, sizeof(vis));
	cin >> k;
	for (i = 2; i < 10000; i++)
	{
		if (ispri(i))
		{
			vis[i] = 1;
		}
	}
	for (j = 0; j < k; j++)
	{
		memset(used, 0, sizeof(used));
		memset(res, 0, sizeof(res));
		memset(fa, 0, sizeof(fa));

		cin >> x >> t;
		int result = bfs();
		if (result == -1)
			printf("Impossible\n");
		else
			printf("%d\n", result);
		//dfs();

	}
	
}