//http://bailian.openjudge.cn/tm2017/A/
#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

int su[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97 };
bool isprime(int n)
{
	for (int i = 0; i < 26 && su[i] <= n; i++)
	{

		if (su[i] == n)
			return true;
	}
	return false;
}
int yin[100];
int xi[100];
int main()
{
	int n;
	
	while (cin >> n)
	{
		memset(yin, 0, sizeof(yin));
		memset(xi, 0, sizeof(xi));
		if (isprime(n))
		{
			cout << n << endl;
			continue;
		}
		int k = 0,x=1;
		int jie = 7;
		for (int i = 0; i<=3 ; i++)
		{
			
			if (n%su[i] == 0)
			{
				x = 0;
				yin[k] = su[i];
				while (n%su[i] == 0)
				{
					n /=su[i];
					x++;
				}
				xi[k] = x;
				k++;
			}
		}
		//cout << n << endl;
		if (isprime(n))
		{
			yin[k] = n;
			xi[k] = 1;
		}
		for (int i = 0; yin[i] != 0; i++)
		{
			//printf("yinshu %d , xishu %d\n", yin[i], xi[i]);
			if (i >= 1)
				cout << '*';
			if (xi[i] == 1)
				cout << yin[i];
			if (xi[i] > 1)
				cout <<yin[i]<< '^' << xi[i];
		}
		cout << endl;
	}
}