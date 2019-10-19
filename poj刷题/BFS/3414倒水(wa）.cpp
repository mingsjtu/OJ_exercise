//http://poj.org/problem?id=3414
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
/*
FILL(2)
POUR(2,1)
DROP(1)
fill 1==1;
fill 2==2;
drop 1==3;
drop 2==4
pour 1 2=5
pour 2 1=6
*/
using namespace std;
int a, b, c;
int res = 100005;
int vis[105][105];
int lastx,lasty;
struct sta
{
	int x, y, s;
};
int x1[105][105];
int y2[105][105];
int cnt = 0;
void bfs()
{
	queue<sta> q1;
	if (!q1.empty())
	{
		q1.pop();
	}
	sta s1;
	s1.x = 0; s1.y = 0; s1.s = 0;
	q1.push(s1);
	x1[0][0] = -1;
	y2[0][0] = -1;
	vis[0][0] = -1;
	//dong[0] = s1;
	sta s2, s3;
	while (!q1.empty())
	{
		s1 = q1.front();
		//printf("pop x%d ,y %d ,s %d \n", s1.x, s1.y, s1.s);
		q1.pop();
		//fill 1
		s2.x = a;
		s2.y = s1.y;
		s2.s = s1.s + 1;

		if (vis[s2.x][s2.y] == 0)
		{
			x1[s2.x][s2.y] = s1.x;
			y2[s2.x][s2.y] = s1.y;
			vis[s2.x][s2.y] = 1;
			if (s2.x == c|| s2.y == c)
			{
				lastx = s2.x;
				lasty = s2.y;
				res = min(res, s2.s);
				//printf("find %d\n", s2.s);
				return;
			}
			q1.push(s2);
			
		}

		//fill 2
		s2.x = s1.x;
		s2.y = b;
		if (vis[s2.x][s2.y] == 0)
		{
			x1[s2.x][s2.y] = s1.x;
			y2[s2.x][s2.y] = s1.y;
			vis[s2.x][s2.y] = 2;
			if (s2.x == c || s2.y == c)
			{
				lastx = s2.x;
				lasty = s2.y;
				res = min(res, s2.s);
				//printf("find %d\n", s2.s);

				return;
			}

			q1.push(s2);
		}
		//drop 1
		s2.x = 0;
		s2.y = s1.y;
		s2.s = s1.s + 1;
		if (vis[s2.x][s2.y] == 0)
		{
			x1[s2.x][s2.y] = s1.x;
			y2[s2.x][s2.y] = s1.y; 
			vis[s2.x][s2.y] = 3;
			if (s2.x == c || s2.y == c)
			{
				lastx = s2.x;
				lasty = s2.y;
				//printf("find %d\n", s2.s);
				res = min(res, s2.s);
				return;
			}
			q1.push(s2);
		}
		//drop 2
		s2.x = s1.x;
		s2.y = 0;
		s2.s = s1.s + 1;
		if (vis[s2.x][s2.y] == 0)
		{
			x1[s2.x][s2.y] = s1.x;
			y2[s2.x][s2.y] = s1.y;
			vis[s2.x][s2.y] = 4;
			if (s2.x == c || s2.y == c)
			{
				lastx = s2.x;
				lasty = s2.y;
				res = min(res, s2.s);
				//printf("find %d\n", s2.s);
				return;
			}
			q1.push(s2);
		}
		//pour 1 to 2
		int tmp = s1.x + s1.y - b;
		if (tmp >= 0)
		{
			s2.x = tmp;
			s2.y = b;
		}
		else
		{
			s2.x = 0;
			s2.y = s1.x + s1.y;
		}
		s2.s = s1.s + 1;
		if (vis[s2.x][s2.y] == 0)
		{
			x1[s2.x][s2.y] = s1.x;
			y2[s2.x][s2.y] = s1.y; 
			vis[s2.x][s2.y] = 5;
			if (s2.x == c || s2.y == c)
			{
				lastx = s2.x;
				lasty = s2.y;
				res = min(res, s2.s);
				//printf("find %d\n", s2.s);

				return;
			}
			q1.push(s2);
		}
		//pour 2 to 1 
		tmp = s1.x + s1.y - a;
		if (tmp >= 0)
		{
			s2.x = a;
			s2.y = tmp;
		}
		else
		{
			s2.x = s1.x + s1.y;
			s2.y = 0;
		}
		s2.s = s1.s + 1;
		if (vis[s2.x][s2.y] == 0)
		{
			x1[s2.x][s2.y] = s1.x;
			y2[s2.x][s2.y] = s1.y; 
			vis[s2.x][s2.y] = 6;
			if (s2.x == c ||s2.y == c)
			{
				lastx = s2.x;
				lasty = s2.y;
				res = min(res, s2.s);
				//printf("find %d\n", s2.s);
				return;
			}
			q1.push(s2);
		}
	}
	return;
}
void dfs()
{
	int tmpx=lastx,tmpy=lasty;
	stack<int> dong;
	int orix, oriy;
	//dong.push(vis[lastx][lasty]);
	while (!(tmpx == 0 && tmpy == 0))
	{
		dong.push(vis[tmpx][tmpy]);
		orix = x1[tmpx][tmpy];
		oriy = y2[tmpx][tmpy];
		tmpx = orix;
		tmpy = oriy;
	}
	int tmpd;
	while (!dong.empty())
	{
		tmpd = dong.top();
		dong.pop();
		switch (tmpd)
		{
		case 1:
			printf("FILL(1)\n");
			break;
		case 2:
			printf("FILL(2)\n");
			break;
		case 3:
			printf("DROP(1)\n");
			break;
		case 4:
			printf("DROP(2)\n");
			break;
		
		case 5:
			printf("POUR(1, 2)\n");
			break;
		case 6:
			printf("POUR(2, 1)\n");
		}

	}

}
int main()
{
	scanf("%d %d %d", &a, &b, &c);
	//printf("a %d,b %d,c %d\n", a, b, c);
	bfs();
	if (res != 100005)
	{
		printf("%d\n", res);
		dfs();
	}
	else
	{
		printf("impossible\n");
	}
	
}