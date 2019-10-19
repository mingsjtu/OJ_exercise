//http://poj.org/problem?id=3252
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n1,n2;
int er1[50], er2[50];
int c[35][35];
void init()
{
	memset(c, 0, sizeof(c));
	int i, j, k;
	for (i = 0; i <=32; i++)
	{
		c[0][i] = 1;
		c[i][i] = 1;
	}
	for (i = 1; i <= 32; i++)
	{
		for (j = 1; j <i; j++)
		{
			c[j][i] = c[j - 1][i - 1] + c[j][i - 1];
		}
	}
}
int getall(int w)
{
	int i, j, k;
	if (w % 2 == 0)
	{
		int res = 0;
		int m = w / 2;
		for (i = m; i < 2*m; i++)
		{
			res += c[i][2 * m - 1];
		}
		return res;
	}
	if (w % 2 == 1)
	{
		int res = 0;
		int m = w / 2;
		for (i = m+1; i <=2 * m; i++)
		{
			res += c[i][2 * m];
		}
		return res;
	}
}
int compute(int x)
{
	//cout << x << endl;
	if (x < 2)
		return 0;
	int i = 0,res=0;
	int j, k;
	int ling = 0;
	while (x > 0)
	{
		er1[i]=x % 2;
		if (er1[i] == 0)
			ling++;
		i++;
		x /= 2;
	}
	int wei = i;
	//printf("wei %d ling %d\n", wei,ling);
	if (ling >= wei - ling)
		res++;
	for (i = 2; i <= wei - 1; i++)
	{
		res += getall(i);
		//printf("getall %d\n", getall(i));
	}
	i = wei - 2;
	ling = 0;
	for (i = wei - 2; i >=0; i--)
	{
		if (er1[i] == 0)
			ling++;
		else
		{
			for (k = i; 2 * (ling+1+ k) >=wei; k--)
			{
				//printf("k %d\n", k);
				res += c[k][i];
			}
		}
	}
	return res;
}
bool ok(int x)
{
	int i=0;
	int ling = 0;
	while (x > 0)
	{
		er1[i] = x % 2;
		if (er1[i] == 0)
			ling++;
		i++;
		x /= 2;
	}
	int wei = i;
	//printf("wei %d\n", wei);
	if (ling >= wei - ling)
		return true;
	else
		return false;
}
int sha(int n)
{
	int i; int res = 0;
	for (i = 2; i <=n; i++)
	{
		if (ok(i))
			res++;
	}
	return res;
}
int main()
{
	int i, j, k;
	init();
	//while (cin >> n1)
	//{
		//int res1 = compute(n1);
		//cout << res1 << endl;
		//int res2 = sha(n1);
		//printf("%d %d\n", res1, res2);
	//}
	cin >> n1 >> n2;
	int res1=compute(n1-1);
	int res2=compute(n2);
	cout << res2-res1 << endl;
}