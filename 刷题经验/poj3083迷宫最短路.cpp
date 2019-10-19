//http://poj.org/problem?id=3083
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int n, m;
char map[45][45];
int left1[4][4] = { { 1,0,3,2 },{2,1,0,3},{3,2,1,0},{0,3,2,1} };
int zou[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
int right1[4][4] = { {3,0,1,2},{0,1,2,3},{1,2,3,0},{2,3,0,1} };
int s[2], e[2];
bool vis[45][45];
//int dir[1700];
int zuo()
{
	int i, j, k;
	int x = s[0], y = s[1],xx,yy;
	//printf("x%d ,y%d\n", x, y);
	int cur;
	for (i = 0; i < 4; i++)
	{
		xx = x + zou[i][0];
		yy = y + zou[i][1];
		if (xx >= 0 && xx < m&&yy >= 0 && yy < n&& (map[xx][yy] == '.' || map[xx][yy] == 'E'))
		{
			cur = i;
			break;
		}
	}
	int tmp;
	int t=1;
	x = xx;
	y = yy;
	while (1)
	{
		//printf("cur %d\n", cur);
		t++;
		if (x == e[0] && y == e[1])
		{
			break;
		}
		for(i=0;i<4;i++)
		{
			xx = x + zou[left1[cur][i]][0];
			yy = y + zou[left1[cur][i]][1];
			if (xx >= 0 && xx < m&&yy >= 0 && yy < n&&(map[xx][yy] == '.'||map[xx][yy]=='E'))
			{
				break;
			}
		}
		x = xx;
		y = yy;
		cur = left1[cur][i];
		
	}
	return t;
}
int you()
{
	int i, j, k;
	int x = s[0], y = s[1], xx, yy;
	//printf("x%d ,y%d\n", x, y);
	int cur;
	for (i = 0; i < 4; i++)
	{
		xx = x + zou[i][0];
		yy = y + zou[i][1];
		if (xx >= 0 && xx < m&&yy >= 0 && yy < n && (map[xx][yy] == '.' || map[xx][yy] == 'E'))
		{
			cur = i;
			break;
		}
	}
	int tmp;
	int t = 1;
	x = xx;
	y = yy;
	while (1)
	{
		//printf("cur %d\n", cur);
		t++;
		if (x == e[0] && y == e[1])
		{
			break;
		}
		for (i = 0; i < 4; i++)
		{
			xx = x + zou[right1[cur][i]][0];
			yy = y + zou[right1[cur][i]][1];
			if (xx >= 0 && xx < m&&yy >= 0 && yy < n && (map[xx][yy] == '.' || map[xx][yy] == 'E'))
			{
				break;
			}
		}
		x = xx;
		y = yy;
		cur = right1[cur][i];

	}
	return t;
}
struct h
{
	int x, y, t;
};
int zuiduan()
{
	queue<h> h1;
	memset(vis, 0, sizeof(vis));
	while (!h1.empty())
	{
		h1.pop();
	}
	h tmp,cur;
	tmp.x = s[0];
	tmp.y = s[1];
	tmp.t = 1;
	h1.push(tmp);
	int i, j, k;
	int xx, yy, x, y,t;
	bool flag = false;
	vis[s[0]][s[1]] = 1;

	while (!h1.empty()&&!flag)
	{
		cur=h1.front();
		h1.pop();
		x = cur.x;
		y = cur.y;
		t = cur.t;

		//printf("x%d ,y%d,t%d\n", x, y,cur.t);
		tmp.t = t+1;
		for (i = 0; i < 4; i++)
		{
			xx = x + zou[i][0];
			yy = y + zou[i][1];
			if (xx >= 0 && xx < m&&yy >= 0 && yy < n &&vis[xx][yy]==0&& (map[xx][yy] == '.' || map[xx][yy] == 'E'))
			{
				if (xx == e[0] && yy == e[1])
				{
					flag = true;
					break;
				}
				tmp.x = xx;
				tmp.y = yy;
				vis[xx][yy] = 1;
				h1.push(tmp);
			}
		}
	}
	return tmp.t;
}
int main()
{
	int t;
	cin >> t;
	int i, j, k;
	while (t--)
	{
		cin >> n >> m;
		for (i = 0; i < m; i++)
		{
			scanf("%s[^\n]", map[i]);
		}
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (map[i][j] == 'S')
				{
					s[0] =i;
					s[1] = j;
				}
				if (map[i][j] == 'E')
				{
					e[0] = i;
					e[1] = j;
				}
			}
		}
		cout << zuo() << ' '<<you()<<' '<<zuiduan()<<endl;
	}
}