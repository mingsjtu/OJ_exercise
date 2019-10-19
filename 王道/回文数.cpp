#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
bool isok(const int num)
{
	int zifu[20];
	int tmp = num;
	int i = 0;
	while (tmp >= 10)
	{
		zifu[i] = tmp % 10;
		tmp /=10;
		i++;
	}
	zifu[i] = tmp;
	int weishu = i+1;
	for (i = 0; i <weishu / 2; i++)
	{
		if (zifu[i] != zifu[weishu - i - 1])
			return false;
	}
	return true;
}
int main()
{
	int i = 0;
	int m, n;//shangxian xiaxian
	cin >> m >> n;
	for (i = m; i < n; i++)
	{
		if (isok(i))cout << i << endl;
	}
	return 0;
}