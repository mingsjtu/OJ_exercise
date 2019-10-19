//http://poj.org/problem?id=1905
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
double l, c, n;
const double pi = 3.1415926;
double jie(double y)
{
	//printf("%lf\n", y);
	double low = 0;
	double high = pi;
	double mid = (low + high) / 2;
	//while ((sin(mid / 2)) / mid - y>= 0.000000001|| (sin(mid / 2)) / mid - y <= -0.000000001)
	while(high-low>0.00000002/l)
	{
		//printf("mid %lf y%lf\n", mid, (sin(mid / 2)) / mid - y);
		if ((sin(mid / 2)) / mid >= y)
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
		mid = (low + high) / 2;
	}
	return mid;
}

int main()
{
	double res;
	while (cin >> l >> n >> c)
	{
		if (l == -1 && n == -1 && c == -1)
			break;
		//int l1 = (1 + n * c)*l;
		double tmp = 2 * (1 + n * c);
		res = jie(double(1.0/tmp));
		//cout << double(sin(res / 2) / res - double(500) / double(l1)) << endl;
		double res1;
		res1 = l/2/ tan(pi/2-res / 4);
		printf("%.3f\n", res1);
	}
	
}