//http://poj.org/problem?id=3393
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int md[13] = { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int md2[13] ={31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool p(int x)
{
	if (x == 1700)
		return true;
	if (x >= 1528)
	{
		if (x % 4 == 0 && x % 100 != 0)
			return true;
		if (x % 400 == 0)
			return true;
	}
	if (x < 1528)
		if (x % 4 == 0)
			return true;
	return false;
}
bool a1[120005];
bool a2[120005];
bool pp[10005];

void init()
{
	int x;
	for (x = 1; x <= 10000; x++)
	{
		if (p(x))
			pp[x] = 1;
		else
			pp[x] = 0;
	}
}
int main()
{
	int n, y1, y2, m1, m2;
	int id1, id2;
	int d1, d2;
	int i, j, k;
	int y,m;
	init();
	y = 1; m = 1; d1 = 5; d2 = 0;
	for (y = 1; y < 10;)
	{
		m++;
		if (m == 13)
		{
			m = 1;
			y++;
		}
		if (!pp[y])
		{
			d1 += md[m - 1];
			d1%= 7;
			d2 += md[m];
			d2%= 7;
		}
		else
		{
			d1 += md2[m - 1] % 7;
			d2 += md2[m];
			if (y == 1752 && m == 9)
				d2 -=11;
			if (y == 1752 && m == 10)
				d1 -= 11;
			d1 %= 7;
			d2 %= 7;
		}
		printf("year%d mon%d kai%d bi%d\n", y, m, d1, d2);
		int id = y * 12 + m;
		if (d1 == 0 || d1 >= 5)
			a1[id] = 1;
		if (d2 >= 4)
			a2[id] = 1;

	}
	cin >> n;
	while (n--)
	{
		cin >> y1 >> m1 >> y2 >> m2;
		id1 = y1 * 12 + m1 - 9;
		id2 = y2* 12 + m2 - 9;
		int g1=0, g2=0;
		for (i = y1; i <= y2; i++)
		{
			if (a1[i])
				g2++;
			if (a2[i])
				g1++;
		}
		printf("%d %d\n", g2, g1);
	}
}