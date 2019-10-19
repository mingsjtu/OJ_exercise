//http://poj.org/problem?id=2031
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
double x[105], y[105], z[105],r[105];
int n;
double map[105][105];
bool in[105];
double d[105];
void init()
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <=i; j++)
		{
			map[i][j] = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) + (z[i] - z[j])*(z[i] - z[j])) - (r[i] + r[j]);
			map[j][i] = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) + (z[i] - z[j])*(z[i] - z[j])) - (r[i]+r[j]);
			if (map[i][j] < 0)
			{
				map[i][j] = 0;
				map[j][i] = 0;
			}
			cout << map[i][j]<<' ';
		}
		cout << endl;
	}
}
void dig()
{
	int i, j, k;
	memset(in, 0, sizeof(0));
	in[0] = true;
	int ok = 1;
	int newp = 0;
	for (i = 0; i < n; i++)
		d[i] = map[0][i];
	d[0] = 0;
	double newd = 100000000;
	double sum = 0.0;
	while (ok < n)
	{
		newd = 100000000;
		for (i = 0; i < n; i++)
		{
			if (in[i])
				continue;
			printf("d[4] %lf, map[newp][4] %lf\n", d[4], map[newp][4]);
			if (d[i] > map[newp][i])
			{
				d[i] = map[newp][i];
				printf("update %d\n", i);
			}
		}
		printf("d[4] %lf\n", d[4]);
		for (i = 0; i < n; i++)
		{
			//printf("d[i] %lf\n", d[i]);
			if (in[i])
				continue;
			if (d[i] < newd)
			{
				newd = d[i];
				newp = i;
			}
		}
		cout << "newp" << newp << endl;
		sum += newd;
		in[newp] = true;
		d[newp] = 0;
		ok++;
	}
	//cout << sum << endl;
	printf("%.3lf\n", sum);
}
int main()
{
	int i, j, k;
	while (cin >> n)
	{
		memset(map, 0, sizeof(map));
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(z, 0, sizeof(z));
		if (!n)
			break;
		for (i = 0; i < n; i++)
		{
			cin >> x[i] >> y[i] >> z[i] >> r[i];
		}
		init();
		dig();
	}
}