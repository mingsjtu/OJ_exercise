//http://poj.org/problem?id=2262
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
using namespace std;
//int p[41600];
bool isp(int x)
{
	int i, j, k;
	for (i = 2; i <= sqrt(x) + 1 && i < x; i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;

}
bool npp[500010];
void shai()
{
	int i, x, j = 0, k;
	bool flag = true;
	memset(npp, 0, sizeof(npp));
	for (i = 3; i <=707; i+=2)
	{
		if (npp[i])
			break;
		x = i;
		while (x < 500000)
		{
			x += 2*i;
			npp[x] = true;
			
		}
	}

}

int main()
{
	//int len = init();
	shai();
	int x, y, z;
	int i, j, k;
	bool flag;
	while (cin >> x)
	{
		flag = false;
		if (!x)
			break;
		for (i = 3; i <= x / 2; i+=2)
		{
			if (npp[i]==false && npp[x-i]==false)
			{
				flag = true;
				y = i;
				z = x - i;
				break;
			}
		}
		if (flag == false)
		{
			printf("Goldbach's conjecture is wrong.\n");
		}
		else
		{
			printf("%d = %d + %d\n", x, y, z);
		}
	}
}