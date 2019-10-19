//http://poj.org/problem?id=1942
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
unsigned compute(unsigned n, unsigned m)
{
	double cnm = 1.0;
	if (m < n - m)
		m = n - m;
	for (int i = 1; i <=n - m; i++)
	{
		cnm *= double(m + i) / double(i);
	}
	cnm += 0.5;
	return cnm;
}

int main()
{
	unsigned n, m;
	//init();
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		cout << compute(n+m,n) << endl;
	}
	return 0;
}