//http://poj.org/problem?id=2586
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int s, d;
int main()
{
	double is;
	int sum = 0;
	while (cin >> s >> d)
	{
		is = double(d) / double(s);
		if (is > 4)
		{
			sum = 10 * s - 2 * d;
		}
		else
		{
			if (is > 1.5)
			{
				sum = 8 * s - 4 * d;
			}
			else
			{
				if (3*d>2*s)
				{
					sum = 6 * s - 6 * d;
				}
				else
				{
					if (is > 0.25)
					{
						sum = 3 * s - 9 * d;
					}
					else
					{
						sum = -1;
					}
				}
			}
		}
		
		if (sum >= 0)
		{
			printf("%d\n", sum);
		}
		else
		{
			printf("Deficit\n");
	}
}
}