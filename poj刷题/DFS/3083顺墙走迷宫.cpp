//http://poj.org/problem?id=3083
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
using namespace std;
int le[4][4] = { 1,0,2,3,
3,1,0,2,
0,2,3,1,
2,3,1,0 };
int ri[4][4] = {
	2,0,1,3,
	0,1,3,2,
	3,2,0,1,
	1,3,2,0
};
int w, h;
char map[45][45];
int qidian[2],zhongdian[2];
int dy[4] = { 1, 0, 0, -1 };
int dx[4] = { 0,-1,1,0 };
int step;
bool flagl = false;
bool flagr = false;
bool flag = false;
int stepl, stepr;
void dfsl(int x, int y,int d)
{
	if (flagl == true)
		return;
	//printf("fangxiang %d map %c\n", d,map[x][y]);
	if (map[x][y]=='E')
	{
		return;
	}
	int i, j, k,nx,ny;
	for (i = 0; i < 4; i++)
	{
		//printf("test %d\n", le[d][i]);
		nx = x + dx[le[d][i]];
		ny = y + dy[le[d][i]];
		if (nx<0 || nx>h - 1 || ny<0 || ny>w - 1)
			continue;
		if (map[nx][ny] == 'E')
		{
			flagl = true;
			//printf("find!!!!!\n");
			return;
		}
		if (map[nx][ny] != '#'&&map[nx][ny]!='S')
		{
			if(!flagl)
				stepl++;
			dfsl(nx, ny, le[d][i]);
			if (flagl == true)
				return;
		}
	}

}
void dfsr(int x, int y, int d)
{
	if (flagr == true)
		return;
	//printf("fangxiang %d map %c\n", d, map[x][y]);
	if (map[x][y] == 'E')
	{
		return;
	}
	int i, j, k, nx, ny;
	for (i = 0; i < 4; i++)
	{
		//printf("test %d\n", ri[d][i]);
		nx = x + dx[ri[d][i]];
		ny = y + dy[ri[d][i]];
		if (nx<0 || nx>h - 1 || ny<0 || ny>w - 1)
			continue;
		if (map[nx][ny] == 'E')
		{
			flagr = true;
			//printf("find!!!!!\n");
			return;
		}
		if (map[nx][ny] != '#'&&map[nx][ny] != 'S')
		{
			if (!flagr)
				stepr++;
			dfsr(nx, ny, ri[d][i]);
			if (flagr == true)
				return;
		}
	}

}
bool keyong;
/*int dfs(int x, int y, int s)
{
	if (!flag&&s >= step)
		return step;
	//printf("x%d ,y %d, map%c \n", x, y, map[x][y]);
	keyong = false;
	if (map[x][y] == 'E')
	{
		printf("here s%d\n", s);

		flag = true;
		return step>s+1?s+1:step;
	}
		
	//map[x][y] = '#';
	int i, j, k,nx,ny;
	for (i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx<0 || nx>h - 1 || ny<0 || ny>w - 1)
			continue;
		if (map[nx][ny] == 'E')
		{
			//printf("here s%d\n",s);
			step = s + 1<step?s+1:step;
			flag = true;
			return step;
		}
		if (map[nx][ny] == '#')
			continue;
		map[nx][ny] = '#';
		int tmp=dfs(nx, ny, s + 1);
		//printf("tmp %d\n", tmp);
		if(tmp!=-1)
			step = step < tmp ? step : tmp;
		/*if (s != -1 && s + 1 < step)
		{
			keyong = true;
			step = s + 1;
			flag = true;
		}
		map[nx][ny] = '.';
			
	}
	if (flag)
		return step;
	else
		return -1;

}*/
int d[40][40];
int dfs(int x, int y, int s)
{
	d[x][y] = 1;
	queue<int> qx,qy;
	qx.push(x);
	qy.push(y);
	int cx, cy,nx,ny;
	int i, j, k;
	while (!qx.empty())
	{
		cx = qx.front();
		cy = qy.front();
		qx.pop();
		qy.pop();
		for (i = 0; i < 4; i++)
		{
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= 0 && nx < h&&ny >= 0 && ny < w)
			{
				d[nx][ny]=d[cx][cy] + 1;
				if (map[nx][ny] == 'E')
					return d[nx][ny];
				if (map[nx][ny] == '#')
					continue;
				if (map[nx][ny] == '.')
				{
					qx.push(nx);
					qy.push(ny);
					map[nx][ny] = '#';
				}
			}
		}
	}


}
int main()
{
	int t;
	int i, j, k;
	cin >> t;
	while (t-- > 0)
	{
		memset(map, 0, sizeof(map));
		scanf("%d%d", &w, &h);
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				//scanf("%c", &map[i][j]);
				cin >> map[i][j];
				if (map[i][j] == 'S')
				{
					qidian[0] = i;
					qidian[1] = j;
				}
				if (map[i][j] == 'E')
				{
					zhongdian[0] = i;
					zhongdian[1] = j;
				}
			}
		}
		//cout << "get\n";
		stepl = 1;
		flagl=false;
		dfsl(qidian[0], qidian[1],0);
		printf("%d ",stepl+1);
		flagr = false;
		stepr = 1;
		map[qidian[0]][qidian[1]] = '#';
		dfsr(qidian[0], qidian[1], 0);
		printf("%d ", stepr + 1);
		flag = false;
		step = stepl+1<stepr+1?stepl+1:stepr+1;
		step=dfs(qidian[0], qidian[1], 1);
		printf("%d\n", step);
	}
}