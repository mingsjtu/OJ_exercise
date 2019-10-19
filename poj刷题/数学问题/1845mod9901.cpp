//http://poj.org/problem?id=1845
#include<iostream>
#include<cstdio>
#include<math.h>
#include<cstring>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	if (a == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	if (b == 0)
	{
		cout << 1 << endl;
		return 0;
	}
	a = a % 9901;
	//printf("a %d\n", a);
	int res = 1;
	int i = 1;
	int pre = 1;
	while (i <=b)
	{
		pre = (pre * a)%9901;
		//printf("pre %d\n", pre);

		res = (res+pre)%9901;
		i++;
	}
	cout << res << endl;
}