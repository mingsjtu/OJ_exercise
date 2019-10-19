//http://poj.org/problem?id=2602
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int digit1[1000005];
int digit2[1000005];
int len1, len2;
int N;
int len, res[1000005];
void sum()
{
	len = N;
	int i, j, k;
	int tmp, jinwei = 0;
	for (i = 0; i < N; i++)
	{
		tmp = digit1[i] + digit2[i] + jinwei;
		res[i]=tmp % 10;
		jinwei = tmp / 10;
	}
	if (jinwei > 0)
	{
		len++;
		res[len - 1] = jinwei;
	}
}
int main()
{
	cin >> N;
	int i, j, k;
	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &digit1[N - i - 1], &digit2[N - i - 1]);
	}
	sum();
	for (i = 0; i < len; i++)
	{
		putchar(char(res[len-1-i]+'0'));
	}
	cout << endl;
}