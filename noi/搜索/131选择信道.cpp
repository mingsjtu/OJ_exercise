//http://noi.openjudge.cn/ch0205/131/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
bool map[30][30];
int fa[30];
bool vis[30];
int findfa(int x)
{
	if (fa[x] != x)
	{
		fa[x] = findfa(fa[x]);
	}
	return fa[x];
}
void join(int a, int b)
{
	int f_a = findfa(a);
	int f_b = findfa(b);
	if (f_a != f_b)
	{
		fa[a] = f_b;
	}
}
int main()
{
	int i, j, k;
	int n;
	char a;

	while (cin >> n)
	{
		if (!n)
			break;
		int res = 0;
		memset(vis, 0, sizeof(vis));
		memset(map, 0, sizeof(map));

		char b[30];
		int m;
		for (i = 0; i < n; i++)
		{
			cin >> a;
			map[a-'A'][a-'A'] = 1;
			cin >> b;
			//cout << "string" << b << endl;
			m = strlen(b);
			for (j = 1; j < m; j++)
			{
				map[a - 'A'][b[j] - 'A'] = 1;
				map[b[j] - 'A'][a - 'A'] = 1;
				//printf("%c and %c\n", a, b[j]);
			}
			//cout << endl;
		}
		for (i = 0; i < n; i++)
			fa[i] = i;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				cout << map[i][j];
				if (map[i][j] == 0)
				{
					join(i, j);
				}
			}
			cout << endl;
		}
		for (i = 0; i < n; i++)
		{
			int tmp = findfa(i);
			printf("i%d fa%d\n", i, tmp);
			vis[tmp] = 1;
		}
		for (i = 0; i < n; i++)
		{
			if (vis[i] == 1)
				res++;
		}
		if(res>1)
			printf("%d channels needed.\n", res);
		else
			printf("1 channel needed.\n");

	}

}