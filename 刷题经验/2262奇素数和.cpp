//http://poj.org/problem?id=2262
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
bool p[1000010];
void init()
{
	int x,y;
	for (x = 3; x <= 1000010; x += 2)
	{
		if (p[x])
			continue;
		for (y = x << 1; y <= 1000010; y += x)
		{
			p[y] = 1;
		}
	}
}
int main()
{
	memset(p, 0, sizeof(p));
	init();
	int x,i,j;
	bool flag = false;
	while (cin >> x)
	{
		if (!x)
			return 0;
		for (i = 3; i <=x-i; i += 2)
		{
			if (p[i] == 0 && p[x - i] == 0)
			{
				printf("%d = %d + %d\n",x,i,x-i);
				flag = true;
				break;
			}

		}
		if(!flag)
		printf("Goldbach's conjecture is wrong.\n");
	}
}