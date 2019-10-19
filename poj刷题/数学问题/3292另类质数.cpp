//http://poj.org/problem?id=3292
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<math.h>
using namespace std;
bool p[200010];
bool isp(int x)
{
	int i, j, k;
	for (i = 5; i <= sqrt(x)&&i<x; i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}
int init()
{
	int i,j=0,x;
	memset(p, 0, sizeof(p));
	for (i = 5; i < 200005; i += 4)
	{
		if (p[i]==true)
		{
			continue;
		}
		x = i+i;
		while (x <= 200005)
		{
			if(x%4==1)
				p[x] = true;
			x += i;
		}
	}
	return j;
}
bool check(int x)
{
	int i, j, k;
	for (i = 5; i <= sqrt(x)+1; i+=4)
	{
		if (x%i == 0)
		{
			if (!p[i] && !p[x / i])
				return true;
			else
				return false;
		}
	}
	return false;
}
bool res[1000005];
int main()
{
	init();
	int i, j, k;

	/*for (i = 5; i <= 200001; i += 4)
	{
		if (!p[i])
			cout << i << endl;
	}*/
	memset(res, 0, sizeof(res));
	for (i = 5; i <= 1000001; i+=4)
	{
		res[i]=check(i);
		//if(res[i])
		//cout << i << endl;
	}
	//cout << 1 << endl;
	int x,result=0;
	while (cin >> x)
	{
		if (!x)
			break;
		result = 0;
		for (i = 5; i <= x; i += 4)
		{
			if (res[i])
			{
				result++;
			}
		}
		printf("%d %d\n", x, result);
	}
	
}