//http://poj.org/problem?id=3273
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[100005];
int n, m;

bool test(int x)
{
	int i, j, k;
	int cur = a[0];
	int res = 1;
	for (i = 1; i < n; i++)
	{
		if (cur + a[i] <= x)
		{
			cur += a[i];
		}
		else 
		{

			res++;
			if (res > m)
				return false;
			cur = a[i];

		}
	}
	//printf("x %d ; res %d\n", x, res);
	//if (res > m)
	//	return false;
	return true;
}
int main()
{
	int i, j, k;
	cin >> n >> m;
	int sum = 0;
	int maxn = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
		if (a[i] > maxn)
		{
			maxn = a[i];
		}
	}
	int high = sum;
	int low = maxn;
	int mid;
	while (high > low)
	{
		mid = (high + low) / 2;
		//printf("high %d,low %d,mid %d\n", high, low, mid);
		if (test(mid))
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	cout << low << endl;
}