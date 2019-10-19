//http://bailian.openjudge.cn/xly2019/A/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			return 0;
		if (n < 9)
		{
			cout << n << endl;
			continue;
		}
		if (n >= 9 && n < 99)
		{
			cout << 9 << endl;
			continue;
		}
		if (n >= 99 && n < 999)
		{
			cout << 99 << endl;
			continue;
		}
		if (n >= 999 && n < 9999)
		{
			cout << 999 << endl;
		}
		if (n >= 9999 && n < 99999)
		{
			cout << 9999 << endl;
		}
		if (n >= 99999 && n < 999999)
		{
			cout << 99999 << endl;
		}
	}
}