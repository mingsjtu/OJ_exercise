//http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1002
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
char map[4][4];
int res = 0,cur=0;
int n;
bool canput(int t)
{
	int x = t / n;
	int y = t % n;
	int i,j, k;
	for (i = x; i >= 0; i--)
	{
		if (map[i][y] == 'X')
			break;
		if (map[i][y] == 'a')
			return false;
	}
	for (i = y; i >= 0; i--)
	{
		if (map[x][i] == 'X')
			break;
		if (map[x][i] == 'a')
			return false;
	}
	return true;
}
void dfs(int sta, int cur)
{

	int i, j, k;
	printf("dfs sta%d ,cur %d\n", sta, cur);
	if (sta == n * n)
	{
		//printf("dfs sta%d ,cur %d\n", sta, cur);
		if (cur > res)
			res = cur;
		return;
	}
	if (map[sta / 4][sta % 4] == '.'&&canput(sta))
	{
		printf("put x%d\n", sta);
		map[sta / 4][sta % 4] = 'a';
		//cur++;
		dfs(sta + 1, cur + 1);
		map[sta / 4][sta % 4] = '.';
	}
	dfs(sta + 1, cur);
}

int main()
{
	int i, j, k;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		res = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
			//getchar();
		}
		
		dfs(0, 0);
		cout << res << endl;
	}

}