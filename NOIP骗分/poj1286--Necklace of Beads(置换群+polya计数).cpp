//http://poj.org/problem?id=1286
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
int n;
const int maxn = 24;
int p[9] = { 2,3,5,7,11,13,17,19,23 };
int phi[maxn + 5];
void init()
{
	int i, j, k;
	for (i = 1; i <= maxn; i++)
	{
		phi[i] = i;
		for (j = 0; j < 9 && p[j] <=i; j++)
		{
			if (i%p[j] == 0)
				phi[i] = phi[i] * (p[j] - 1) / p[j];
		}
		//printf("phi[%d] is %d\n", i, phi[i]);
	}
}
int main()
{
	init();
	int i, j, k;
	__int64 res;
	while (cin >> n)
	{
		if (n == -1)
			return 0;
		res = 0;
		int n2 = sqrt(n);
		for (i = 1; i <= n; i++)
		{
			if(n%i==0)
				res += pow(3, i)*phi[n / i];
		}
		
		if (n % 2 == 0)
		{
			res += (n/2)*pow(3, n / 2)+(n/2)*pow(3,n/2+1);
		}
		else
		{
			res += n * pow(3, n / 2+1);
		}
		res /= (2*n);
		printf("%lld\n", res);
	}
}