#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int x, y, h, w;
	int xx, yy;
	while (cin >> x >> y >> h >> w)
	{
		cin >> xx >> yy;
		if (xx > x&&xx<x + w && yy>y + h && yy < y)
		{
			printf("in \n");
		}
		else
		{
			if ((xx == x && (yy >= y + h && yy <= y)) || (xx == x + w && (yy >= y + h && yy <= y)) || (yy == y + h && (xx <= x + w && xx >= x)) || (yy == y && (xx <= x + w && xx >= x)))
				printf("on \n");
			else
				printf("out \n");
		}
	}
}