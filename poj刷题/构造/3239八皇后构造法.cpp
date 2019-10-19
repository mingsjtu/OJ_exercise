//https://blog.csdn.net/lyy289065406/article/details/6642789
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	int n,m;
	int i, j, k;
	while (cin >> n)
	{
		if (n == 0)
			break;
		if (n % 6 != 2 && n % 6 != 3)
		{
			if (n % 2 == 0)
			{
				for (i = 2; i <=n; i+=2)
				{
					cout << i << ' ';
				}
				for (i = 1; i <= n - 1; i += 2)
				{
					cout << i << ' ';
				}
				cout << endl;
			}
			if (n % 2 == 1)
			{
				for (i = 2; i <= n-1; i += 2)
				{
					cout << i << ' ';
				}
				for (i = 1; i <= n; i += 2)
				{
					cout << i << ' ';
				}
				cout << endl;
			}
		}
		if (n % 6 == 2)
		{
			m = n / 2;
			if (m % 2 == 0)
			{
				for (i = m; i <= n; i += 2)
					cout << i << ' ';
				for (i = 2; i <= m - 2; i += 2)
					cout << i << ' ';
				for (i = m + 3; i <= n - 1; i += 2)
				{
					cout << i << ' ';
				}
				for (i = 1; i <= m + 1; i+=2)
				{
					cout << i << ' ';
				}
				cout << endl;
			}
			if (m % 2 == 1)
			{
				for (i = m; i <= n-1; i += 2)
					cout << i << ' ';
				for (i = 1; i <= m-2; i += 2)
					cout << i << ' ';
				for (i = m + 3; i <= n; i += 2)
				{
					cout << i << ' ';
				}
				for (i = 2; i <= m + 1; i+=2)
				{
					cout << i << ' ';
				}
				cout << endl;
			}
			

		}
		if (n % 6 == 3)
		{
			m = (n-1)/ 2;
			if (m % 2 == 0)
			{
				for (i = m; i <= n-1; i += 2)
					cout << i << ' ';
				for (i = 2; i <= m - 2; i += 2)
					cout << i << ' ';
				for (i = m + 3; i <= n; i += 2)
				{
					cout << i << ' ';
				}
				for (i = 1; i <= m + 1; i+=2)
				{
					cout << i << ' ';
				}
				cout << endl;
			}
			if (m % 2 == 1)
			{
				for (i = m; i <= n; i += 2)
					cout << i << ' ';
				for (i = 1; i <= m - 2; i += 2)
					cout << i << ' ';
				for (i = m + 3; i <= n-1; i += 2)
				{
					cout << i << ' ';
				}
				for (i = 2; i <= m + 1; i+=2)
				{
					cout << i << ' ';
				}
				cout << endl;
			}


		}
	}
}