#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
bool p[10005];
void init()
{
	int i, j, k, x,y;
	for (x = 2; x < 10005; x++)
	{
		if (p[x])
			continue;
		for (y = x + x; y < 10005; y += x)
		{
			p[y] = 1;
		}
	}
}
int deal(int x)
{
	if (p[x] == 0)
		return 1;
	int i, j, k;
	int res = 0;
	for (i = 2; i <=x; i++)
	{
		if (p[i] == 0)
		{
			while (x%i == 0)
			{
				res++;
				x /= i;
			}
		}
	}
	return res;
}
int main()
{
	int x, y, i, j, k;
	init();
	while (cin >> x)
	{
		cout << deal(x) << endl;
	}
}