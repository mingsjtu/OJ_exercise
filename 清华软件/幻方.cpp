//http://bailian.openjudge.cn/jssxlylx2016/D/
#include<iostream>
using namespace std;
int n;
int map[50][50];
int nx, ny;
void insert(int i,int ox,int oy)
{
	map[ox][oy] = i;
	bool flag = false;
	if (ox == 0 && oy == 2 * n - 2)
	{
		nx = ox + 1;
		ny = oy;
		flag = true;
	}
	else {
		if (ox == 0)
		{
			nx = 2 * n - 2;
			ny = oy + 1;
			flag = true;
		}
		if (oy == 2 * n - 2)
		{
			nx = ox - 1;
			ny = 0;
			flag = true;
		}
		if (map[ox - 1][oy + 1] != 0)
		{
			nx = ox + 1;
			ny = oy;
			flag = true;
		}
	}
	if (!flag)
	{
		nx = ox - 1;
		ny = oy + 1;
	}
	//cout << ox << oy<<endl;

}
int main()
{
	int i, j;
	cin >> n;
	memset(map, 0, sizeof(map));
	int jie = (2 * n - 1) * (2 * n - 1);
	nx = 0, ny = n-1;
		for (i = 1; i <= jie; i++)
		{
			insert(i,nx,ny);
			//printf("nx:%d,ny:%d\n", nx, ny);
		}
		for (i = 0; i < 2*n-1; i++)
		{
			for (j = 0; j < 2*n-1; j++)
			{
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}

}