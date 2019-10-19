//http://bailian.openjudge.cn/xly2016/A/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double n;
int main()
{
	while (cin >> n) {
		double y = 0;
		if (n < 5)
			y = 2.5 - n;
		else
		{
			if (n < 10)
				y = 2 - 1.5 * (n - 3) * (n - 3);
			else {
				y = n / 2 - 1.5;
			}
		}
		printf("%.3f\n", y);
	}
}