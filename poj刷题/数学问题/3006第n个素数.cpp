//http://poj.org/problem?id=3006
#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
bool isp(int x)
{
	int i, j, k;
	if (x < 2)
		return false;
	for (i = 2; i <= sqrt(x) + 1&&i<x; i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}
int main()
{
	int a, n, d,x,res;
	while (cin >> a >> d >> n)
	{
		if (a == 0 && d == 0 && n == 0)
			break;
		int i = 0;
		x = a;
		while (i < n)
		{
			if (isp(x))
			{
				i++;
			}
			if (i == n)
			{
				res = x;
				break;
			}
			x += d;
		}
		cout << x << endl;
	}

}