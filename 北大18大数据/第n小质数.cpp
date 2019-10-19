#include<iostream>
#include<cstring>
#include<cstdio>
#include<math.h>
using namespace std;
bool isprime(int x)
{
	int i = 1,m=sqrt(x);
	for (i = 2; i <= m + 1; i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}
int main()
{
	int idx,i=1,cnt=2,res;
	cin >> idx;
	while (i < idx)
	{
		if (isprime(cnt))
		{
			res = cnt;
			i++;
		}
		cnt++;
	}
	cout << cnt - 1 << endl;
}