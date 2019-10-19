#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

struct N
{
	int x, y, z, t;
	void init(int x1,int y1,int z1,int t1)
	{
		x = x1;
		y = y1;
		z = z1;
		t = t1;
	}
	
};
void atob(int &a, int sa, int &b, int sb)
{
	if (sb >= a + b)
	{
		b = a + b;
		a = 0;
	}
	else
	{
		a =a-( sb - b);
		b = sb;
	}
}
queue<N> q;
bool mark[100][100][100];
int time[100][100][100];
int BFS(int s,int n,int m)
{
	N tmp;
	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		N ne;
		atob(tmp.x, s, tmp.y, n);// x to y
		//ne.init(tmp.x +tmp.y, 0, tmp.z, tmp.t);
		if (mark[tmp.x][tmp.y][tmp.z] == 0)
		{
			mark[tmp.x][tmp.y][tmp.z] = 1;
			if (tmp.x == s / 2 || tmp.y == s / 2 || tmp.z == s / 2)
				return (tmp.t + 1);
			
				time[tmp.x][tmp.y][tmp.z] = tmp.t + 1;
				ne.init(tmp.x, tmp.y, tmp.z, tmp.t + 1);
				q.push(ne);
			
		}
		atob(tmp.y, n, tmp.x, s);// y to x,huifu
		atob(tmp.x, s, tmp.z, m);// x to z

			//ne.init(tmp.x +tmp.y, 0, tmp.z, tmp.t);
			if (mark[tmp.x][tmp.y][tmp.z] == 0)
			{
				mark[tmp.x][tmp.y][tmp.z] = 1;
				if (tmp.x == s / 2 || tmp.y == s / 2 || tmp.z == s / 2)
					return (tmp.t + 1);
					time[tmp.x][tmp.y][tmp.z] = tmp.t + 1;
					ne.init(tmp.x, tmp.y, tmp.z, tmp.t + 1);
					q.push(ne);
	
			}
			atob(tmp.z, m, tmp.x, s);// z to x,huifu
			atob(tmp.y, m, tmp.x, s);// y to x

			//ne.init(tmp.x +tmp.y, 0, tmp.z, tmp.t);
			if (mark[tmp.x][tmp.y][tmp.z] == 0)
			{
				mark[tmp.x][tmp.y][tmp.z] == 1;
				if (tmp.x == s / 2 || tmp.y == s / 2 || tmp.z == s / 2)
					return (tmp.t + 1);
					time[tmp.x][tmp.y][tmp.z] = tmp.t + 1;
					ne.init(tmp.x, tmp.y, tmp.z, tmp.t + 1);
					q.push(ne);
			}
			atob(tmp.x, s, tmp.y, n);// x to y,huifu
			atob(tmp.y, n, tmp.z, m);// y to z

			//ne.init(tmp.x +tmp.y, 0, tmp.z, tmp.t);
			if (mark[tmp.x][tmp.y][tmp.z] == 0)
			{
				mark[tmp.x][tmp.y][tmp.z] == 1;
				if (tmp.x == s / 2 || tmp.y == s / 2 || tmp.z == s / 2)
					return (tmp.t + 1);
					time[tmp.x][tmp.y][tmp.z] = tmp.t + 1;
					ne.init(tmp.x, tmp.y, tmp.z, tmp.t + 1);
					q.push(ne);
			}

			atob(tmp.z, m, tmp.y, n);// z to y,huifu
			atob(tmp.z, m, tmp.x, s);// z to x

			//ne.init(tmp.x +tmp.y, 0, tmp.z, tmp.t);
			if (mark[tmp.x][tmp.y][tmp.z] == 0)
			{
				mark[tmp.x][tmp.y][tmp.z] == 1;
				if (tmp.x == s / 2 || tmp.y == s / 2 || tmp.z == s / 2)
					return (tmp.t + 1);
					time[tmp.x][tmp.y][tmp.z] = tmp.t + 1;
					ne.init(tmp.x, tmp.y, tmp.z, tmp.t + 1);
					q.push(ne);

			}
			atob(tmp.x, s, tmp.z, m);// x to z,huifu
			atob(tmp.z, s, tmp.y, m);// z to y
			//ne.init(tmp.x +tmp.y, 0, tmp.z, tmp.t);
			if (mark[tmp.x][tmp.y][tmp.z] == 0)
			{
				mark[tmp.x][tmp.y][tmp.z] = 1;
				if (tmp.x == s / 2 || tmp.y == s / 2 || tmp.z == s / 2)
					return (tmp.t + 1);
					time[tmp.x][tmp.y][tmp.z] = tmp.t + 1;
					ne.init(tmp.x, tmp.y, tmp.z, tmp.t + 1);
					q.push(ne);
			}
		}
		return -1;


}
int main()
{
		int s, n, m;
		while (cin >> s >> n >> m)
		{
			if (!s)
				return 0;
			if (s % 2 == 1)
			{
				cout << "NO" << endl;
				continue;
			}
			while (!q.empty())q.pop();
			N fir;
			fir.init(s, 0, 0, 0);
			q.push(fir);
			int res = BFS(s, n, m);
			cout << res;

		}
	}
