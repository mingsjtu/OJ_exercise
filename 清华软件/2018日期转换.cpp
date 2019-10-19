//https://blog.csdn.net/bugaosuni59/article/details/82707451
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int mon1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int mon2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
bool run(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
	{
		return true;
	}
	return false;
}
int main()
{
	int h, m, s, d, mo, y;
	int nh, nm, ns, nd, nmo, ny;
	scanf("%d:%d:%d %d.%d.%d", &h, &m, &s, &d, &mo, &y);
	//cout << h << m << s << d << mo << y << endl;
	int day=0;
	if (run(y))
	{
		for (int i = 0; i < mo - 1; i++)
			day += mon2[i];
	}
	else
	{
		for (int i = 0; i < mo - 1; i++)
			day += mon1[i];
	}
	cout << day << endl;
	int j = 0,k=0;
	for (int i = 2000; i < y; i++)
	{
		//cout << i << endl;
		if (run(i))
		{
			day += 366;
			j++;
			printf("366 %dci\n",j);
		}
		else
		{
			day += 365;
			k++;
			printf("365 %dci\n",k);
		}
	}
	day += d;
	cout << day << endl;
	ny = day / 1000;
	nmo = (day-ny*1000) / 100+1;
	nd = day % 100;
	//////
	int sum=0;
	sum += h * 12500 / 3 + m * 625 / 9 + s * 125 / 36;
	nh = sum / 10000;
	nm = (sum - nh * 10000) / 100;
	ns = sum % 100;
	printf("%d:%d:%d %d.%d.%d\n", nh, nm, ns, nd, nmo, ny);
	
}