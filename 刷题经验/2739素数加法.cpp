//http://poj.org/problem?id=2739
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<math.h>
using namespace std;
bool p[10005];
void init()
{
	int i, j, k,x;
	for (i = 2; i <= 10005; i++)
	{
		if (p[i] == true)
			continue;
		for (x = i + i; x <= 10005; x += i)
			p[x] = true;
	}
}
int main()
{
	int i, j, k;
	memset(p, 0, sizeof(p));
	init();
	int t;
	int sum;
	
	while (cin>>t)
	{
		if (t == 0)
			return 0;
		int res = 0;
		for (i = 2; i <=t; i++)
		{
			if (!p[i])
			{
				sum = 0;
				for (j = i; sum < t; j++)
				{
					if (!p[j])
						sum += j;
				}
				if (sum == t)
				{
					//cout << i << endl;
					res++;
				}
			}
		}
		cout <<res << endl;
	}
}