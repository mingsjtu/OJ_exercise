//http://poj.org/problem?id=2635
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
using namespace std;
char d[105];
int d1[35];
int a;
bool p[1000005];
bool isp(int x)
{
	for (int i; i <= sqrt(x) + 1 && i < x; i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}
bool yu(int x,int l)
{
	//printf("yu%d\n", x);
	int res = 0,i,j,k;
	for (i = l-1; i>=0; i--)
	{
		res =(res*1000+d1[i])% x;
		//printf("res %d\n", res);
	}
	return res;

}

void init()
{
	memset(p, 0, sizeof(p));
	int i, j, k,x;
	for (i = 2; i <= 1000; i++)
	{
		if (p[i] == true)
			continue;
		x = i;
		while (1)
		{
			x += i;
			if (x > 1000000)
				break;
			p[x] = true;
		}
	}
}

int main()
{
	init();
	int i, j, k,x, len;
	bool flag = false;
	while (scanf("%s", d))
	{
		memset(d1, 0, sizeof(d1));
		cin >> a;
		flag = false;
		len = strlen(d);
		//printf("len %d\n", len);
		if (d[0] == '0'&&a==0)
		{
			break;
		}
		j = 0;
		for (j=0;3*j+2<len;j++)
		{
			d1[j] = d[len - 3 * j-1]-'0' + (d[len - 3 * j - 2]-'0') * 10 + (d[len - 3 * j - 3]-'0') * 100;
			//printf("d %d\n", d1[j]);
		}
		int i = len - 3 * j -1;
		while (i >= 0)
		{
			d1[j] = d1[j] * 10 + d[i]-'0';
			i--;
		}
		int len1;
		if (d1[j] == 0)
		{
			len1 = j;
		}
		else
		{
			len1 = j + 1;
		}
		//printf("d %d\n", d1[j]);

		for (i = 2; i < a; i++)
		{
			if (p[i])
				continue;
			if (yu(i,len1)==0)
			{
				//printf("find %d\n", i);
				flag = true;
				break;
			}
		}
		if (flag)
		{
			printf("BAD %d\n", i);
		}
		else
		{
			printf("GOOD\n");
		}
	}
}