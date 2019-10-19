//http://poj.org/problem?id=3041
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
bool line[505][505];
int a[10005][2];
int girl[505];
bool used[505];
bool myfind(int x)
{
	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		if (line[x][i] == 1 && used[i] == 0)
		{
			used[i] = 1;
			if (girl[i] == 0 || myfind(girl[i]))
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
	memset(line, 0, sizeof(line));
	memset(used, 0, sizeof(used));
	memset(a, 0, sizeof(a));
	memset(girl, 0, sizeof(girl));
	scanf("%d %d", &n,&m);
	int i, j, k;
	for(i=0;i<m;i++)
	{
		scanf("%d %d", &a[i][0], &a[i][1]);
		line[a[i][0]][a[i][1]] = 1;
	}
	int res = 0;
	for (i = 1; i <=n; i++)
	{
		memset(used, 0, sizeof(used));
		if (myfind(i))
			res++;
	}
	/*for (i = 1; i <= n; i++)
	{
		printf("%d", girl[i]);
	}
	cout << endl;*/
	printf("%d\n", res);
	return 0;
}