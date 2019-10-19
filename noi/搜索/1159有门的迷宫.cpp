//http://noi.openjudge.cn/ch0205/1159/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
char map[22][22];
int n, m;
int key[5];
int tar[5];
int qidian[2];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool flag = false;
bool have[5];
int door[5][2];
bool keda[5];
bool vis[22][22];
bool find1;
void dfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] == 1)
		return;
	vis[x][y] = 1;
	if (flag)
		return;
	int i, j, k;
	int nx, ny;
	for (i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		//if (map[nx][ny] >= 'A'&&map[nx][ny] <= 'E')
		//{
		//	keda[map[nx][ny] - 'A'] = 1;
		//	if (key[map[nx][ny] - 'A'] == tar[map[nx][ny] - 'A'])
		//	{
		//		map[nx][ny] = 'o';
		//		//cout << "ok\n";
		//		dfs(nx, ny);
		//	}
		//}
		if (map[nx][ny] == 'G')
		{
			flag = true;
			return;
		}
		if (map[nx][ny] == '.')
		{
			//map[nx][ny] = 'o';
			dfs(nx, ny);
		}
		if (map[nx][ny] >= 'a'&&map[nx][ny] <= 'e')
		{
			key[map[nx][ny] - 'a']++;
			char tmp = map[nx][ny];
			//map[nx][ny] = 'o';
			dfs(nx, ny);
			//printf("cur %d,tar%d\n", key[tmp - 'a'], tar[tmp - 'a']);

		}
	}
}
int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
			break;
		memset(have, 0, sizeof(have));
		memset(keda, 0, sizeof(keda));
		memset(map, 0, sizeof(map));
		memset(key, 0, sizeof(key));
		memset(tar, 0, sizeof(tar));
		memset(vis, 0, sizeof(vis));

		int i, j, k;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'S')
				{
					qidian[0] = i;
					qidian[1] = j;
				}
				if (map[i][j] >= 'a'&&map[i][j] <= 'e')
				{
					tar[map[i][j] - 'a']++;
				}
				if (map[i][j] >= 'A'&&map[i][j] <= 'E')
				{
					door[map[i][j] - 'A'][0] = i;
					door[map[i][j] - 'A'][1] = j;

					have[map[i][j] - 'A'] = 1;
				}
			}
		}
		flag = false;
		//for (i = 0; i < n; i++)
		//{
		//	for (j = 0; j < m; j++)
		//	{
		//		cout << map[i][j];
		//	}
		//	cout << endl;
		//}
		dfs(qidian[0], qidian[1]);
		while (find1)
		{
			find1 = false;

for (i = 0; i < 5; i++)
		{
			if (have[i] && key[i] == tar[i] && keda[i])
			{
				find1 = true;
				//cout << "ok\n";
				map[door[i][0]][door[i][1]] = '.';
				memset(vis, 0, sizeof(vis));
				memset(key, 0, sizeof(key));
				dfs(qidian[0], qidian[1]);
				//dfs(door[tmp - 'a'][0], door[tmp - 'a'][1]);
			}
		}
		}
		

		if (flag)
			cout << "Yes\n";
		else
		{
			cout << "No\n";
		}
		//for (i = 0; i < n; i++)
		//{
		//	for (j = 0; j < m; j++)
		//	{
		//		cout << map[i][j];
		//	}
		//	cout << endl;
		//}
		/*for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (map[i][j] == '.')
				{
					dfs(i, j);
				}
				if (map[i][j] >= 'a'&&map[i][j] <= 'e')
				{
					key[map[i][j] - 'a']++;
				}
			}
		}
	*/
	}

}