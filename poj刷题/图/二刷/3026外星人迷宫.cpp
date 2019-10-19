//http://poj.org/problem?id=3026
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
char map[55][55];
int dis[105][105]; 
int n;
int h, w;
int num;//µãÊý
int dian[105][2];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


void bfs(int x, int y,int hao)
{
	int tmp[55][55];
	bool vis[55][55];
	memset(vis, 0, sizeof(vis));
	memset(tmp, 0, sizeof(tmp));

	int nx, ny, i, j, k;
	queue<int> qx, qy;
	while (!qx.empty())
	{
		qx.pop();
	}
	while (!qy.empty())
	{
		qy.pop();
	}
	tmp[x][y] = 0;
	vis[x][y] = 1;
	qx.push(x);
	qy.push(y);
	int bu = 0;
	while (!qx.empty())
	{
		bu++;
		x = qx.front();
		y = qy.front();
		//printf("current x%d y%d\n", x, y);
		qx.pop();
		qy.pop();
		for (i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= w || ny >= h || nx < 0 || ny < 0)
				continue;
			if (vis[nx][ny])
				continue;
			if (map[nx][ny] == ' ' || map[nx][ny] == 'A' || map[nx][ny] == 'S')
			{
				vis[nx][ny] = 1;
				tmp[nx][ny] = tmp[x][y]+1;
				//printf("tmp nx%d ny%d is %d\n", nx, ny, tmp[nx][ny]);
				qx.push(nx);
				qy.push(ny);
			}
		}
	}
	for (i = 0; i < num; i++)
	{
		dis[hao][i] = tmp[dian[i][0]][dian[i][1]];
		dis[i][hao] = tmp[dian[i][0]][dian[i][1]];
	}
}
void prim()
{
	int newp = 0;
	int ok = 1;
	int i, j, k;
	int dp[105];
	bool fin[105];
	memset(fin, 0, sizeof(fin));
	memset(dp,-1, sizeof(dp));
	int minv = 100000;
	int all = 0;
	fin[0] = 1;
	dp[0] = 0;
	while (ok++ <=num)
	{
		for (i = 0; i <= num; i++)
		{
			if (fin[i])
				continue;
			if (dp[i] == -1 || dp[i] >dis[newp][i])
			{
				dp[i] =dis[newp][i];
				//printf("updata newp%d to i%d dis%d\n", newp, i, dp[i]);
			}
		}
		minv = 100000;
		for (i = 0; i <= num; i++)
		{
			if (fin[i])
				continue;
			if (minv > dp[i])
			{
				minv = dp[i];
				newp = i;
			}
		}
		fin[newp] = 1;
		all += minv;
		//printf("newp%d ,minv %d\n", newp, minv);
	}
	printf("%d\n", all);
}
int main()
{
	//memset(dis, 0, sizeof(dis));
	//memset(map, 0, sizeof(map));
	scanf("%d", &n);
	while (n-- > 0)
	{
		scanf("%d %d", &h, &w);
		memset(dis, 0, sizeof(dis));
		memset(map, 0, sizeof(map));
		num = 0;
		memset(dian, 0, sizeof(dian));
		int i, j, k;
		getchar();
		for (i = 0; i < w; i++)
		{
			for (j = 0; j < h; j++)
			{
				//cin>>map[i][j];
				map[i][j] = getchar();
				//printf("i %d , j %d\n", i, j);
				if (map[i][j] == 'S')
				{
					dian[0][0] = i;
					dian[0][1] = j;
				}
				if (map[i][j] == 'A')
				{
					dian[num + 1][0] = i;
					dian[num + 1][1] = j;
					num++;
				}
			}
			getchar();
		}
		//printf("num %d\n", num);

		for (i = 0; i <= num; i++)
		{
			//printf("bfs %d,%d\n", dian[i][0], dian[i][1]);
			bfs(dian[i][0], dian[i][1], i);
		}
		/*for (i = 0; i <= num; i++)
		{
			for (j = 0; j <= num; j++)
			{
				cout << dis[i][j] << ' ';
			}
			cout << endl;
		}*/
		prim();
	}
}