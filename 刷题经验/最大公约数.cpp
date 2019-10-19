//
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
void exgcd(int a, int b, int &x, int &y,int &c)
{
	if (b == 0)
	{
		c = a; x = 1; y = 0;
		return;
	}
	exgcd(b, a%b, y, x,c);
	y -= a / b * x;
}
int main()
{
	int i, j, k;
	int n, m;
	int res, x, y;
	while (cin >> n >> m)
	{
		exgcd(n, m, x, y, res);
		printf("x%d ,y %d, res %d\n", x, y, res);
	}

}