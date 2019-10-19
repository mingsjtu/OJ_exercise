//https://www.nowcoder.com/practice/4b733a850c364c32b368555c8c2ec96b?tpId=40&tqId=21341&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;
const double pi = acos(-1);
int main()
{
	double x1, x2, y1,y2,z1,z2;
	while (cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2)
	{
		double r =sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2));
		double v = r * r*r*pi*4/3;
		printf("%.3lf %.3lf\n", r, v);
	}
	
}