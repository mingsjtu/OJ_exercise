//http://poj.org/problem?id=3020
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int used[405];
int girl[405];
int link[405][405];
char map[45][15];
int index[45][15];
int h, w;
int t;
int all = 0;
bool dfs(int x)
{
	int i, j, k;
	for (i = 0; i <=all; i++)
	{
		if (link[x][i] == true && used[i] == false)
		{
			used[i] = true;
			//used[x] = true;
				if (girl[i] == 0 || dfs(girl[i]))
				{
					girl[i] = x;
					//girl[x] = i;
					//printf("chenggong %d and %d\n", i, x);
					return true;
				}
		}

	}
	return false;
}
int main()
{
	int i, j, k;
	cin >> t;
	while (t--)
	{
		all = 1;
		scanf("%d %d", &h, &w);
		memset(link, 0, sizeof(link));
		memset(girl, 0, sizeof(girl));
		memset(used, 0, sizeof(used));
		memset(index, 0, sizeof(index));
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == '*')
				{
					index[i][j] = all++;
					if (i - 1 >= 0)
					{
						if (index[i - 1][j] != 0)
						{
							link[index[i - 1][j]][index[i][j]] = 1;
							link[index[i][j]][index[i - 1][j]] = 1;

						}
					}
					if (j - 1 >= 0)
					{
						if (index[i][j - 1] != 0)
						{
							link[index[i][j - 1]][index[i][j]] = 1;
							link[index[i][j]][index[i][j - 1]] = 1;

						}
					}
				}
			}
		}

				

		int sum = 0;
		for (i = 1; i <=all; i++)
		{
			memset(used, 0, sizeof(used));
			if (dfs(i))
				sum++;
		}
		//cout << all-1 << sum << endl;
		cout << all-1 - sum/2 << endl;
	}

}