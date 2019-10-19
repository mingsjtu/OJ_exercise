//http://poj.org/problem?id=2154
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m,t;
int res = 0;
int quick(int x,int mod, int k)
{
	int res = 1;
	int a = x;
	while (k > 0)
	{
		//cout << k << endl;
		if (k & 1)
		{
			res *= a;
			res %= mod;
		}
		k = k >> 1;
		a = a * a;
		a %= mod;
	}
	return res;
}
int solve()
{
	int i, j, k;
	int nn = n;
	int mn = n % m;
	int sum = 0;
	for (i = 2; i< nn; i++)
	{
		if (nn%i == 0)
		{
			//cout << "yin " << i << endl;
			res += (n / i - 1)*quick(mn,m,i-1);
			sum += n / i - 1;
			res %= m;
			while (nn%i == 0)
				nn /= i;
		}
	}
	res += quick(mn, m, mn-1);
	res += n - sum - 1;
	res %= m;
	return res;
}
int main()
{
	int i, j, k;
	cin >> t;
	while (t--)
	{
		res = 0;
		scanf("%d %d", &n, &m);
		//n %= m;
		/*if (n == 1)
		{
			cout << 1 % m << endl;
			continue;
		}
		if (n == 2)
		{
			cout << 3 % m << endl;
			continue;
		}*/
		printf("%d\n",solve());
	}
}