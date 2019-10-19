//http://poj.org/problem?id=2739
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
int p[10000];
int sp[100];
bool isp(int x)
{
	int i;
	for (i = 2; i <= sqrt(x) + 1&&i<x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}
int init()
{
	int i,j = 0;
	for (i = 2; i < 10000; i++)
	{
		if (isp(i))
		{
			p[j] = i;
			//printf("j %d pj%d\n", j, p[j]);
			j++;
		}
	}
	/*sp[0] = p[0];
	for (i = 1; i < 1000; i++)
	{
		sp[i] = sp[i - 1] + p[i];
		if (sp[i] > 10000)
			break;
		printf("%d ", sp[i]);
	}*/
	return j;
	//cout << i << endl;
}
int main()
{
	int len=init();
	int x,i,j,k,sum;
	while (cin >> x)
	{
		if (!x)
			break;
		int res = 0;
		for (i = 0; i < len; i++)
		{
			sum = 0;
			for (j = i; j < len; j++)
			{
				sum += p[j];
				if (sum > x)
					break;
				if (sum == x)
				{
					res++;
					break;
				}
			}
		}
		cout << res << endl;
	}
	
}