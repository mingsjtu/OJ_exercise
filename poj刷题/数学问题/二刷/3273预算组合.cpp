//http://poj.org/problem?id=3273
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m;
int a[100005];
bool test(int x)
{
	int i, j, k;
	int cur = 0,use=1;
	for (i = 0; i < n; i++)
	{
		if (cur + a[i] <= x)
		{
			cur += a[i];
		}
		else
		{
			cur = a[i];
			use++;

		}
	}
	//printf("x %d use %d\n", x, use);
	if (use > m)
		return false;
	else
		return true;
}
int main()
{
	cin >> n >> m;
	int i, j, k;
	int maxn = 0;
	int s = 0;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		s+=a[i];
		if (a[i] > maxn)
			maxn = a[i];
	}
	int low, high;
	low = maxn;
	high = s;
	int mid;
	while (low < high)
	{
		//printf("low%d high%d\n", low, high);
		mid = (low + high) / 2;
		if (test(mid))
		{
			high = mid;
		}
		else
			low = mid+1;
	}
	mid = (high + low) / 2;
	cout << mid << endl;
}