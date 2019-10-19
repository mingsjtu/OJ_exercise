//http://bailian.openjudge.cn/xly2019/B/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
const int m[12] = { 31,28,31,30,31,30,31,31,30,31,31 };
const int m1[12] = { 31,29,31,30,31,30,31,31,30,31,31 };
bool isr(int x)
{
	if (x % 400 == 0)
		return true;
	if (x % 4 == 0 && x % 100 != 0)
		return true;
	return false;
}
int main()
{
	int i, j, k;
	int res = 0;
	//1900 1yue 1ri zhou1
	int res1 = 1;
	int year, mon;
	cin >> year >> mon;
	for (i = 1990; i < year; i++)
	{
		if (isr(i))
		{
			res1 += 366;
		}
		else
			res1 += 365;
	}
	if (isr(year))
	{
		printf("res1 %d\n", res1);
		for (i = 0; i < mon-1; i++)
		{
			res1 += m1[i];
		}
		res1 = res1 % 7;
		printf("res1 %d\n", res1);
		printf("Sun Mon Tue Wed Thu Fri Sat\n");
		j = 1;
		k = res1;
		while(k--)
			printf("    ");
		k = res1;
		while (j <= m1[i])
		{
			printf("%3d ", j++);
			k++;
			if (k == 7)
			{
				k = 0;
				printf("\n");
			}
		}
	}
	else
	{
		printf("res1 %d\n", res1);

		for (i = 0; i < mon-1; i++)
		{
			res1 += m[i];
		}
		printf("res1 %d\n", res1);
		res1 = res1 % 7;
		printf("Sun Mon Tue Wed Thu Fri Sat\n");
		j = 1;
		k = res1;
		while (k--)
			printf("    ");
		k = res1;
		while (j <= m[i])
		{
			printf("%3d ", j++);
			k++;
			if (k == 7)
			{
				k = 0;
				printf("\n");
			}
		}
	}
	
}