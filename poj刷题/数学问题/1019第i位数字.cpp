//http://poj.org/problem?id=1019
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<math.h>
using namespace std;
int a[33000],b[33000],c[33000];
unsigned s[33000];
char biaoc[90]={ "11212312341234512345612345671234567812345678912345678910123456789101112345678910"};
void init()
{
	int i, j, k;
	a[0] = s[0] = 0;
	a[1] = s[1] = 1;
	b[0] = c[0] = 0;
	for (i = 1; i <=33000; i++)
	{
		a[i] = a[i-1] + int(log10(double(i))) + 1;

		s[i] = s[i-1] + a[i];
		if (i < 10)
			b[i] = 1;
		if (i >= 10 && i < 100)
			b[i] = 2;
		if (i >= 100 && i < 1000)
			b[i] = 3;
		if (i >= 1000 && i < 10000)
			b[i] = 4;
		if (i > 10000)
			b[i] = 5;
		c[i] = c[i - 1] + b[i];
	}
}
int compute(int x)
{

	//printf("x %d\n", x);
	int i=1, j=1, k,orii;
	/*for (i = 0; i < 100; i++)
	{
		printf("a[i] %d,s[i] %d\n", a[i], s[i]);
	}*/
	i = 1, j = 1;
	for (i = 1; i < 33000; i++)
	{
		if (a[i] > x)
		{
			j = i;
			break;

		}
	}
	j--;
	//printf("j%d ai%d\n", i,a[i]);
	int wei = a[i] - x-int(log10(double(i)));
	//printf("ai%d x %d log %d\n", a[i], x, int(log10(double(i))));
	//printf("wei %d\n", wei);
	for (i = 0; i < wei - 1; i++)
	{
		j /= 10;
	}
	return j % 10;
}
int main()
{
	int i, j, k;
	int t,x,n;
	init();
	a[0] = s[0] = 0;
	a[1] = s[1] = 1;
	/*for (i = 0; i < 100; i++)
	{
		printf("a[i] %d,s[i] %d\n", a[i], s[i]);
	}
	cout << s[33000] << endl;*/
	cin >> t;
	while (t--)
	{
		cin >> x;
		for (i = 0; i < 10000; i++)
		{
			if (s[i] >=x)
			{
				n = i;
				break;
			}
		}
		
		//printf("n %d,sn-1 %d\n", n, s[n-1]);
		int res=compute(x - s[n - 1]);
		cout << res << endl;
		//cout << biaoc[x-1] << endl;
	}
	
}