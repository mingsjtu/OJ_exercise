//https://blog.csdn.net/da_kao_la/article/details/82381617
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int n;
char str[1000];
int dig[10];//0-9需要有几个
int dig1[10];//0,9实际有几个
void cun(char*str)
{
	int l = strlen(str);
	int i;
	for (i = 0; i < l; i++)
		dig1[str[i] - '0']++;
}
void cun(int x)
{
	int chu, yu;
	while (x > 0)
	{
		yu = x % 10;
		x = x / 10;
		dig[yu]++;

	}
}
int search(int d[])
{
	if (d[1] == -1)
		return d[0];
	if (d[2] == -1)
	{
		int tmp = d[1] * 10 + d[0];
		if (tmp > n)
			return(d[0] * 10 + d[1]);
		
	}
}
int main()
{
	cin >> n;
	cin >> str;
	int i=0, j=0, k=0;
	memset(dig, 0, sizeof(dig));
	memset(dig1, 0, sizeof(dig1));
	cun(str);
	for (i = 1; i <= n; i++)
		cun(i);
	int d[3] = { -1,-1,-1 };//丢失的数字
	for (i = 0; i <= 9; i++)
	{
		if (dig[i] > dig1[i])
			d[j++] = i;
	}
	cout << d[0] << d[1] << d[2];
	search(d);
}
