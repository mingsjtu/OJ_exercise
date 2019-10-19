#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int map[11][11];//zai di t shike huanbing
int n, m,k;//chang kuan
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


void ganran(int x, int y)
{
	int i, j,nx,ny;
	for (i = 0; i < 4; i++)
	{
		nx = dx[i] + x;
		ny = dy[i] + y;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		if (map[nx][ny] == 0)
			map[nx][ny] = 1;
	}
}
int main()
{
	int x, y;
	cin >> n >> m >> k;
	int i = 0;
	memset(map, 0, sizeof(map));
	for (i = 0; i < k; i++)
	{
		cin >> x >> y;
		map[x-1][y-1] = 1;
	}
	int max = 0,huan=k;
	int t, j;
	for (t = 0; huan>0; t++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
			    if (map[i][j] > 0)
					{
						map[i][j]++;
					}
            }
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
			    if (map[i][j] == 6)
				{
					map[i][j] = -1;//buzai huanbing
				}
				else
				{
					if (map[i][j] == 4)
						ganran(i, j);
				}
            }
		}


		huan = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (map[i][j] > 0)
					huan++;
                //cout<<map[i][j]<<" ";
			}

			//cout<<endl;
		}
		cout << t << "is" << huan << endl;
	}

}
