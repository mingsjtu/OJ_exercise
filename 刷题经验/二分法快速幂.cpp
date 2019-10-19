//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
long long mod(int a, int n, int k)//a^n%k
{
	long long res=1, i, j;
	while (n > 0)
	{
		if (n&1 == 1)
		{
			res *= a;
			res %= k;
		}
		a *= a;
		n = n >> 1;
	}
	return res;
}
int main()
{
	int a, n, k;
	int res;
	while (cin >> a >> n >> k)
	{
		res=mod(a, n, k);
		printf("%d \n", res);
	}
}