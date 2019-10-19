//http://poj.org/problem?id=1006
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool test(int x, int a, int b)
{
	if (x % 23 == a && x % 28 == b)
		return true;
	else
		return false;
}
int main()
{
	int a, b, c, d;
	bool flag = false;
	int t = 1;
	while (cin >> a >> b >> c >> d)
	{
		//printf("test a%d b%d c%d d%d\n", a, b, c, d);
		a %= 23;
		b %= 28;
		c %= 33;
		flag = false;
		if (a == -1 && b == -1 && c == -1 && d == -1)
		{
			break;
		}
		int x = c;
		while (1)
		{
			//printf("x %d\n", x);
			if (x>d&&test(x, a, b))
			{
				flag = true;
				break;
			}
			x += 33;
		}
		printf("Case %d: the next triple peak occurs in %d days.\n", t, x-d);
		t++;
	}
}