//https://blog.csdn.net/da_kao_la/article/details/82454805
#include<iostream>
#include<cstdio>
using namespace std;
int a, b;
bool check(int x)
{
	int i=0;
	int dig[10];
	while (x > 0)
	{
		dig[i++]=x % 10;
		x /= 10;
	}
	int n = i;
	for (i = 0; i < n/2+1; i++)
	{
		if (dig[i] != dig[n - 1 - i])
			return false;
	}
	return true;
}
int main()
{
	int i;
	cin >> a >> b;
	for (i = a; i <=b; i++)
	{
		if (check(i))
			cout << i << ' ';
	}
}